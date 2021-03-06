#include "SimLED.h"

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

SimLED::SimLED(const int  &masterLedPin,
               const bool &enableTest,
               const bool &enableFlash) {
  pin_        = masterLedPin;
  type_       = SLMaster;
  allowTest_  = enableTest;
  allowFlash_ = enableFlash;
  addToLinkedList();
}

SimLED::SimLED(const int  &ledPin,
               FlightSimInteger *dr,
               const int  &lowLimit,
               const int  &highLimit,
               const bool &invertLimits,
               const bool &enableTest,
               const bool &enableFlash) {
  pin_          = ledPin;
  type_         = SLIntAnnc;
  drInt_        = dr;
  lowLimitI_    = lowLimit;
  highLimitI_   = highLimit;
  inverse_      = invertLimits;
  allowTest_    = enableTest;
  allowFlash_   = enableFlash;
  addToLinkedList();
}

SimLED::SimLED(const int    &ledPin,
               FlightSimFloat *dr,
               const float  &lowLimit,
               const float  &highLimit,
               const bool   &invertLimits,
               const bool   &enableTest,
               const bool   &enableFlash) {
  pin_          = ledPin;
  type_         = SLFloatAnnc;
  drFloat_      = dr;
  lowLimitF_    = lowLimit;
  highLimitF_   = highLimit;
  inverse_      = invertLimits;
  allowTest_    = enableTest;
  allowFlash_   = enableFlash;
  addToLinkedList();
}

void SimLED::addToLinkedList() {
  next_ = 0;
  
  if (count_++ == 0) {
    first_ = this;
  } else {
    // Go through linked list and make last existing element point to us
    SimLED *a = first_;
    while (a->next_)
      a = a->next_;
    a->next_ = this;
  }
}

// Run setup_() function on each instance of SimLED
void SimLED::setup() {
  if (count_ > 0) {
    SimLED* buf = first_;
    while (buf != 0) {
      buf->setup_();
      buf = buf->next_;
    }
  }
}

// Run update()_ on each instance of SimLED
// if updateOutput, set LED pins according to lit_ status
void SimLED::update( bool updateOutput) {
  if (count_ > 0) {
    SimLED* buf = first_;
    while (buf != 0) {
      buf->update_(updateOutput);
      buf = buf->next_;
    }
  }
}

// Determine whether this SimLED should be lit
void SimLED::update_(bool updateOutput) {
  switch (type_) {
    case SLMaster: {
        // If we set active_ to false here, Master SimLEDs will extinguish
        // when all their annunciators are out. Without this line, they stay
        // lit until the Reset button is pressed.
        
        // active_ = false;
        
        SimLED *buf = next_;
        while ( (buf->type_ != SLMaster) && (buf != 0) ) {
          // Step through anncs until we reach the end, or the next Master
          // Activate this Master if any unAck'd Active anncs are found
          active_ += (buf->active_ && !buf->ack_);
          // reset acknowledgements for inactive anncs
          if (!buf->active_)
            buf->ack_ = false;
          buf = buf->next_;
        }
      }
      break;
      // for regular anncs, we are active if our dataref is within the limits.
    case SLIntAnnc:
      active_ = (lowLimitI_ <= *drInt_ && *drInt_ <= highLimitI_);
      if(inverse_ == true)
        active_ = !active_;
      break;
    case SLFloatAnnc:
      active_ = (lowLimitF_ <= *drFloat_&& *drFloat_ <= highLimitF_);
      if(inverse_ == true)
        active_ = !active_;
      break;
    default:
      return;
  }
  
  lit_ = active_;
  
  // apply lit_ filters:
  
  // we are lit if bulb-test is active
  if( (allowTest_ == true) && (testAll_ == true) )
    lit_ = true;
  
  // we are not lit if we're a flashing light and the flash timers says not to
  if ( (allowFlash_ == true) && (flashNow_ == false) )
    lit_ = false;
  
  // we are not lit if the sim isn't running
  if(FlightSim.isEnabled() == false) {
    lit_ = false;
  }
  
  // unless ordered otherwise, light or extinguish LED based on our lighting state
  if (updateOutput)
    digitalWrite(pin_, lit_);
}

void SimLED::masterReset() {
  // do nothing if this isn't a Master
  if(type_ != SLMaster)
    return;
  
  // Acknowledge all our Active anncs, which are the subsequent anncs in
  // the list, until we reach another Master or the end.
  SimLED *buf = next_;
  while((buf->type_ != SLMaster) && (buf != 0)) {
    buf->ack_ = buf->isActive();
    buf = buf->next_;
  }
  // Resetting the Master extinguishes it.
  active_ = false;
}

// Initialise static data members
int SimLED::count_      = 0;
SimLED* SimLED::first_  = 0;
bool SimLED::testAll_   = false;
bool SimLED::flashNow_  = true;
// flashNow defaults True. If user does not implement a flash timer, SimLEDs
// specified as flashing will instead stay steadily lit.

