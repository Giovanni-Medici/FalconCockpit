/*
 * File:   newmain1.c
 * Author: Giovanni
 *
 * Created on 16 gennaio 2022, 12.50
 */
// BEGIN CONFIG
#pragma config FOSC = INTOSCIO // Oscillator Selection bits (INTOSCIO oscillator: I/O function on GP4/OSC2/CLKOUT,I/O function o
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = ON // Code Protection bit (Program memory code protection is disabled)
#pragma config IOSCFS = 4MHZ // Internal Oscillator Frequency Select (8 MHz)
#pragma config BOREN = ON // Brown-out Reset Selection bits (BOR disabled)
// END CONFIG
#include "xc.h"    //should be AFTER the config settings

#define _XTAL_FREQ 4000000
#define input_pin GP3
#define output_pin GP5

void __interrupt () my_isr_routine (void) {
  PIR1bits.TMR2IF = 0; // clear the interrupt request
  if (input_pin != 0)
    output_pin = 0;
  else
    output_pin = 1;
}

void main(void) 
{
    /* CONFIGURE GPIO */
    ANSEL = 0; // disable analog
    /* CONFIGURE PWM on GPIO5 */
    // Pin configuration
    TRISIO5 = 0; // GP5 as output
    TRISIO3 = 1; //GP3 as input
    WPU = 0;
    IOC = 0b00001000;
    // Configure PWM
    T2CON = 0b00000100; // 0000 -> Postscaler = 1:1, T2 is on, 00 -> Prescaler=1:1
    OPTION_REG = 0b10000000;
    PR2 = 32; // roll over every 33 counts
    PIE1bits.TMR2IE = 1; // enable TMR2 interrupts
    INTCONbits.PEIE = 1; // enable peripheral interrupts
    INTCONbits.GIE = 1; // enable global interrupts

    while (1)    //loop forever
    {
        //non interrupt code will go here
    }
}