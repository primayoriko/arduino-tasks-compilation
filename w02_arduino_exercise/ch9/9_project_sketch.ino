/*
    13518146 - Naufal Prima Yoriko
    Project - A stopwatch (uses the LCD, push buttons)
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

const int kPinBtn_Stop = 6;
const int kPinBtn_StartPause = 8;
const int kPinRS = 12;
const int kPinEnable = 11;
const int kPinD4 = 5;
const int kPinD5 = 4;
const int kPinD6 = 3;
const int kPinD7 = 2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(kPinRS, kPinEnable, kPinD4,
            kPinD5, kPinD6, kPinD7);

float startTime;
int started, paused;

void setup() {
  Serial.begin(9600);

  pinMode(kPinBtn_StartPause, INPUT);
  pinMode(kPinBtn_Stop, INPUT);

  digitalWrite(kPinBtn_StartPause, HIGH);
  digitalWrite(kPinBtn_Stop, HIGH);

  lcd.begin(16, 2);

  started = 0;
  paused = 0;
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("STOPWATCH ");
  if(started){
    if (paused){
      lcd.print("PAUSE");
      lcd.setCursor(0, 1);
    } else {
      lcd.print("PLAY ");
      lcd.setCursor(0, 1);

      float seconds = (millis() - startTime)/1000;
      int hours = int(seconds)/3600;
      int minutes = (int(seconds)%3600)/60;

      lcd.print(hours);
      lcd.print(":");
      lcd.print(minutes);
      lcd.print(":");
      lcd.print(seconds - 3600 * hours - 60 * minutes);
    }
  } else {
    lcd.print("OFF  ");
  }

  if(digitalRead(kPinBtn_StartPause) == LOW){
    if(started){
      if(paused){
        paused = 0;
      } else {
        paused = 1;
      }
    } else {
      startTime = millis();
      started = 1;
      paused = 0;
    }
    
  }

  if(digitalRead(kPinBtn_Stop) == LOW){
    paused = 0;
    started = 0;
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  delay(50);
}