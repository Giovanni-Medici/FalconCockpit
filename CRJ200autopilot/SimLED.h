///////////////////////////////////////////////////////////////////////////////
//
// SimLED v1.00
//
// Copyright 2012 Jack Deeth
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// I would appreciate, but not insist, on attribution if this code is
// incorporated into other projects.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef SIMLED_H
#define SIMLED_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

enum SimLedType {
  SLUndefined,
  SLMaster,
  SLIntAnnc,
  SLFloatAnnc
};

class SimLED {
public:
  // Constructors
  // if enableTest is True, the LED will be lit by the lightTest function.
  // if enableFlash is True, the flash filter will apply to this SimLED.
  
  // Create Master SimLED
  // It will be lit by annunciator LEDs created AFTER it, until another
  // Master SimLED is defined or the last SimLED is declared.
  //
  // The compiler will regard SimLED(pinNo, false) as SimLED(int, int)
  // and complain of ambiguity between Master and Int Annc constructors. 
  // In this case, cast to boolean: 
  // SimLED(pinNo, (bool) false);
  //
  // Annunciators created before the first Master SimLED
  SimLED(const int    &masterLedPin,
         const bool   &enableTest = true,
         const bool   &enableFlash = true);
  
  // Create Annunciator SimLEDs
  // lowLimit and highLimit define the range where the SimLED is ACTIVE.
  //
  // example: SimLED takeoffTrim(10, &elevTrimDR, 0.10, 0.15);
  // active when trim is between 0.10 and 0.15
  //
  // If invertLimits is True, this is reversed, and they define the range where
  // the annunciator is INACTIVE.
  //
  // example: SimLED balanceWarn(10, &cOfGPosition, 0.20, -0.10);
  // balanceWarn will be inactive when the dataref is less than 0.20 and
  // greater than -0.10 inclusive. Therefore it will be Active outside of that
  // range.
  //
  // Integer annunciator limit values are inclusive.
  //
  SimLED(const int    &ledPin,
         FlightSimInteger *dr,
         const int    &lowLimit     = 1,
         const int    &highLimit    = 32000,
         const bool   &invertLimits = false,
         const bool   &enableTest   = true,
         const bool   &enableFlash  = false);

  SimLED(const int    &ledPin,
         FlightSimFloat *dr,
         const float  &lowLimit,
         const float  &highLimit,
         const bool   &invertLimits = false,
         const bool   &enableTest   = true,
         const bool   &enableFlash  = false);
  
  // Set up all SimLED objects. This simply calls setup_ on each instance of
  // SimLED, setting the pinMode to OUTPUT.
  //
  // Call this in the Arduino setup() function.
  static void setup(void);
  
  // Update all SimLED objects. This takes input from the datarefs, applies
  // annunciator system logic to determine which are Active, and then applies
  // other filters to determine which are Lit. If updateOutput is True, then
  // each LED pin is set High or Low as well.
  //
  // Call this in the Arduino loop() function.
  static void update (bool updateOutput = true);
  
  // A SimLED isActive when the state of the datarefs and annunciators would
  // cause it to light. isLit is isActive with filters applied, to override
  // the LED state for the following functions:
  // - Light test
  // - Light flasher
  // - Simulator state (LEDs extinguish when sim is inactive)
  //
  // For example, a flashing master warning SimLED is continually Active,
  // but alternately Lit and not Lit. A SimLED illuminated by a test is
  // Lit but not Active.
  //
  bool isActive(void) { return active_; }
  bool isLit(void)    { return lit_ ; }
  
  // Acknowledges currently lit Annunciator SimLEDs belonging to this Master
  // SimLED and extinguishes the Master SimLED.
  //
  // masterReset has no effect when called on SimLEDs that aren't Master SimLEDs.
  //
  void masterReset(void);
  
  // Operate the flashing sequence for flash-enabled SimLEDs.
  // When called with True, all flash-enabled SimLEDs will light when Active.
  // When called with False, they will be extinguished.
  static void flash (bool litNow)       { flashNow_ = litNow; }
  
  // Sets whether this SimLED will react to the flash filter
  void enableFlash (bool allowFlash)    { allowFlash_ = allowFlash; }
  
  // While called with 'true', will override enabled SimLEDs to light up.
  static void lightTest(bool lightAll)  {testAll_ = lightAll;}
  
  // Enables or disables this SimLED's participation in lightTests
  void enableTest (bool allowTest)      {allowTest_ = allowTest;}
  
private:
  // Hardware pin of output LED
  int pin_;
  
  // Defines this as Master, Int Annc., or Float Annc.
  SimLedType type_;
  
  // Annc is active when dataref is between Low and High limits, unless
  // it is Inverse. Inverse anncs are active when dataref is NOT between
  // Low and High limits. Range is inclusive.
  bool inverse_; 
  
  FlightSimInteger * drInt_;
  int lowLimitI_;     
  int highLimitI_;    
  
  FlightSimFloat * drFloat_;
  float lowLimitF_;
  float highLimitF_;
  
  // Annc input data is in range to activate this annc.
  bool active_; 
  
  // Per annc system simulation, this annc LED should be lit.
  bool lit_;    
  
  // This Active_ annc has been Ack_nowledged by Master Reset key
  bool ack_;    
  
  void addToLinkedList(void);
  void setup_ (void) {pinMode(pin_, OUTPUT);}
  void update_(bool updateOutput = true);
  
  bool allowTest_;
  bool allowFlash_;
  
  static bool flashNow_;
  static bool testAll_;
  
  // Number of SimLEDs created
  static int count_;
  // Pointer to first SimLED in linked list
  static SimLED* first_;
  // Pointer to next SimLED in linked list. == 0 if this is last element
  SimLED* next_;
};

#endif // SIMLED_H

