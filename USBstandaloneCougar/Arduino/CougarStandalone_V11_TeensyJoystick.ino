/* Thrustmaster Cougar Throttle Standalone USB Adapter
   Giovanni Medici 2020
   This sketch controls the Thrustmaster Cougar Throttle,
   through a Teensy 4.0 board.
   Buttons Names:
   T1 = Slew Radar Cursor (Cursor Joystick Button)
   T2 = Transmit VHF (UP)
   T3 = Transmit UHF (DNW)
   T4 = (RGT)
   T5 = (LFT)
   T6 = Uncage (Radar Range Knob Button)
   T7 = Dogfight Mode
   T8 = Missile Override Mode
   T9 = Open AirBrakes
   T10 = Close AirBrakes
   T11 = Idle cutoff
   T12 = Dogfight Cancel

   Pin- VGA
   23 = 6
   2  = 7
   3  = 8
   4  = 9
   5  = 2
   6  = 3
   7  = 4

Change log:
20220531 : Changed the Joystick so to take advantage of the native Joystick 
           mode of Teensy
20210310 : Added a byte check whether the user has calibrated the device at
           least once. Added comments. Removed warnings during compilation.
20210228 : Added axis shaping for Antenna 


© 2021. This work is licensed under a CC BY 4.0 license. 
You are free to:
Share — copy and redistribute the material in any medium or format.
Under the following terms:
Attribution — You must give appropriate credit, provide a link to the license, 
and indicate if changes were made. You may do so in any reasonable manner, but 
not in any way that suggests the licensor endorses you or your use.
NonCommercial — You may not use the material for commercial purposes.
NoDerivatives — If you remix, transform, or build upon the material, you may 
not distribute the modified material.
No additional restrictions — You may not apply legal terms or technological 
measures that legally restrict others from doing anything the license permits.
.*/

#include <EEPROM.h>
#include "Smoothed.h"


const int numButtons = 32;  // 32 for Cougar Throttle 16 for Teensy, 32 for Teensy++
unsigned long loopCount;
unsigned long startTime, holdStart;
String msg;

bool flagStart = 0;         // True when both T1 and T6 are pressed
bool printSerial = 0;       // When true, prints verbose text in the Serial Monitor

uint16_t btns = 0;          // Array of the buttons

char lo ;
char hi ;

// arrays that store min max 0/idle
unsigned short Tscale[3];
unsigned short Xscale[3], Yscale[3], Ascale[3], Rscale[3];

// Handle the toggle switches
byte T7prev, T7now, T8prev, T8now, T12prev, T12now, T12now2, T8now2, T7now2 = 0;
uint32_t T7time, T8time, T10time, T12time = 0;

Smoothed <unsigned short> TSens;
Smoothed <unsigned short> XSens;
Smoothed <unsigned short> YSens;
Smoothed <unsigned short> ASens;
Smoothed <unsigned short> RSens;


int ledPin  = 13;


void setup() {
  // put your setup code here, to run once:
  if (printSerial)  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  pinMode( 5, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode( 7, OUTPUT);

  pinMode(23, INPUT);
  pinMode( 2, INPUT);
  pinMode( 3, INPUT);
  pinMode( 4, INPUT);


  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  loopCount = 0;
  startTime = millis();
  msg = "";
  // configure the joystick to manual send mode.  This gives precise
  // control over when the computer receives updates, but it does
  // require you to manually call Joystick.send_now().
  Joystick.useManualSend(true);

  //Serial.println("Begin Complete Joystick Test");

  // Defines thresholds and smooth weights of the axes

  TSens.begin(SMOOTHED_AVERAGE, 5);
  XSens.begin(SMOOTHED_AVERAGE, 3);
  YSens.begin(SMOOTHED_AVERAGE, 3);
  RSens.begin(SMOOTHED_AVERAGE, 5);
  ASens.begin(SMOOTHED_AVERAGE, 5);
  analogReadResolution(12);
  loadCalibration();
}


void loop() {
  unsigned short TNow, XNow, YNow, ANow, RNow;

  loopCount++;
  if ( (millis() - startTime) > 5000 ) {
    //Serial.print("Average loops per second = ");
    //Serial.println(loopCount / 5);
    startTime = millis();
    loopCount = 0;
  }


  btns = pullMatrix();
  lo = btns & 0xFF;
  hi = btns >> 8;


  // Simple routine which Serial Prints the status of the buttons
  if (printSerial)  printBinary(btns);


  Joystick.button( 1, bitRead(btns, 0)); // T1
  Joystick.button( 2, bitRead(btns, 1)); // T2
  Joystick.button( 3, bitRead(btns, 2)); // T3
  Joystick.button( 4, bitRead(btns, 3)); // T4
  Joystick.button( 5, bitRead(btns, 4)); // T5
  Joystick.button( 6, bitRead(btns, 5)); // T6
  Joystick.button( 7, bitRead(btns, 6)); // T7
  Joystick.button( 8, bitRead(btns, 7)); // T8
  Joystick.button( 9, bitRead(btns, 8)); // T9
  Joystick.button(10, bitRead(btns, 9)); // T10
  Joystick.button(12, bitRead(btns, 11)); // Dogfight Override (Center)


  for (int i = 13; i < numButtons; i++) {
    Joystick.button(i, 0);
  }

  // Pulls down all button lines
  digitalWrite(5, HIGH); // pull pin 5 down
  digitalWrite(6, HIGH); // pull pin 6 down
  digitalWrite(7, HIGH); // pull pin 7 down
  //delay(4);

  // Sends an HIGH and then low to PIN 18, to reduce noise of the analogRead
  //reduceNoise(18);

  
  analogRead(18);
  TNow = analogRead(18);

   if (printSerial)  {
    Serial.print("T0: ");
    Serial.print(TNow);
    Serial.print(" | ");
    }
    // Mapping throttle axes to min max values (13 bit)
  if (TNow>=Tscale[1]) TNow = Tscale[1]-1;
  if (TNow<=Tscale[0]) TNow = Tscale[0]+1;
  
  TNow = map(TNow, Tscale[0], Tscale[1], 0, 1023);
  //TNow = mapAxes(TNow, Tscale);

  
  XNow = analogRead(19);
  XNow = mapAxes(XNow, Xscale);
  XNow = XNow/8; // 13 to 10 bit
  XNow = XNow*8;
  
  
  YNow = analogRead(15);
  YNow = mapAxes(YNow, Yscale);
  YNow = YNow/8; // 13 to 10 bit
  YNow = YNow*8;
  
  
  ANow = analogRead(17);
  //ANow = ANow/8; // 13 to 10 bit
  ANow = mapAxesAnt(ANow, Ascale);


  RNow = analogRead(16);
  //RNow = RNow/8;
  RNow = mapAxes(RNow, Rscale);


  // Serial print the readed values
  if (printSerial)  {
    Serial.print("RAW T: ");
    Serial.print(TNow);
    Serial.print(" | X: ");
    Serial.print( XNow );
    Serial.print(" | Y: ");
    Serial.print(YNow);
    Serial.print(" | A: ");
    Serial.print(ANow);
    Serial.print(" | R: ");
    Serial.print(RNow);
    Serial.print(" ");
  }

  // Clamps to max min values
  TNow = checkInt( TNow );
  XNow = checkInt( XNow );
  YNow = checkInt( YNow );
  ANow = checkInt( ANow );
  RNow = checkInt( RNow );


  // Filters small changes
  //if ( abs( ( XSens.getLast()-XNow ) ) < 5 )  XNow = XSens.getLast();
  //if ( abs( ( YSens.getLast()-YNow ) ) < 5 )  YNow = YSens.getLast();

  TSens.add(TNow);
  XSens.add(XNow);
  YSens.add(YNow);
  ASens.add(ANow);
  RSens.add(RNow);

  Joystick.Z( TSens.get() );
  Joystick.sliderLeft(RSens.get());
  Joystick.sliderRight(ASens.get());
  Joystick.X(XSens.get());
  Joystick.Y(YSens.get());


  //digitalWrite(5, LOW); // pull pin 3 back up
  //digitalWrite(6, LOW); // pull pin 3 back up
  //digitalWrite(7, LOW); // pull pin 3 back up

  //Throttle Cutoff Detent
  //if ( ( TNow > (Tscale[2]-50) ) && (TNow < (Tscale[2]+50 ) ) )   Joystick.button(11, 1);
  //else Joystick.button(11,0);
  Joystick.button(11, 0);

  // Sends the USB packet
  Joystick.send_now();

  // If both Antenna and Range knob buttons are pressed
  // Starts counting
  if (bitRead(btns, 0) && bitRead(btns, 5))
  {
    if (flagStart == 0) // flags 
    {
      holdStart = millis();
      flagStart = 1;
    }
    else if (flagStart == 1)
    {
      if (( millis() - holdStart) > 2000)
      {
        // Enters configuration mode
        if (printSerial)  {
          Serial.println("");
          Serial.println("Entering Calibration mode");
        }
        flagStart = 0;
        enterConfig();
        loadCalibration();
      }
    }


  }



  // Serial print the readed values
  if (printSerial)  {
    Serial.print("T: ");
    Serial.print(TSens.get());
    Serial.print(" | X: ");
    Serial.print( XSens.get() );
    Serial.print(" | Y: ");
    Serial.print(YSens.get());
    Serial.print(" | A: ");
    Serial.print(ASens.get());
    Serial.print(" | R: ");
    Serial.println(RSens.get());
  }

}



int checkInt(unsigned short x) {
  // Clamps to max min values 10 bit
  if (x > 1023) x = 1023;
  if (x < 0) x = 0;
  return x;
}


int checkInt12(unsigned short x) {
  // Clamps to max min values 12 bit
  if (x > 4095) x = 4095;
  if (x < 0) x = 0;
  return x;
}


void enterConfig() {
  // This is the configuration routine, once enterd it will last 10 seconds,
  // during this time the user shall move the axis and knobs and release them
  // to their rest position.
  // The throttle axis shall be left in the idle detent position.

  // Triggers the watchdog
  unsigned long startCali, now;

  startCali = millis();
  delay(250);


  now = millis();

  //uint32_t T_max, T_min, T_idle ;
  unsigned int T_max, T_min, T_idle ;
  unsigned int A_max, A_min, A_0 ;
  unsigned int R_max, R_min, R_0 ;
  unsigned int X_max, X_min, X_0 ;
  unsigned int Y_max, Y_min, Y_0 ;

  //uint32_t T_now;
  unsigned int T_now = 0;
  unsigned int X_now = 0, Y_now = 0, A_now = 0, R_now = 0;

  T_min = A_min = R_min = X_min = Y_min = 4095;
  T_max = T_idle = 0;
  A_max = A_0 = 0;
  R_max = R_0 = 0;
  X_max = X_0 = 0;
  Y_max = Y_0 = 0;

  
  // Turns on the led
  digitalWrite(ledPin, HIGH);
  while ((now - startCali) < 20000L)
  {
    // Reads the smoothed value of the axis

    reduceNoise(19);
    X_now = analogRead(19);

    reduceNoise(15);
    Y_now = analogRead(15);
    
    reduceNoise(17);
    A_now = analogRead(17);
    
    reduceNoise(16);
    R_now = analogRead(16);

    reduceNoise(18);
    T_now = analogRead(18);

    // Clamp to max min values
    X_now = checkInt12(X_now);
    Y_now = checkInt12(Y_now);
    A_now = checkInt12(A_now);
    R_now = checkInt12(R_now);
    T_now = checkInt12(T_now);



    if (X_now > X_max) X_max = X_now;
    if (Y_now > Y_max) Y_max = Y_now;
    if (A_now > A_max) A_max = A_now;
    if (R_now > R_max) R_max = R_now;
    if (T_now > T_max) T_max = T_now;


    if (X_now < X_min) X_min = X_now;
    if (Y_now < Y_min) Y_min = Y_now;
    if (A_now < A_min) A_min = A_now;
    if (R_now < R_min) R_min = R_now;
    if (T_now < T_min) T_min = T_now;
    
    now = millis();
  }
  if (printSerial) {
    Serial.println("");
    Serial.println("Calibration Finished");
  }
  X_0 = X_now;
  Y_0 = Y_now;
  A_0 = A_now;
  R_0 = R_now;
  T_idle = T_now;

  // Write Values to memory
  // Exit configuration mode
  blinkLED(4);

  // Writes to EEPROM the calibration values
  shiftSave(0,  X_min);
  shiftSave(2,  X_max);
  shiftSave(4,  X_0);

  shiftSave(6,  Y_min);
  shiftSave(8,  Y_max);
  shiftSave(10, Y_0);

  shiftSave(12, A_min);
  shiftSave(14, A_max);
  shiftSave(16, A_0);

  shiftSave(18, R_min);
  shiftSave(20, R_max);
  shiftSave(22, R_0);

  shiftSave(24, T_min);
  shiftSave(26, T_max);
  shiftSave(28, T_idle);
  
  EEPROM.update(30,1); // Update checks if the value need to be changed (preserve EEPROM)
  blinkLED(4);

}



void blinkLED(int n)
{
  // Blinks the led to tell the user that configuration
  // routine is about to finish.
  for (int i = 0; i < n; i++) // Repeats n times
  {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}


void shiftSave(int addr, int number)
{
  // This routine splits the number into convenient bytes
  // and writes it into the EEPROM starting from the specified
  // address.
  EEPROM.write(addr, number >> 8);
  EEPROM.write(addr + 1, number & 0xFF);
}



int shiftLoad(int addr )
{
  // This routine loads the specified address couple
  // and returns the value obtained by merging the
  // the two addresses.
  // and writes it into the EEPROM starting from the specified
  // address.
  return (EEPROM.read(addr) << 8) + EEPROM.read(addr + 1);
}


void loadCalibration()
{
  byte isConfig = EEPROM.read( 30 );
  
  if (isConfig!=255)
  {
  // Reads from EEPROM and fills the calibration values
  Xscale[0] = shiftLoad(  0 );
  Xscale[1] = shiftLoad(  2 );
  Xscale[2] = shiftLoad(  4 );

  Yscale[0] = shiftLoad(  6 );
  Yscale[1] = shiftLoad(  8 );
  Yscale[2] = shiftLoad( 10 );

  Ascale[0] = shiftLoad( 12 );
  Ascale[1] = shiftLoad( 14 );
  Ascale[2] = shiftLoad( 16 );

  Rscale[0] = shiftLoad( 18 );
  Rscale[1] = shiftLoad( 20 );
  Rscale[2] = shiftLoad( 22 );


  Tscale[0] = shiftLoad( 24 );
  Tscale[1] = shiftLoad( 26 );
  Tscale[2] = shiftLoad( 28 );
  }
  else
  {
    // Fills default calibration values;
    Xscale[0] = 0;
    Xscale[1] = 4095;
    Xscale[2] = 2048;

    Yscale[0] = 0;
    Yscale[1] = 4095;
    Yscale[2] = 2048;

    Ascale[0] = 0;
    Ascale[1] = 4095;
    Ascale[2] = 2048;

    Rscale[0] = 0;
    Rscale[1] = 4095;
    Rscale[2] = 2048;

    Tscale[0] = 0;
    Tscale[1] = 4095;
    Tscale[2] = 3800;
  }
  
  if (printSerial)  {
    Serial.print("isConfig = ");
    Serial.println(isConfig);
    if (isConfig==1)
    {
      Serial.println("Previous calibration configuration found.");
    }
    else
    {
      Serial.println("No calibration found, will use default values.");
    }
    Serial.println("Xscale min | max | 0 || Yscale min | max | 0 | Ascale min | max | 0 || Rscale min | max | 0 ");
    Serial.print(Xscale[0]);
    Serial.print(" ");
    Serial.print(Xscale[1]);
    Serial.print(" ");
    Serial.print(Xscale[2]);
    Serial.print(" | ");
    Serial.print(Yscale[0]);
    Serial.print(" ");
    Serial.print(Yscale[1]);
    Serial.print(" ");
    Serial.print(Yscale[2]);
    Serial.print(" | ");
    Serial.print(Ascale[0]);
    Serial.print(" ");
    Serial.print(Ascale[1]);
    Serial.print(" ");
    Serial.print(Ascale[2]);
    Serial.print(" | ");
    Serial.print(Rscale[0]);
    Serial.print(" ");
    Serial.print(Rscale[1]);
    Serial.print(" ");
    Serial.println(Rscale[2]);

    Serial.println("Tscale min | max | idle ");
    Serial.print(Tscale[0]);
    Serial.print(" ");
    Serial.print(Tscale[1]);
    Serial.print(" ");
    Serial.println(Tscale[2]);
    Serial.println();
  }

}

uint16_t pullMatrix(void) {
  // This routine reads the status of the pushbuttons.
  // They are wired in a matrix form, with the "feed"
  // PINS 2 3 and 4 of the VGA cable, while the "sensing"
  // ones are 6 7 8 and 9.
  // In the adapter I designed, they are hooked to different
  // pins in the Teensy
  //  VGA - TEENSY
  //  6   - 23
  //  7   -  2
  //  8   -  3
  //  9   -  4
  //  2   -  5
  //  3   -  6
  //  4   -  7


  uint16_t buttons = 0, butTemp = 0; // create a 16bit variable to store the button data
  byte T7prevT, T8prevT, T12prevT = 0;
  //byte T10prevT = 0;
  digitalWrite(7, LOW); // pull line 4 down
  delay(2);
  bitWrite(buttons, 1, !(digitalRead(2))); // read T1 (cursor enable)
  bitWrite(buttons, 6, !(digitalRead(23))); // read T6 (uncage)
  digitalWrite(7, HIGH); // bring line 4 back up


  digitalWrite(5, LOW); // pull pin 2 down
  delay(2);
  bitWrite(buttons, 2, !(digitalRead(23))); // T2
  bitWrite(buttons, 3, !(digitalRead(2))); // T3
  bitWrite(buttons, 4, !(digitalRead(3))); // T4
  bitWrite(buttons, 5, !(digitalRead(4))); // T5
  digitalWrite(5, HIGH); // bring pin 2 back up


  digitalWrite(6, LOW); // pull pin 3 down
  delay(2);
  bitWrite(buttons, 7, !(digitalRead(23))); // T7 DGF
  bitWrite(buttons, 8, !(digitalRead(2))); // T8
  bitWrite(buttons, 9, !(digitalRead(3))); // T9
  bitWrite(buttons, 10, !(digitalRead(4))); // T10
  digitalWrite(6, HIGH); // bring pin 3 back up

  // Dogfight Override
  if (bitRead(buttons, 7) == 0 && (bitRead(buttons, 8) == 0 )) bitWrite(buttons, 12, 1);
  else bitWrite(buttons, 12, 0);

  // Deals with DogfightOverride Toggle Switch T7
  momentarySwitch(T7prev, buttons, 7, T7time, &T7time, &butTemp, &T7prevT);
  T7prev = T7prevT;
  buttons = butTemp;
  
  // Deals with DogfightOverride Toggle Switch T8
  momentarySwitch(T8prev, buttons, 8, T8time, &T8time, &butTemp, &T8prevT);
  T8prev = T8prevT;
  buttons = butTemp;

  // Deals with Dogfight Cancel (Center) Toggle Switch T12
  momentarySwitch(T12prev, buttons, 12, T12time, &T12time, &butTemp, &T12prevT) ;
  T12prev = T12prevT;
  buttons = butTemp;


  return (buttons >> 1);
}

void printBinary(uint16_t inByte)
{
  Serial.print("Key : ");
  // Prints a binary bit by bit
  for (int b = 0; b <= 11; b++)
  {
    Serial.print(bitRead(inByte, b));
  }
  Serial.print(" | ");
}

int mapAxes(unsigned short Value, unsigned short ScaleVal[])
{

  // Clamps to max min
  if (Value > ScaleVal[1]) Value = ScaleVal[1];
  if (Value < ScaleVal[0]) Value = ScaleVal[0];
  // Simple routine to map values according to min max 0
  if (Value >= ScaleVal[2])
  {

    Value = map(Value, ScaleVal[2], ScaleVal[1], 512, 1023);
  }
  else
  {
    /*Serial.print(Value);
    Serial.print(" ");
    Serial.print(ScaleVal[0]);
    Serial.print(" ");
    Serial.print(ScaleVal[2]);
    Serial.print(" ");*/
    Value = map(Value, ScaleVal[0], ScaleVal[2], 0, 511);
    //Serial.print(Value);
    
  }


  return Value;
}



int mapAxesAnt(unsigned short Value, unsigned short ScaleVal[])
{

  // Clamps to max min
  if (Value > ScaleVal[1]) Value = ScaleVal[1];
  if (Value < ScaleVal[0]) Value = ScaleVal[0];
  // Simple routine to map values according to min max 0
  if (Value >= ScaleVal[2])
  {

    Value = map(Value, ScaleVal[2], ScaleVal[1], 512, 1023);
    if (Value>=896)
    {Value = map(Value, 896, 1023, 704, 1023);}
    else if (Value>=768)
    {Value = map(Value, 768, 895, 576, 703);}
    else if (Value>=512)
    {Value = map(Value, 512, 767, 512, 575);}
    
    
  }
  else
  {
    /*Serial.print(Value);
    Serial.print(" ");
    Serial.print(ScaleVal[0]);
    Serial.print(" ");
    Serial.print(ScaleVal[2]);
    Serial.print(" ");*/
    Value = map(Value, ScaleVal[0], ScaleVal[2], 0, 511);
    //Serial.print(Value);
    if (Value>=256)
    {Value = map(Value, 256, 511, 447, 511);}
    else if (Value>=125)
    {Value = map(Value, 125, 255, 319, 446);}
    else if (Value<125)
    {Value = map(Value, 0, 124, 0, 318);}
    
  }


  return Value;
}

void reduceNoise(int pinNum)
{
  // This function reduces the noise in the pot
  // (particoularly effective for the Microstick).
  //digitalWrite(pinNum, HIGH);
  //delay(4); //5
  //digitalWrite(pinNum, LOW);
  
}


void momentarySwitch(byte previous, uint16_t buttons, int address, long lastTime, uint32_t *newTime, uint16_t *newbuttons, byte *prev )
{
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time

  *newTime = lastTime;
  *newbuttons = buttons;
  if (( bitRead(buttons, address) == 1) && (previous == 0) & ( ( millis() - lastTime) > 100 ) )
  {
    if (printSerial)  Serial.println("Momentary");

    *newTime = millis();
    bitSet(*newbuttons, address);
  }
  else if ( ( millis() - lastTime) > 20 )
  {
    bitClear(*newbuttons, address);
  }

  *prev = bitRead(buttons, address);



}
