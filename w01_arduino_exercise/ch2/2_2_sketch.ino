/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 2.2 5x 1s & 5x 0.5s
*/

const int kPinLed = 2;

void setup(){
    pinMode(kPinLed, OUTPUT);
}

void loop(){
    for(int i = 0; i < 5; i++){
        digitalWrite(kPinLed, HIGH);
        delay(1000);

        digitalWrite(kPinLed, LOW);
        delay(1000);
    }
    for(int i = 0; i < 5; i++){
        digitalWrite(kPinLed, HIGH);
        delay(500);

        digitalWrite(kPinLed, LOW);
        delay(500);
    }
}

