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

const int kPin_RS = 12;
const int kPin_Enable = 11;
const int kPin_D4 = 5;
const int kPin_D5 = 4;
const int kPin_D6 = 3;
const int kPin_D7 = 2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(kPin_RS, kPin_Enable, kPin_D4,
            kPin_D5, kPin_D6, kPin_D7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
    /* Read of potentiometer data from ard1  */
    /* Set motor DC speed */
    /* Read Kinetic Sensor */
    /* send data to ard1 (set true if change detected)  */
    /* Move DC motor */
}