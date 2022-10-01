/*
 * File:   newmain.c
 * Author: Giovanni
 * This simple program, written for the PIC16F615, reads a potentiometer 
 * through ADC, every 40 runs and keeps only the first 8 bits of the info.
 * With the given reading it outputs a software PWM. For Duty Cycle smaller than
 * 7 percent, it shuts off the output (PWM).
 * ADC on GP0
 * Output on GP5
 * Created on 16 gennaio 2022, 10.42
 */

#pragma config FOSC = INTOSCIO // Oscillator Selection bits (INTOSCIO oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF // Code Protection bit (Program memory code protection is disabled)
#pragma config IOSCFS = 8MHZ // Internal Oscillator Frequency Select (4 MHz)
#pragma config BOREN = OFF // Brown-out Reset Selection bits (BOR disabled)


#include <xc.h>

#define _XTAL_FREQ 8000000

void setDuty(unsigned int duty) {
    // sets the right shifted part of duty into CCPR1L
    CCPR1L = duty >> 2;
    // sets CCP1CON as bitwise AND of 0b11001111
    CCP1CON &= 0xCF;
    // sets CCP1CON as bitwise OR of 0b00110000 & left shifted duty
    CCP1CON |= (0x30 & (duty << 4));
}

void main(void) {
    /* Variables */
    unsigned int result;
    unsigned char ledOFF;


    /* CONFIGURE GPIO */
    ANSEL = 0b0000001; // AN0 is inputs
    TRISA = 0; // disable pin


    ADCON0bits.CHS = 0b00; // Use AN0 as the analog source
    ADCON0bits.VCFG = 0; // Use AN0 as input, VDD and VSS as ref
    ADCON0bits.ADFM = 0; // Only 8-bit result (left justified)
    ADCON0bits.ADON = 1; // Turn on the module

    /* CONFIGURE PWM on GPIO5 */
    // Pin configuration
    GP5 = 0; // GP5 put low
    TRISIO0 = 1; // GP0 ADC
    TRISIO5 = 0; // GP5 as output
    P1ASEL = 1; // GP5 as AF > P1A (PWM)

    // Configure PWM
    T2CONbits.T2CKPS = 0b00; // set prescaler as 1:1 (default)
    CCP1CONbits.P1M = 0; // single / P1A modulated
    CCP1CONbits.CCP1M = 0b1100; // set PWM mode 

    // Timer configuration
    TMR2 = 0; // reset TMR2 count
    TMR2ON = 1; // enable TMR2, start PWM

    // Variable initialization
    ledOFF = 0;

    // Loop forever
    while (1) {

        // Make an ADC reading  
        ADCON0bits.GO_nDONE = 1;

        // If the ADC has finished
        while (ADCON0bits.GO_nDONE == 1) {
        }

        result = ADRESH;

        if (result >= 9) //9/256 (approx 3.5 percent off)
        {
            if (ledOFF == 1) {
                TMR2 = 0; // reset TMR2 count
                TMR2ON = 1; // enable TMR2, start PWM
                NOP();
                __delay_ms(10);
                ledOFF = 0;
            }
            // sets the duty cycle
            setDuty(result);
            __delay_ms(10);

        }
        else {
            // Completely switches off the PWM (to avoid spurious spikes of the 
            // order of 1/1024, but still quite annoying

            if (ledOFF == 0) {
                // ledOFF flag is meant to only play with Timer2 only once/when
                // passing through the threshold, not every cycle.
                ledOFF = 1;
                TMR2 = 0; // reset TMR2 count
                TMR2ON = 0; // disable TMR2, start PWM
                __delay_ms(20);
            }
            // Turn LED off
            GP5 = 0; // set GP5 low
            __delay_ms(10);
        }

    }

}