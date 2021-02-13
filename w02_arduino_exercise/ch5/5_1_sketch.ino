/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 5.1 creating led that show
        the voltage and temperature (C and F)
*/

/*
  LiquidCrystal Library - Hello World

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

#include <LiquidCrystal.h>

const int kPinTemp = A0;
const int kPinRS = 12;
const int kPinEnable = 11;
const int kPinD4 = 5;
const int kPinD5 = 4;
const int kPinD6 = 3;
const int kPinD7 = 2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(kPinRS, kPinEnable, kPinD4,
            kPinD5, kPinD6, kPinD7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  float temperatureC = getTemperatureC();
  float temperatureF = convertToF(temperatureC);

  lcd.setCursor(0, 0);
  lcd.print(temperatureC);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print(temperatureF);
  lcd.print(" F");

  delay(250);
}

float getTemperatureC(){
    return map(((analogRead(kPinTemp) - 20) * 3.04), 0, 1023, -40, 125);
}

float convertToF(float tempC){
    return (tempC * 9.0 / 5.0) + 32.0;
}
 