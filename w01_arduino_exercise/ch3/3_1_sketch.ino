/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 3.1 change delay with gas-brake button
*/

const int kMinDelay = 10;
const int kMaxDelay = 1500;
const int kPinLed = 2;
const int kPinBtnBrake = 4;
const int kPinBtnGas = 5;

long lastTime;
int delay = 200;
int ledState = LOW;

void setup(){
    pinMode(kPinLed, OUTPUT);
    pinMode(kPinBtnBrake, INPUT);
    pinMode(kPinBtnGas, INPUT);

    digitalWrite(kPinBtnBrake, HIGH);
    digitalWrite(kPinBtnGas, HIGH);

    lastTime = millis();
}

void loop(){
    if(digitalRead(kPinBtnBrake) == LOW){
        delay--;
    }
    if(digitalRead(kPinBtnGas) == LOW){
        delay++;
    }

    delay = adjustValue(delay, kMinDelay, kMaxDelay);
    if(millis() > lastTime + delay){
        ledState = !ledState;
        digitalWrite(kPinLed, ledState);
        lastTime = millis();
    }

    delay(3); // give basic delay 3ms between loop
}

int adjustValue(int val, int mini, int maks){
    if (val > maks){
        val = maks;
    } else if (val < mini){
        val = mini;
    }

    return val;
}

