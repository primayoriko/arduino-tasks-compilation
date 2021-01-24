/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 3.3 RGB button with 'from' and 'to' color to store val, 
                and when neither pressed LED will fade smoothly
*/

const int kMinDelay = 5;
const int kMaxDelay = 1500;
const int kPinLed = 2;
const int kPinButton = 4;
const int kPinPot = A0;

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

    delay(3); // give basic delay 3ms between loop
}

