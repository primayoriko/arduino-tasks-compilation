/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 3.2 change interval with pot value only when button pressed
*/

const int kPinPot = A0;
const int kPinButton = 4;
const int kPinLed = 10;

const int kMininterval = 5;
const int kMaxinterval = 1500;

long lastTime;
int ledState = LOW;
int potVal = 200; // initial value

void setup(){
    pinMode(kPinLed, OUTPUT);
    pinMode(kPinButton, INPUT);
    digitalWrite(kPinButton, HIGH);

    lastTime = millis();
}

void loop(){
    if(digitalRead(kPinButton) == LOW){
        potVal = analogRead(kPinPot);
    }

    if(millis() > lastTime + potVal){
        ledState = !ledState;
        digitalWrite(kPinLed, ledState);
        lastTime = millis();
    }

    delay(3); // give basic interval 3ms between loop
}
