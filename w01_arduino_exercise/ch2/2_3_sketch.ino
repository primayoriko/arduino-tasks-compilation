/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 2.2 5x 1s then 5x 0.5s
*/

const int k_numLEDs = 3;
const int kPinLed[k_numLEDs] = {3, 5, 7};

void setup(){
    for(int i = 0; i < k_numLEDs; i++){
        pinMode(kPinLed[i], OUTPUT);
    }
}

void loop(){
    for(int i = 0; i < k_numLEDs; i++){
        digitalWrite(kPinLed[i], HIGH);
        delay(300);
        digitalWrite(kPinLed[i], LOW);
    }

    // Use this one if the edge light not light up twice in a row
    for(int i = k_numLEDs - 2; i > 0; i--){
        digitalWrite(kPinLed[i], HIGH);
        delay(300);
        digitalWrite(kPinLed[i], LOW);
    }

    // Or use this one if the edge light up twice
    // for(int i = k_numLEDs - 1; i >= 0; i--){
    //     digitalWrite(kPinLed[i], HIGH);
    //     delay(300);
    //     digitalWrite(kPinLed[i], LOW);
    // }
}
