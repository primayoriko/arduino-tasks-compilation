/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 2.4 any pattern that different with 2.3
*/

const int k_numLEDs = 3;
const int kPinLed[k_numLEDs] = {3, 5, 7};

void setup(){
    for(int i = 0; i < k_numLEDs; i++){
        pinMode(kPinLed[i], OUTPUT);
    }
}

void loop(){
    // Here I'm implementing cyclon/larson pattern, 
    // but with switching on/off of the odd and even light 
    for(int i = 0; i < k_numLEDs; i++){
        if(i % 2 == 0){
            digitalWrite(kPinLed[i], LOW);
        } else {
            digitalWrite(kPinLed[i], HIGH);
        }

        delay(300);
    }

    for(int i = k_numLEDs - 1; i >= 0; i--){
        if(i % 2 == 0){
            digitalWrite(kPinLed[i], HIGH);
        } else {
            digitalWrite(kPinLed[i], LOW);
        }
        
        delay(300);
    }
}
