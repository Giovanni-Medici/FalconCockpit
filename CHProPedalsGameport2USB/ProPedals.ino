

// Program used to setup an adapter for Ch Pro Pedals 
// Gameport to USB adapter.
//
// Giovanni Medici
// 2020-09-13 
//
// © 2021. This work is licensed under a CC BY 4.0 license. 
// You are free to:
// Share — copy and redistribute the material in any medium or format.
// Under the following terms:
// Attribution — You must give appropriate credit, provide a link to the license, 
// and indicate if changes were made. You may do so in any reasonable manner, but 
// not in any way that suggests the licensor endorses you or your use.
// NonCommercial — You may not use the material for commercial purposes.
// NoDerivatives — If you remix, transform, or build upon the material, you may 
// not distribute the modified material.
// No additional restrictions — You may not apply legal terms or technological 
// measures that legally restrict others from doing anything the license permits.
//------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_JOYSTICK, 0, 0, // 0 buttons, 0 hatswitches
                   false, false, false, true, true, true, // no x,y,z,Rx,Ry,Rz
                   false, false, false, false, false );         // Rudder, no Throttle, Accelerator and Brake, no Steering


void setup() {
  // Initialize the three axis
  //Joystick.setRxRange(0, 1023);
  //Joystick.setRyRange(0, 1023);
  //Joystick.setRzRange(0, 1023);


  Joystick.begin(false);

}

void loop() {

  //Serial.begin(9600);
  //reduceNoise(A1);
  int sensorA1 = analogRead(A1);
  //reduceNoise(A2);
  int sensorA2 = analogRead(A2);
  //reduceNoise(A3);
  int sensorA3 = analogRead(A3);
  //reduceNoise(A0);
  //int sensorA0 = analogRead(A0);
  
  Joystick.setRxAxis(1023-sensorA3);
  Joystick.setRyAxis(sensorA2);
  Joystick.setRzAxis(sensorA1);
  
  Joystick.sendState();
  delay(20);
  
  //Serial.print(" | A1 XAxisB: ");
  //Serial.print(sensorA1);
  //Serial.print(" | A2 YAxis: ");
  //Serial.print(sensorA2);
  //Serial.print(" | A3 XAxis: ");
  //Serial.println(sensorA3);
  
  

}

void reduceNoise(int pinNum)
{
  // This function reduces the noise in the pot
  // (particoularly effective for the Microstick).
  digitalWrite(pinNum, HIGH);
  delay(5);
  digitalWrite(pinNum, LOW);
  
}
