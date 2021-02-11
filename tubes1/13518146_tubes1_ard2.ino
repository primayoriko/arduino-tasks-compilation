/*
    13518146 - Naufal Prima Yoriko
    TUBES 1 - ARDUINO 2

    TOOLS:
    1. Arduino
    2. Breadboard
    3. Motor DC
    4. PIR Sensor
*/

#include <LiquidCrystal.h>

const int kPin_Motor = 11;
const int kPin_PIR = 2;

byte motorSpeed;
byte substractCount;

void setup() {
  motorSpeed = 100;

  Serial.begin(9600);
}

void loop() {
    /* Read Motion Sensor */
    if(){

    }

    /* Read of potentiometer data from ard1  */
    int lastMotorSpeed = motorSpeed;

    motorSpeed = Serial.read();
    if(motorSpeed == -1){
      motorSpeed = lastMotorSpeed;
    }
    
    /* Set motor DC speed */
    
    /* send data to ard1 (set true if change detected)  */
    if(){
      Serial.write(substractCount);
      substractCount = 0;
    }
    
    /* Move DC motor */
    openDoor();
}

void OpenDoor(){

}