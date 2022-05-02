/* 
 * File:   main.c
 * Author: Giovanni
 * This routine relies on PIC12F675
 * It activates a timer1 and deals with stepper driver for the X27.168 stepper 
 * motor.
 * Created on 31 January 2022, 21.48
 * 
 * Heavily based on:
 *  SwitecX12 Arduino Library
 *  Guy Carpenter, Clearwater Software - 2017
 *
 *  Licensed under the BSD2 license, see license.txt for details.
 *
 *  All text above must be included in any redistribution.
 */

/*
 * This program uses a PIC12F675 8-bit microprocessor to command 
 * an AX1201728SG stepper driver board, which ultimately is 
 * responsible of the movement of an x27.168 stepper motor.
 * The code is intended to read 2 GPIO inputs (GP4, GP5), which
 * are connected to the poweroff bit and the speedbrake open bit
 * of Falcon 4.35 BMS / DCS World Viper. Once sensed the condition
 * it moves accordingly the stepper motor, whose needle carries a 
 * wheel which indicates the speedbrake position.
 * Three different positions are possible: 
 *   + Not powered
 *   + Closed
 *   + Open
 * 
 * To each mode corresponds a specific position of the wheel -->
 * hence of the stepper.
 * The code implements (directly) the great SwitecX12 library
 * developed by Guy Carpenter. The library is asynchronous, 
 * and reduces to a minimum the CPU effort, so to have a fast 
 * cycle.
 * The library implements an acceleration curve, and takes advantage
 * of the microstepping feature of the stepper driver / stepper.
 * In order to provide a time measurement, the 16-bit Timer1 of
 * the PIC12F675 is used. 
 * 1:1 prescaler and 4 MHz internal clock is used, hence the 
 * Timer1 will add each ~1us. 
 * The useful range of stepper Timer is somewhat in the ~10us ~100us
 * so barely hitting the performance limit of the board.
 * Should it be possible, running a more performing microchip is 
 * desirable.
 * 
 
 Pinout of the PIC12F675 
          +=======\/=======+
        __|                |__
VDD    | 1                  8 |   VSS
          |                |
        __|                |__
GP5 I1 | 2                  7 | GP0 F(X)
          |    PIC12F675   |     
        __|                |__
GP4 I2 | 3                  6 | GP1 DIR
          |                |   
        __|                |__
       | 4                  5 |  GP2 RST
          +================+
 * 
 * GP5 = PowerBit
 * GP4 = Speedbrake open
 * 
 * In the AXG
 * Pin 26 RESET
 * Pin 27 A_DIR
 * Pin 28 F(X)
 */

// ************************************************
// Configuration bits

#pragma config FOSC = INTRCIO // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF // MCLR
#pragma config BOREN = OFF // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF // Data Code Protection bit (Data memory code protection is disabled)



#include <stdio.h>
#include "SwitecX12_C.h"
#include <xc.h>
#include "timers.h"
#include "ReadTimer1.h"

// Define CPU Frequency
#define _XTAL_FREQ 4000000



unsigned int currentStep = 0; // step we are currently at
unsigned int targetStep = 0; // target we are moving to
unsigned int steps = 3780; // total steps available (315 * 12)
unsigned int microDelay = 0; // microsecs until next state
unsigned int (*accelTable)[2]; // accel table can be modified.
unsigned int maxVel = 800; // fastest vel allowed
unsigned int vel = 0; // steps travelled under acceleration
int dir = 0; // direction -1,0,1
__bit stopped; // true if stopped



// This table defines the acceleration curve.
// 1st value is the speed step, 2nd value is delay in microseconds
// 1st value in each row must be > 1st value in subsequent row
// 1st value in last row should be == maxVel, must be <= maxVel
static unsigned int defaultAccelTable[][2] = {
    { 20, 800},
    { 50, 400},
    { 100, 200},
    { 150, 150},
    { 300, 90}
};

const int stepPulseMicrosec = 1;
const int resetStepMicrosec = 300;

#define DEFAULT_ACCEL_TABLE_SIZE (sizeof(defaultAccelTable)/sizeof(*defaultAccelTable))


//
// InitTimer1(void);
// ============================================================================
void InitTimer1(void) {
    // The InitTimer1 function takes care of setting up the Timer1 configuration
    // bits of the PIC12F675. It also disables all interrupts, as no ISR 
    // function is implemented.
    T1CON = 0x00; // Shuts the timer off
    NOP();        // Takes a breath to avoid RWM issues
    
    TMR1H = 0; // Clear timer1 registers
    TMR1L = 0; // before enabling timer1

    // Timer1 is 16bit timer
    T1CON = 0x01; // Prescalar 1:1, Timer1 On
    //T1CONbits.TMR1ON = 1; // Turns on the Timer1

    T1IF = 0; // Clear interrupt bit
    T1IE = 0; // Enable Timer1 interrupt
    PEIE = 0; // Enable peripheral interrupts
    GIE = 0; // Enable global interrupts
}



//
// SwitecX12_init
// ============================================================================
void SwitecX12_init(void) {

    dir = 0;          // Initializes the direction
    vel = 0;          // velocity
    stopped = 1;      // stopped boolean
    currentStep = 0;  // stepper: current step
    targetStep = 0;   // stepper: target step

    accelTable = defaultAccelTable; // and acceleration table
    maxVel = defaultAccelTable[DEFAULT_ACCEL_TABLE_SIZE - 1][0]; // last value in table.
}


//
// Main function
// ============================================================================
void main() {
    
    char GP_input = 0;
    
    ANSEL = 0x00;           // Set ports as digital I/O, not analog input
    ADCON0 = 0x00;          // Shut off the A/D Converter
    CMCON = 0x07;           // Shut off the Comparator
    VRCON = 0x00;           // Shut off the Voltage Reference
    
    OPTION_REGbits.nGPPU = 0; // Sets OPTION_REG GPPU to 0 so to enable Weak pull-up
    WPU = 0b00110000;       // Weak pull-up enabled for GP4 and GP5
    
    GPIO = 0x00;            // Make all pins 0
    TRISIO = 0b00110000;    // GP4,5 input, rest all output
    GPIE = 0;               // Pin interrupt mode disabled

    
    SwitecX12_init();       // Initialize the library
    __delay_ms(500);        // Consolidates the power supply status prior to 
    GP2 = 1;                // Power up stepper driver board, RESET PIN HIGH
                            // GP4 as digital I/O
                            // GP5 is by default digital I/O
    __delay_ms(100);
    //InitTimer1;          // Initialize the timer
    zero();
    __delay_ms(500);

    while (1) {
        // Infinite loop
        
        GP_input = ( (GPIO >> 4) & (0b0011) );
        
        switch(GP_input)
        {
            case 0b0010: 
            {
                setPosition(2080); // Closed position angle
                break;
            }
            case 0b0011:
            {
                setPosition(1040); // Open position angle
                break;
            }
            default:
            {
                setPosition(1600); // Powered off bit
                break;
            }
        }

        update(); // Update position

    }
}


void step(int dir) {

    //digitalWrite(pinDir, dir > 0 ? LOW : HIGH);
    if (dir > 0) {
        //pinDir
        GP1 = 0;
        currentStep++;
    } else {
        GP1 = 1;
        currentStep--;
    }

    GP0 = 1;
    __delay_us(stepPulseMicrosec);
    GP0 = 0;
   
}

void stepTo(unsigned int position) {
    unsigned int count;
    //int dir;
    if (position > currentStep) {
        dir = 1;
        count = position - currentStep;
    } else {
        dir = -1;
        count = currentStep - position;
    }
    for (int i = 0; i < count; i++) {
        step(dir);
        __delay_us(resetStepMicrosec);

    }
}

void zero() {
    // Slow routine to zero the stepper position at init
    currentStep = steps - 1;
    stepTo(0);
    targetStep = 0;
    vel = 0;
    dir = 0;
}

void advance() {
    // detect stopped state
    if (currentStep == targetStep && vel == 0) {
        stopped = 1;
        dir = 0;
        InitTimer1(); //time0 = micros();
        
        return;
    }

    // if stopped, determine direction
    if (vel == 0) {
        dir = currentStep < targetStep ? 1 : -1;
        // do not set to 0 or it could go negative in case 2 below
        vel = 1;
    }

    step(dir);

    // determine delta, number of steps in current direction to target.
    // may be negative if we are headed away from target
    int delta = dir > 0 ? (signed int)targetStep - (signed int)currentStep : (signed int)currentStep - (signed int)targetStep;

    if (delta > 0) {
        // case 1 : moving towards target (maybe under accel or decel)
        if (delta < vel) {
            // time to decelerate
            vel = (unsigned int)delta;
        } else if (vel < maxVel) {
            // accelerating
            vel++;
        } else {
            // at full speed - stay there
        }
    } else {
        // case 2 : at or moving away from target (slow down!)
        vel--;
    }

    // vel now defines delay
    unsigned char i = 0;
    // this is why vel must not be greater than the last vel in the table.
    while (accelTable[i][0] < vel) {
        i++;
    }
    microDelay = accelTable[i][1];
    InitTimer1(); //time0 = micros();
}

void setPosition(unsigned int pos) {
    // pos is unsigned so don't need to check for <0
    if (pos >= steps) pos = steps - 1;
    targetStep = pos;
    if (stopped) {
        // reset the timer to avoid possible time overflow giving spurious deltas
        stopped = 0; // false
        InitTimer1(); //time0 = micros();
        microDelay = 0;
    }
}

void update() {
    if (!stopped) {
        //unsigned long delta = micros() - time0;
        //if ( ( (TMR1H << 8) | (TMR1L) ) >= microDelay) {
        if (ReadTimer1() >= microDelay) {
            advance();
        }
    }
}
