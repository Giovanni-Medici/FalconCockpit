#ifndef __READTIMER1_H
 #define __READTIMER1_H

#include "timers.h"
 
 /********************************************************************
 *    Function Name:  ReadTimer1                                     *
 *    Return Value:   char: Timer1 16-bit value                      *
 *    Parameters:     void                                           *
 *    Description:    This routine reads the 16-bit value from       *
 *                    Timer1.                                        *
 ********************************************************************/
 //#if defined (TMR_V1) || defined (TMR_V2) || defined (TMR_V3) || defined (TMR_V4) || defined (TMR_V5) || defined (TMR_V6) || defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)  || defined (TMR_V7_3)

 unsigned int ReadTimer1(void)
 {
   union Timers timer;
 
   timer.bt[0] = TMR1L;    // Read Lower byte
   timer.bt[1] = TMR1H;    // Read upper byte
 
   return (timer.lt);      // Return the 16-bit value
 }
 #endif