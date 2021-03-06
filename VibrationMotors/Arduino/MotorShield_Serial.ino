//
// MotorShield_Serial
//
// Simple test of the serial communication protocol joined with the
// Adafruit MotorShield v1.
// The protocol sends a command, which indicates which motor
// to run, a byte with the motor speed, and an end marker (\n)
//
// Giovanni Medici 2020
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

#include <AFMotor.h>

AF_DCMotor motor1(1); // SX Rest
AF_DCMotor motor2(2); // DX Rest
AF_DCMotor motor3(3); // SX Seat Top Bottom
AF_DCMotor motor4(4); // DX Seat Top Bottom


const byte numChars = 2;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;
boolean motorReady = false;
int dataNumber = 0;             // new for this version




void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("<Arduino is ready>");
  Serial.println("Motor test!");

  // turn on motor
  motor4.setSpeed(200);

  motor4.run(RELEASE);
}

void loop() {
  recvWithEndMarker();
  //showNewNumber();
}



void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  if (Serial.available() > 0) {
    motorReady = true;
    rc = Serial.read();

    if (rc != endMarker) {
      //receivedChars[ndx] = rc;
      ndx++;
      if (ndx == 1)
      {
        // First character is the command
        parseCommand(rc);
      }
      if (ndx == 2)
      {
        parseSpeed(rc);
      }
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
  else
  {
    //checkMotors();

  }
}

void showNewNumber() {
  if (newData == true) {
    dataNumber = 0;             // new for this version
    dataNumber = atoi(receivedChars);   // new for this version
    Serial.print("This just in ... ");
    Serial.println(receivedChars);
    Serial.print("Data as Number ... ");    // new for this version
    Serial.println(dataNumber);     // new for this version
    newData = false;
  }
}

void checkMotors() {
  // This function checks the value of motorReady
  // if true (any motor was running) but no new serial is available
  // it will shut down the motors and set the flag to false.

  if (motorReady)
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    motorReady = false;
  }
}


byte parseCommand(byte rc)
// This function parses the rc input (to determine which motor(s)
// to start
{
  //
  switch (rc)
  {
    case '`':
      // Releases all the motors
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      break;

    case 'a':
      // Motor 1 on
      motor1.run(FORWARD);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      break;

    case 'b':
      motor2.run(FORWARD);
      motor1.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      break;

    case 'c':
      motor3.run(FORWARD);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor4.run(RELEASE);
      break;

    case 'd':
      motor4.run(FORWARD);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      break;

    case 'g':
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      break;

    case 'h':
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      break;

    case 'k':
      motor1.run(FORWARD);
      motor3.run(FORWARD);

      motor2.run(RELEASE);
      motor4.run(RELEASE);
      break;

    case 'i':
      motor2.run(FORWARD);
      motor4.run(FORWARD);

      motor1.run(RELEASE);
      motor3.run(RELEASE);
      break;

    case 'l':
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      break;
    case 'm':
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      break;

  }

  /*
    if (rc == 'a')
    {
    // Motor 1 on
    motor1.run(FORWARD);

    }
    if (rc == 'b')
    {
    motor2.run(FORWARD);
    }
    if (rc == 'c')
    {
    // Motor 4 on
    motor3.run(FORWARD);

    }
    if (rc == 'd')
    {
     motor4.run(FORWARD);
    }
    if (rc == 'g')
    {
       motor1.run(FORWARD);
       motor2.run(FORWARD);
    }

    if (rc == '`')
    {
    // Releases all the motors
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);

    }
  */
}


byte parseSpeed(byte rc)
// This function parses the rc input (to determine the motors
// speed
{
  //
  // Motor 4 on
  uint8_t motSpeed;
  motSpeed = rc;
  motor1.setSpeed(motSpeed);
  motor2.setSpeed(motSpeed);
  motor3.setSpeed(motSpeed);
  motor4.setSpeed(motSpeed);
  if (motSpeed < 10)
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }



}
