/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 1.3 change number 13 -> 2
*/

const int kPinLed = 2;

void setup(){
    pinMode(kPinLed, OUTPUT);
}

void loop(){
    digitalWrite(kPinLed, HIGH);
    delay(500);

    digitalWrite(kPinLed, LOW);
    delay(1000);
}

