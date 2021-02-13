/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 5.3 creating led that show
        max, min, and curr temperature in F with it's time
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

float maxTempF = -1e4;
float minTempF = 1e5;
long timeMin, timeMax;

int cnt = 0;

void loop() {
    float voltage = getVoltage();
    float temperatureC = getTemperatureC();
    float temperatureF = convertToF(temperatureC);

    // Using equality sign to show time of nearest value
    if(maxTempF <= temperatureF){
        maxTempF = temperatureF;
        timeMax = millis();
    }

    if(minTempF >= temperatureF){
        minTempF = temperatureF;
        timeMin = millis();
    }
    
    // Alter row 1 between max and min value
    lcd.setCursor(0, 0);
    if(cnt){
        lcd.print("max ");
        lcd.print(maxTempF);
        lcd.print("(");
        lcd.print(int((millis() - timeMax)/1000));
        lcd.print("s)");
    } else {
        lcd.print("min ");
        lcd.print(minTempF);
                lcd.print("(");
        lcd.print(int((millis() - timeMin)/1000));
        lcd.print("s)");
    }
    lcd.print(" F");
    cnt = (cnt + 1 ) % 2;

    lcd.setCursor(0, 1);
    lcd.print("curr ");
    lcd.print(temperatureF);
    lcd.print(" F");

    delay(600);
}

float getVoltage(){
    return (analogRead(kPinTemp) * 5.0)/1024;
}

float getTemperatureC(){
    return map(((analogRead(kPinTemp) - 20) * 3.04), 0, 1023, -40, 125);
}

float convertToF(float tempC){
    return (tempC * 9.0 / 5.0) + 32.0;
}
 