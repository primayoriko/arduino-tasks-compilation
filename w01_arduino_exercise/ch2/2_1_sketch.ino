/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 2.1 change loop 4 -> 10
*/

const int kPinLed = 13;

void setup(){
    pinMode(kPinLed, OUTPUT);
}

void loop(){
    for(int i = 0; i < 10; i++){
        digitalWrite(kPinLed, HIGH);
        delay(200);

        digitalWrite(kPinLed, LOW);
        delay(200);
    }
    delay(1000);
}
