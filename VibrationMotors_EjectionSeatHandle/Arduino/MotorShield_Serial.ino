// Simple test of the serial communication protocol joined with the
// Adafruit MotorShield v1.
// The protocol sends a command, which indicates which motor
// to run, a byte with the motor speed, and an end marker (\n)
//
// Giovanni Medici 2020
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Keyboard.h>

AF_DCMotor motor1(1); // SX Rest
AF_DCMotor motor2(2); // DX Rest
AF_DCMotor motor3(3); // SX Seat Top Bottom
AF_DCMotor motor4(4); // DX Seat Top Bottom


bool isEjecting = 0;  // Boolean to check whether the Ejection Handle has been pulled 

const byte numChars = 2;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;
boolean motorReady = false;
boolean doPrint = false;



void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  

   // turn on motor
   motor4.setSpeed(200);

   motor4.run(RELEASE);
   pinMode(2, INPUT_PULLUP); 
   Keyboard.begin();
}

void loop() {
  // Vibration Motors
  recvWithEndMarker();
  // Ejection Handle
  checkHandle();

}

// This function deals with the Ejection Seat Handle
void checkHandle() {
  if ( (isEjecting == 0) && (digitalRead(2) == LOW) )
 {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('e');
  if (doPrint)
  {
    Serial.println("EJECTING");
  }
  delay(2);
  isEjecting = 1;
  
}
if ( (isEjecting == 1) && (digitalRead(2) == HIGH) )
 {
  // Release all when was ejecting and released the lever
  Keyboard.releaseAll();
  if (doPrint)
  {
    Serial.println("END EJECTING");
  }
  delay(2);
  isEjecting = 0;
  
}
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
