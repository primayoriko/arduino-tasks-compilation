/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 1.3 change sleeptime 500 -> 1000
*/

const int kPinLed = 13;

void setup(){
    pinMode(kPinLed, OUTPUT);
}

void loop(){
    digitalWrite(kPinLed, HIGH);
    delay(500);

    digitalWrite(kPinLed, LOW);
    delay(1000);
}
