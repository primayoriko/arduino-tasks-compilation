/*
    13518146 - Naufal Prima Yoriko
    TUBES 1 - ARDUINO 1

    TOOLS:
    1. Arduino
    2. Breadboard
    3. LCD 16x2
    4. TMP36
    5. Piezo
    6. Potentiometer
    7. Motor DC
    8. PIR Sensor
*/

#include <LiquidCrystal.h>

const int kPin_Temp = A0;
const int kPin_Potentiometer = A5;
const int kPin_Speaker = 7;
const int kPin_Motor = 9;
const int kPin_PIR = 8;

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
    /* Read Temp Sensor */
    /* Beep alarm temp > 37 */
    /* Read Kinetic Sensor */
    /* Read of people change from ard2  */
    /* decrement / no change of people count  */
    /* LCD Display
        lagi dibuka: tidak siap dibuka -> people ++
        people < 10 && temp <= 7  : Siap dibuka
        (people => 10): penuh
    */
    /* Read potentiometer */
    /* Send potentiometer data to ard1 */
    /* Set motor DC speed */
    /* Move DC motor */

//   float temperatureC = getTemperatureC();
//   float temperatureF = convertToF(temperatureC);

//   lcd.setCursor(0, 0);
//   lcd.print(temperatureC);
//   lcd.print(" C");
//   lcd.setCursor(0, 1);
//   lcd.print(temperatureF);
//   lcd.print(" F");

//   delay(250);
}

float getTemperatureC(){
    int reading = analogRead(kPin_Temp);

    float voltage = (reading * 5.0) / 1024;

    return (voltage - 5.0) * 100;
}

float convertToF(float tempC){
    return (tempC * 9.0 / 5.0) + 32.0;
}