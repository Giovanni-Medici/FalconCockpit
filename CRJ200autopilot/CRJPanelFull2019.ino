// 
// CRJPanelFull
//
// The program is used to interface a Teensy 2.0 ++ with a custom designed
// Hardware that has the same functions as the CRJ-200 Autopilot panel.
// It is meant to work with the gorgeous CRJ-200 developed by Javier Rollon
// http://www.jrollon.com
// To use this script with x-plane, you shall install Teensyduino and the
// USB Flight Sim Plugin
// http://www.pjrc.com/teensy/td_flightsim.html
//
// Adds the great SimLED library, developed by Jack Deeth
// Adds two libraries to control Push Buttons and Encoders
//
// Copyright 2019 Giovanni Medici
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


#include "SimLED.h"

#include <Bounce.h>
#include <Encoder.h>
//#include <DogLcd.h>


// #########################################################
// LED DATAREF
// Two statements to define a LED: 
// FlightSimInteger intName; defines an integer linked to a x-plane parameter
// SiMLED intNameCtr (PIN_NUM, &intName, minDetect,maxDetect);
// ~ intName    : is the name of the integer connected to x-plane parameter;
// ~ intNameCtr : is a function that calls the SimLED library
// ~ PIN_NUM    : is the PIN number on Teensy
// ~ minDetect  : is the minimum change value which calls the SimLED function;
// ~ maxDetect  : is the maximum change value which calls the SimLED function;


FlightSimInteger apLight;
SimLED apLightCtr (PIN_C6, &apLight, 1,1);
FlightSimInteger xfrLight;
SimLED xfrLightCtr (PIN_F0, &xfrLight, 1,1);
FlightSimInteger speedLight;
SimLED speedLightCtr (PIN_F2, &speedLight, 1,8);
FlightSimInteger apprLight;
SimLED apprLightCtr (PIN_F4, &apprLight, 1,1);
FlightSimInteger hdgLight;
SimLED hdgLightCtr (PIN_F6, &hdgLight, 1,1);

FlightSimInteger navLight;
SimLED navLightCtr (PIN_A0, &navLight, 1,1);
FlightSimInteger altLight;
SimLED altLightCtr (PIN_A2, &altLight, 1,1);
FlightSimInteger vsLight;
SimLED vsLightCtr (PIN_A7, &vsLight, 1,16);



FlightSimInteger fdLight;
SimLED fdLightCtr (PIN_B5, &fdLight, 1,1);
FlightSimInteger turbLight;
SimLED turbLightCtr (PIN_B2, &turbLight, 1,1);
FlightSimInteger bcLight;
SimLED bcLightCtr (PIN_B7, &bcLight, 1,1);
FlightSimInteger bankLight;
SimLED bankLightCtr (PIN_C0, &bankLight, 1,1);
//FlightSimInteger fd2Light;
SimLED fd2LightCtr (PIN_C4, &fdLight, 1,1);





// #########################################################
// X-PLANE COMMAND AND ENCODERS DATAREF
// Hardware objects, for accessing the buttons, and rotary encoder


Bounce apEngBtn  = Bounce(PIN_C7, 10);  // Pushbutton on pin C6, 10ms debounce
Bounce xfrBtn    = Bounce(PIN_F1, 10);  
Bounce speedBtn  = Bounce(PIN_F3, 10); 
Bounce apprBtn   = Bounce(PIN_F5, 10);  
Bounce hdgBtn    = Bounce(PIN_F7, 10);  
Bounce navBtn    = Bounce(PIN_A1, 10);  
Bounce altBtn    = Bounce(PIN_A3, 10);  
Bounce vsBtn     = Bounce(PIN_A6, 10);

Bounce fdBtn     = Bounce(PIN_B6, 10);
Bounce apDiscBtn = Bounce(PIN_B4, 10);
Bounce turbBtn   = Bounce(PIN_B3, 10);
Bounce bcBtn     = Bounce(PIN_D7, 10);
Bounce bankBtn   = Bounce(PIN_C1, 10);
Bounce fd2Btn    = Bounce(PIN_C5, 10);



//ENCODERS BUTTONS
Bounce crs1syncBtn     = Bounce(PIN_B0, 10);
Bounce crs2syncBtn     = Bounce(PIN_A5, 10);

Bounce altsyncBtn   = Bounce(PIN_C2, 10);
Bounce hdgsyncBtn   = Bounce(PIN_E1, 10);
Bounce speedsyncBtn = Bounce(PIN_D5, 10);

//Bounce vssyncBtn    = Bounce(PIN_C3, 10);



// ENCODERS

Encoder speedEncoder = Encoder(PIN_D0, PIN_D4);
Encoder hdgEncoder   = Encoder(PIN_D1, PIN_E0);
Encoder altEncoder   = Encoder(PIN_E5, PIN_D3);
Encoder vsEncoder    = Encoder(PIN_D2, PIN_E4);


Encoder crs1Encoder  = Encoder(PIN_E7, PIN_B1);
Encoder crs2Encoder  = Encoder(PIN_E6, PIN_A4);


// X-Plane objects, Command refs and Data ref
// BUTTONS UPPER
FlightSimInteger apEng;
FlightSimInteger xfrEng;
FlightSimInteger speedEng;
FlightSimInteger apprEng;
FlightSimInteger hdgEng;
FlightSimInteger navEng;

FlightSimInteger altEng;
FlightSimInteger vsEng;


// BUTTONS LOWER
FlightSimInteger fdEng;
FlightSimInteger apDiscEng;
FlightSimInteger turbEng;
FlightSimInteger bcEng;
FlightSimInteger bankEng;
FlightSimInteger fd2Eng;




//FlightSimInteger batteryMaster;
FlightSimInteger testAllLights;




//FlightSimInteger crs2btn_A;
FlightSimInteger crs2btn_B;
FlightSimInteger crs2btn_C;



// ENCODERS
FlightSimInteger altVal;
FlightSimInteger speedVal;
FlightSimInteger hdgVal;
FlightSimInteger vsVal;

FlightSimInteger crs1Val;
FlightSimInteger crs2DHVal;

FlightSimInteger VTVal;


FlightSimInteger altsyncC;
FlightSimInteger speedsyncC;
FlightSimInteger hdgsyncC;
FlightSimInteger crs1syncC;
FlightSimInteger crs2syncC;

FlightSimInteger crs1BarosyncC;
FlightSimFloat crs1BaroVal;




// Variables used in the routine
//long encoder_prev=0;    // used for detecting rotary position change

long altVal_prev=0;
//long altenc;
long hdgVal_prev=0;
//long hdgenc;


long speedVal_prev=100;
//int speedenc=0;

long vsVal_prev=0;
//int vsenc=0;

long crs1Val_prev=0;
long crs1BaroVal_prev=29.92;

// int crs1enc=0;
long crs2DHVal_prev=0;
/*int crs2enc=0;
 
 */
int crs1EBtnClick=0;
int crs1EBtn_mode=0;

int crs2EBtnClick=0;
int crs2EBtn_mode=0;

long VTVal_prev=90;
int spd_val=0;

/*
 //elapsedMillis fd_click_timer;       // double click timer fd
 */
elapsedMillis inactivityTimeout;// an inactivity timeout



// #########################################################
// SETUP runs once, when Teensy boots.
//

void setup() {
  // initialize all hardware



  // ENCODERS PINMODE
  pinMode(PIN_D0, INPUT_PULLUP);  // SPEED ENC 
  pinMode(PIN_D4, INPUT_PULLUP);  // SPEED ENC
  pinMode(PIN_D5, INPUT_PULLUP);  // SPEED BTN


  pinMode(PIN_D1, INPUT_PULLUP);  // HDG ENC 
  pinMode(PIN_E0, INPUT_PULLUP);  // HDG ENC
  pinMode(PIN_E1, INPUT_PULLUP);  // HDG BTN
  pinMode(PIN_D3, INPUT_PULLUP);  // ALT ENC 
  pinMode(PIN_E5, INPUT_PULLUP);  // ALT ENC
  pinMode(PIN_C2, INPUT_PULLUP);  // ALT BTN

  pinMode(PIN_D2, INPUT_PULLUP);  // VS ENC 
  pinMode(PIN_E4, INPUT_PULLUP);  // VS ENC
  //pinMode(PIN_C3, INPUT_PULLUP);  // VS BTN
  //pinMode(PIN_C3, OUTPUT);        // VS BTN AS OUTPUT

  pinMode(PIN_E7, INPUT_PULLUP);  // CRS1 ENC 
  pinMode(PIN_B1, INPUT_PULLUP);  // CRS1 ENC
  pinMode(PIN_B0, INPUT_PULLUP);  // CRS1 BTN


  pinMode(PIN_E6, INPUT_PULLUP);  // CRS2 ENC 
  pinMode(PIN_A4, INPUT_PULLUP);  // CRS2 ENC
  pinMode(PIN_A5, INPUT_PULLUP);  // CRS2 BTN




  // BUTTONS UPPER PART
  pinMode(PIN_C7, INPUT_PULLUP); // AP ENG
  pinMode(PIN_F1, INPUT_PULLUP); // XFR
  pinMode(PIN_F3, INPUT_PULLUP); // SPEED
  pinMode(PIN_F5, INPUT_PULLUP); // APPR
  pinMode(PIN_F7, INPUT_PULLUP); // HDG
  pinMode(PIN_A1, INPUT_PULLUP); // NAV
  pinMode(PIN_A3, INPUT_PULLUP); // ALT
  pinMode(PIN_A6, INPUT_PULLUP);  //VS

  // BUTTONS LOWER PART 
  pinMode(PIN_B6, INPUT_PULLUP); // FD1
  pinMode(PIN_B4, INPUT_PULLUP); // APD
  pinMode(PIN_B3, INPUT_PULLUP); // TRB
  pinMode(PIN_D7, INPUT_PULLUP); // BC
  pinMode(PIN_C1, INPUT_PULLUP); // BANK
  pinMode(PIN_C5, INPUT_PULLUP); // FD2
  //pinMode(6, OUTPUT);


  // LEDS X-PLANE DATAREF 
  // Links the variables to the proper DATAREF

  apLight    = XPlaneRef("CRJ/autopilot/ap_eng_light");
  xfrLight   = XPlaneRef("CRJ/autopilot/xpr_light");
  speedLight = XPlaneRef("CRJ/autopilot/spd_light");
  apprLight  = XPlaneRef("CRJ/autopilot/appr_light");
  hdgLight   = XPlaneRef("CRJ/autopilot/hdg_light");
  navLight   = XPlaneRef("CRJ/autopilot/nav_light");
  altLight   = XPlaneRef("CRJ/autopilot/alt_light");
  vsLight    = XPlaneRef("CRJ/autopilot/vs_light");



  fdLight    = XPlaneRef("CRJ/autopilot/fd_light");
  turbLight  = XPlaneRef("CRJ/autopilot/turb_light");
  bcLight    = XPlaneRef("CRJ/autopilot/bcrs_light");
  bankLight  = XPlaneRef("CRJ/autopilot/bank_light");
  //fd2Light   = XPlaneRef("CRJ/mfd/nav_source"); // Forse da mettere cmq fd




  // BUTTONS X-PLANE DATAREF
  // Links the variables to the proper DATAREF

  apEng     = XPlaneRef("CRJ/autopilot/ap_eng_button");
  xfrEng    = XPlaneRef("CRJ/autopilot/xpr_button");
  speedEng  = XPlaneRef("CRJ/autopilot/speed_button");
  apprEng   = XPlaneRef("CRJ/autopilot/appr_button");
  hdgEng    = XPlaneRef("CRJ/autopilot/hdg_button");
  navEng    = XPlaneRef("CRJ/autopilot/nav_button");
  altEng    = XPlaneRef("CRJ/autopilot/alt_button");
  vsEng     = XPlaneRef("CRJ/autopilot/v_button");

  fdEng     = XPlaneRef("CRJ/autopilot/fd_button");
  apDiscEng = XPlaneRef("CRJ/autopilot/ap_disc_button");
  turbEng   = XPlaneRef("CRJ/autopilot/turbo_button");
  bcEng     = XPlaneRef("CRJ/autopilot/backcrs_button");
  bankEng   = XPlaneRef("CRJ/autopilot/12_bank_button");
  fd2Eng    = XPlaneRef("CRJ/mfd/nav_source");


  testAllLights = XPlaneRef("sim/weapons/z[13]");
  //batteryMaster = XPlaneRef("CRJ/syselec/main_batt");


  //crs2btn_A = XPlaneRef("CRJ/autopilot/alt_sync");
  crs2btn_B =XPlaneRef("CRJ/spd/sel_button");
  crs2btn_C=XPlaneRef("CRJ/spd/tgt_vspds");



  // ENCODER DATAREF
  hdgVal   = XPlaneRef("CRJ/autopilot/hdg");
  altVal   = XPlaneRef("CRJ/autopilot/alt");
  speedVal = XPlaneRef("CRJ/autopilot/speed");  
  vsVal    = XPlaneRef("CRJ/autopilot/verticalspeed");
  crs1Val  = XPlaneRef("CRJ/autopilot/crs1");    // CRS1 MODE0 
  crs1BaroVal  = XPlaneRef("CRJ/baro/pressure"); // CRS1 MODE1 Pressure
  crs2DHVal  = XPlaneRef("CRJ/dh_mda_tune");     // CRS2 MODE1 DH
  VTVal    = XPlaneRef("CRJ/spd/tune");          // CRS2 MODE0 VT Speeds


  altsyncC   = XPlaneRef("CRJ/autopilot/alt_sync");
  hdgsyncC   = XPlaneRef("CRJ/autopilot/hdg_sync");
  speedsyncC = XPlaneRef("CRJ/autopilot/knots_mach");
  crs1syncC = XPlaneRef("CRJ/autopilot/crs1_sync");   // CRS1 SYNC 
  crs1BarosyncC = XPlaneRef("CRJ/baro/pressure_std"); // CRS1 MODE1 BARO SYNC
  crs2syncC = XPlaneRef("CRJ/dh_mda_hide");           // CRS2 SYNC DH

  Serial.begin(9600);



  // hdgenc = hdgVal;
  //altenc = altVal;

  // Invokes the SimLED setup routine
  SimLED::setup();

}


// #########################################################
// LOOP runs repetitively, as long as Teensy is powered up
//
void loop() {
  // normally the first step in loop() should update from X-Plane
  FlightSim.update();
  // Update the LED STATE or enable the test all lights command, 
  // only when the battery Master switch is on (airplane Feed ON).
  SimLED::update();
  //if (batteryMaster==1)
  //{
  // TEST LIGHT MODE    
  SimLED::lightTest(testAllLights==1); 

  //}



  // =================================================
  // HDG ENCODER
  // =================================================
  // read the rotary encoder, if it's changed, write to hdgValue

  // HDG ENCODER SYNC BUTTON
  if ( hdgsyncBtn.update() && hdgsyncBtn.read() == HIGH) {
      if ( hdgsyncC == 0 ) {
        hdgsyncC = 1;
        Serial.println("HDGSYNC!!!");
        delay(500);

      } 
      else {
        hdgsyncC = 0;
      } 
    } 


  // ENCODER ROUTINE
  long hdgenc = hdgEncoder.read();

  if (hdgenc != hdgVal_prev) {
    if (hdgVal>359)
    {
      hdgVal=0;
      hdgEncoder.write(0);
      hdgVal_prev=0;
    }
    else
    {
      Serial.print("HDGVAL: ");
      Serial.print(hdgVal);
      Serial.print(" HDGVAL_prev: ");
      Serial.println(hdgVal_prev);

      if (abs(hdgenc-hdgVal_prev)>1)
      {
        if (inactivityTimeout<25)
        {
          hdgVal = hdgVal + (hdgenc - hdgVal_prev)/abs(hdgenc - hdgVal_prev)*4; 
        }
        else
        {
          hdgVal = hdgVal + (hdgenc - hdgVal_prev)/abs(hdgenc - hdgVal_prev);
        }
        // Serial.println(altVal);
        hdgVal_prev = hdgenc;
        inactivityTimeout=0;
      }
    }
    Serial.print("torno?");
    Serial.println(" No");
  }



  // =================================================
  // ALT ENCODER
  // =================================================
  // read the rotary encoder, if it's changed, write to altValue

  long altenc = altEncoder.read();

  if (altenc != altVal_prev) {

    if (altVal<-10)
    {
      //Serial.println("OUTBOUND!!");
      altVal=-10;
      altEncoder.write(-10);
      altVal_prev=-10;
    }
    else
    {
      Serial.print("ALTVAL: ");
      Serial.print(altVal);
      Serial.print(" ALTVAL_prev: ");
      Serial.println(altVal_prev);
      //Serial.print("ENCODER: ");
      //Serial.println(altenc);
      //Serial.print("timer: ");
      //Serial.println(inactivityTimeout);


      if (abs(altenc-altVal_prev)>1)
      {
        if (inactivityTimeout<25)
        {
          altVal = altVal + (altenc - altVal_prev)/abs(altenc - altVal_prev)*4; 
        }
        else
        {
          altVal = altVal + (altenc - altVal_prev)/abs(altenc - altVal_prev);
        }


        // Serial.println(altVal);

        altVal_prev = altenc;
        inactivityTimeout=0;
        //delay(50);

      }
      Serial.print("torno?");
      Serial.println(" No");
    }
  }




  if ( altsyncBtn.update() && altsyncBtn.read() == HIGH) {
      if ( altsyncC == 0 ) {
        altsyncC = 1;
        delay(500);

      } 
      else {
        altsyncC = 0;
      } 
    } 




  // =================================================
  // SPEED ENCODER
  // =================================================
  // read the rotary encoder, if it's changed, write to altValue

  long speedenc = speedEncoder.read();

  if (speedenc != speedVal_prev) {
    //Serial.println(altenc);
    if (speedVal<100)
    {
      speedVal=100;
      speedEncoder.write(100);
      speedVal_prev=100;
    }
    else
    {
      Serial.print("SPEEDVAL: ");
      Serial.print(speedVal);
      Serial.print("SPEEDVAL_prev: ");
      Serial.println(speedVal_prev);
      if (abs(speedenc-speedVal_prev)>1)
      {
        if (inactivityTimeout<25)
        {
          speedVal = speedVal + (speedenc - speedVal_prev)/abs(speedenc - speedVal_prev)*4; 
        }
        else
        {
          speedVal = speedVal + (speedenc - speedVal_prev)/abs(speedenc - speedVal_prev);
        }
        // Serial.println(altVal);
        speedVal_prev = speedenc;
        inactivityTimeout=0;
      }
    }

    Serial.print("torno?");
    //return;
    Serial.println(" No");
  }

  if ( speedsyncBtn.update() && speedsyncBtn.read() == HIGH) {
      if ( speedsyncC == 0 ) {
        speedsyncC = 1;
        delay(500);

      } 
      else {
        speedsyncC = 0;
      } 
    } 

  // =================================================
  // VS ENCODER
  // =================================================
  // read the rotary encoder, if it's changed, write to altValue

  long vsenc = vsEncoder.read();

  if (vsenc != vsVal_prev) {
    //Serial.println(altenc);
    if (vsVal>50)
    {
      vsVal=50;
      vsEncoder.write(50);
      vsVal_prev=50;
    }
    else if (vsVal<-40){
      vsVal=-40;
      vsEncoder.write(-40);
      vsVal_prev=-40;
    }
    else
    {
      Serial.print("VSVAL: ");
      Serial.print(vsVal);
      Serial.print("VSVAL_prev: ");
      Serial.println(vsVal_prev);
      if (abs(vsenc-vsVal_prev)>1)
      {
        if (inactivityTimeout<25)
        {
          vsVal = vsVal + (vsenc - vsVal_prev)/abs(vsenc - vsVal_prev)*4; 
        }
        else
        {
          vsVal = vsVal + (vsenc - vsVal_prev)/abs(vsenc - vsVal_prev);
        }
        // Serial.println(altVal);
        vsVal_prev = vsenc;
        inactivityTimeout=0;
      }
    }
    Serial.print("torno?");
    //return;
    Serial.println(" No");
    delay(50);
  }






  // =================================================
  // CRS1 ENCODER BTN ROUTINE
  // =================================================
  // First part of the script catches a click, stores the 
  // information in the variable crs2EBtnClick and starts a timer
  // inactivityTimeout.

  // Catches single click
  if (crs1EBtnClick ==0 && crs1syncBtn.update() )
    {
      // ROUTINE BOTTONE 2
      if ( crs1syncBtn.read() == HIGH) 
      {
        Serial.println("SYNC");
        inactivityTimeout = 0;
        crs1EBtnClick =1;
      } 
    }

  // Timer for Double Single click
  if (inactivityTimeout<200 && crs1EBtnClick==1) 
  {

    //ROUTINE DOUBLE CLICK
    if (crs1syncBtn.update() && crs1syncBtn.read() == HIGH) 
      {
        //Serial.println("DOUBLE CLICK");
        //Serial.println("SYNC");
        //     inactivityTimeout = 0;
        if (crs1EBtn_mode==1)   
        {
          // SWITCH BETWEEN TWO MODES OF SINGLE CLICK
          crs1EBtn_mode=0;

        }
        else      
        {
          crs1EBtn_mode=1;
          // SINGLE BLINK OF THE LED
          //digitalWrite(6, HIGH);
          //delay(40);
          //digitalWrite(6, LOW);
        }
        crs1EBtnClick =0;
        //    
      }
    

  }

  // SINGLE CLICK ROUTINE
  else if (inactivityTimeout>=200 && crs1EBtnClick==1)    
  {
    // DO SINGLE CLICK MODE 1
    if (crs1EBtn_mode==1)  // BARO SYNC  
    {
      if ( crs1BarosyncC == 0 ) {
        crs1BarosyncC = 1;
        delay(500);
        //DECISION HEIGHT KNOB ON OFF

      } 
      else {
        crs1BarosyncC = 0;
      } 

      crs1EBtnClick=0;  

    }

    // DO SINGLE CLICK MODE 0
    else // crs1EBtn_mode=0
    {
      if ( crs1syncC == 0 ) {
        crs1syncC = 1;
        delay(500);

      } 
      else      {
        crs1syncC = 0;
      }

      crs1EBtnClick=0;
    }
  }


  // ENCODER CRS1 TWO MODES
  if(crs1EBtn_mode==1) // BARO
  {

    long crs1enc = crs1Encoder.read();

    if (crs1enc != crs1BaroVal_prev) {
      //Serial.println(altenc);
      if (crs1BaroVal>31.00)    {

        crs1BaroVal=31.00;
        crs1Encoder.write(31.00);
        crs1BaroVal_prev=31.00;
      }
      else if (crs1BaroVal<27.90)
      {
        crs1BaroVal=27.90;
        crs1Encoder.write(27.90);
        crs1BaroVal_prev=27.90;

      }
      else
      {
        if (abs(crs1enc-crs1BaroVal_prev)>1)
        {
          if (inactivityTimeout<25)
          {
            crs1BaroVal = crs1BaroVal - (crs1enc - crs1BaroVal_prev)/abs(crs1enc - crs1BaroVal_prev)*4*0.01; 
          }
          else
          {
            crs1BaroVal = crs1BaroVal - (crs1enc - crs1BaroVal_prev)/abs(crs1enc - crs1BaroVal_prev)*0.01;
          }
          // Serial.println(altVal);
          crs1BaroVal_prev = crs1enc;
          inactivityTimeout=0;
        }
      }
    }

  }
  else // CRS1 
  {
    long crs1enc = crs1Encoder.read();

    if (crs1enc != crs1Val_prev) {
      //Serial.println(altenc);
      if (crs1Val>360)
      {
        crs1Val=0;
        crs1Encoder.write(0);
        crs1Val_prev=0;
      }
      else
      {

        if (abs(crs1enc-crs1Val_prev)>1)
        {
          if (inactivityTimeout<25)
          {
            crs1Val = crs1Val - (crs1enc - crs1Val_prev)/abs(crs1enc - crs1Val_prev)*4; 
          }
          else
          {
            crs1Val = crs1Val - (crs1enc - crs1Val_prev)/abs(crs1enc - crs1Val_prev);
          }
          // Serial.println(altVal);
          crs1Val_prev = crs1enc;
          inactivityTimeout=0;
        }
      }

    }
  }


  /*

   long crs1enc = crs1Encoder.read();
   
   if (crs1enc != crs1Val_prev) {
   //Serial.println(altenc);
   if (crs1Val>360)
   {
   crs1Val=0;
   crs1Encoder.write(0);
   crs1Val_prev=0;
   }
   else
   {
   if (abs(crs1enc-crs1Val_prev)>1)
   {
   if (inactivityTimeout<25)
   {
   crs1Val = crs1Val + (crs1enc - crs1Val_prev)/abs(crs1enc - crs1Val_prev)*4; 
   }
   else
   {
   crs1Val = crs1Val + (crs1enc - crs1Val_prev)/abs(crs1enc - crs1Val_prev);
   }
   // Serial.println(altVal);
   crs1Val_prev = crs1enc;
   inactivityTimeout=0;
   }
   }
   }
   
   if ( crs1syncBtn.update() ) {
   if ( crs1syncBtn.read() == HIGH) {
   if ( crs1syncC == 0 ) {
   crs1syncC = 1;
   delay(500);
   
   } 
   else {
   crs1syncC = 0;
   } 
   } 
   }
   
   */


  // =================================================
  // CRS2 ENCODER BTN ROUTINE
  // =================================================
  // First part of the script catches a click, stores the 
  // information in the variable crs2EBtnClick and starts a timer
  // inactivityTimeout.

  if (crs2EBtnClick ==0 && crs2syncBtn.update() )
    {
      // ROUTINE BOTTONE 2
      if ( crs2syncBtn.read() == HIGH) 
      {
        Serial.println("SYNC");
        inactivityTimeout = 0;
        crs2EBtnClick =1;
      } 
    }


  // Second part of the script verifies the click/timer condition:
  //   - if elapsed time is less than 200 ms, a click was previously
  //     made, and another click is received, the double click routine
  //     cycles through the 2 modes.
  //   - if elapsed time is more than 200 ms, and a click was previously
  //     made, the single button click routine is performed.

  if ((inactivityTimeout<200) && (crs2EBtnClick==1)) 
  {
    //ROUTINE DOUBLE CLICK
    if (crs2syncBtn.update() ) 
    {
      if ( crs2syncBtn.read() == HIGH) 
      {
        //Serial.println("DOUBLE CLICK");
        //Serial.println("SYNC");
        //     inactivityTimeout = 0;
        if (crs2EBtn_mode==1)   
        {
          // SWITCH BETWEEN TWO MODES OF SINGLE CLICK
          crs2EBtn_mode=0;

        }
        else      
        {
          crs2EBtn_mode=1;
          // SINGLE BLINK OF THE LED
          //digitalWrite(6, HIGH);
          //delay(40);
          //digitalWrite(6, LOW);
        }
        crs2EBtnClick =0;
        //    
      }
    }
  }

  // SINGLE CLICK ROUTINE
  else if (inactivityTimeout>=200 && crs2EBtnClick==1)    
  {
    // DO SINGLE CLICK MODE 1
    if (crs2EBtn_mode==1)  // DECISION HEIGHT SYNC  
    {

      if ( crs2syncC == 0 ) {
        crs2syncC = 1;
        delay(500);
        //DECISION HEIGHT KNOB ON OFF

      } 
      else {
        crs2syncC = 0;
      } 

      crs2EBtnClick=0;  

    }

    // DO SINGLE CLICK MODE 0
    else // crs2EBtn_mode=0
    {

      //Serial.println("SINGLE CLICK");
      //Serial.print("SPD_VAL=");
      //Serial.println(spd_val);

      // CUSTOM ROUTINE DUE TO V1 V2 VR VT
      // crs2btn_B  = V1 V2 VR
      // crs2btn_C = TGT SPEED KNOB


      // spd_val goes from 0 to 3, and is used for the encoder
      // to adjust the values of V1 V2 VR and VT.
      if (spd_val==0)
      {
        // CHANGES BETWEEN the other Velocities to VT
        spd_val=spd_val+1;
        crs2btn_C=0;


      }
      else if(spd_val==1)
      {
        // CHANGES BETWEEN VT and the other Velocities
        spd_val=spd_val+1;
        crs2btn_C=1;
        crs2btn_B=1;
      }
      else if (spd_val<=3)
      {

        // CYCLES through V1 V2 VR
        crs2btn_B=1;
        spd_val=spd_val+1;
        if( spd_val==4)
        {
          spd_val=0;
        }
      }

      crs2EBtnClick=0;
      //Serial.println("FineSingle2ON");

    }
  }




  // ENCODER CRS2 TWO MODES
  if(crs2EBtn_mode==1) // DH
  {
    long crs2enc = crs2Encoder.read();

    if (crs2enc != crs2DHVal_prev) {


      if (crs2DHVal<0)
      {
        crs2DHVal=0;
        crs2Encoder.write(0);
        crs2DHVal_prev=0;
      }
      else
      {
        if (abs(crs2enc-crs2DHVal_prev)>1)
        {
          if (inactivityTimeout<25)
          {
            crs2DHVal = crs2DHVal + (crs2enc - crs2DHVal_prev)/abs(crs2enc - crs2DHVal_prev)*4*10; 
          }
          else
          {
            crs2DHVal = crs2DHVal + (crs2enc - crs2DHVal_prev)/abs(crs2enc - crs2DHVal_prev)*10;
          }
          // Serial.println(altVal);
          crs2DHVal_prev = crs2enc;
          inactivityTimeout=0;
          //Serial.print("torno?");
          //return;
          //Serial.println(" No");
          //delay(50);
        }
      }
    }

  }
  else
  {
    long crs2enc = crs2Encoder.read();

    if (crs2enc != VTVal_prev) {


      if (VTVal<90)
      {
        VTVal=90;
        crs2Encoder.write(90);
        VTVal_prev=90;
      }
      else
      {
        if (abs(crs2enc-VTVal_prev)>1)
        {
          if (inactivityTimeout<25)
          {
            VTVal = VTVal + (crs2enc - VTVal_prev)/abs(crs2enc - VTVal_prev)*4; 
          }
          else
          {
            VTVal = VTVal + (crs2enc - VTVal_prev)/abs(crs2enc - VTVal_prev);
          }
          // Serial.println(altVal);
          VTVal_prev = crs2enc;
          inactivityTimeout=0;
          //Serial.print("torno?");
          //return;
          Serial.println(" No");
          //delay(50);
        }
      }
    }

  }




  // =================================================







  // ++=============================================++
  // ||=============================================||
  // ||          BUTTONS NORMAL ROUTINES            ||
  // ||=============================================||
  // ++=============================================++

  // Autopilot Engage Button
  if ( apEngBtn.update() && apEngBtn.read() == HIGH) {
    if ( apEng == 0 ) {
      apEng = 1;
    } 
    else {
      apEng = 0;
    } 
  } 

  // XFR Engage Button
  if ( xfrBtn.update() && xfrBtn.read() == HIGH) {
    if ( xfrEng == 0 ) {
      xfrEng = 1;
    } 
    else {
      xfrEng = 0;
    } 
  } 

  // SPEED Engage Button
  if ( speedBtn.update() && speedBtn.read() == HIGH) {
    if ( speedEng == 0 ) {
      speedEng = 1;
    } 
    else {
      speedEng = 0;
    } 
  }    

  // APPR Engage Button
  if ( apprBtn.update() && apprBtn.read() == HIGH) {
    if ( apprEng == 0 ) {
      apprEng = 1;
    } 
    else {
      apprEng = 0;
    } 
  } 

  // HDG Engage Button
  if ( hdgBtn.update() && hdgBtn.read() == HIGH) {
    if ( hdgEng == 0 ) {
      hdgEng = 1;
    } 
    else {
      hdgEng = 0;
    } 
  } 

  // NAV Engage Button
  if ( navBtn.update() && navBtn.read() == HIGH) {
    if ( navEng == 0 ) {
      navEng = 1;
    } 
    else {
      navEng = 0;
    } 
  } 

  // ALT Engage Button
  if ( altBtn.update() && altBtn.read() == HIGH) {
    if ( altEng == 0 ) {
      altEng = 1;
    } 
    else {
      altEng = 0;
    } 
  } 

  // VS Engage Button
  if ( vsBtn.update() && vsBtn.read() == HIGH) {
    if ( vsEng == 0 ) {
      vsEng = 8;
    } 
    else {
      vsEng = 0;
    } 
  } 


  // FD Engage Button
  if ( fdBtn.update() && fdBtn.read() == HIGH) {
    if ( fdEng == 0 ) {
      fdEng = 1;
      Serial.println("FDENGAGE");
    } 
    else {
      fdEng = 0;
    } 
  } 

  // APDISC Engage Button
  if ( apDiscBtn.update() && apDiscBtn.read() == HIGH) {
    if ( apDiscEng == 0 ) {
      apDiscEng = 1;
    } 
    else {
      apDiscEng = 0;
    } 
  } 


  // TURB Engage Button
  if ( turbBtn.update() && turbBtn.read() == HIGH) {
    if ( turbEng == 0 ) {
      turbEng = 1;
    } 
    else {
      turbEng = 0; 
    } 
  }


  // BC Engage Button
  if ( bcBtn.update() && bcBtn.read() == HIGH) {
    if ( bcEng == 0 ) {
      bcEng = 1;
    } 
    else {
      bcEng = 0;
    } 
  } 

  // 1/2 BANK Engage Button
  if ( bankBtn.update() && bankBtn.read() == HIGH) {
    if ( bankEng == 0 ) {
      bankEng = 1;
    } 
    else {
      bankEng = 0;
    }  
  }

  // FD2 Engage Button 
  if ( fd2Btn.update() && fd2Btn.read() == HIGH) {

    if ( fd2Eng == 0 ) {
      fd2Eng = 1; // NAV1 VOR MODE
    } 
    else if (fd2Eng ==1) {
      fd2Eng = 2; // NAV2 VOR MODE
    } 
    else if (fd2Eng ==2) {
      fd2Eng = 3; // FMS MODE
    } 
    else if (fd2Eng ==3) {
      fd2Eng = 0; // OFF
    } 
    Serial.println("NAV1 NAV2 FMS OFF");

  }

}
