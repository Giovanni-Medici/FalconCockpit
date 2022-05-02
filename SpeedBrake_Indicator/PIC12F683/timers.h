#ifndef __TIMERS_H
 #define __TIMERS_H
 /******************************************************************************
  // *                  TIMERS PERIPHERAL LIBRARY HEADER FILE
  ******************************************************************************
  * FileName:                timers.h
  * Dependencies:        See include below
  * Processor:               PIC18
  * Compiler:                MCC18
  * Company:                 Microchip Technology, Inc.
  ...
  *****************************************************************************/
 //#include "pconfig.h"
 
 /* PIC18 timers peripheral library. */
 
 /* used to hold 16-bit timer value */
 union Timers
 {
   unsigned int lt;
   char bt[2];
 };
#endif