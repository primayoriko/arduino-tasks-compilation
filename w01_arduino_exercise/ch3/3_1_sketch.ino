/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 3.1 change interval with gas-brake button
*/

const int kMinInterval = 10;
const int kMaxInterval = 1500;
const int kPinBtnBrake = 4;
const int kPinBtnGas = 5;
const int kPinLed = 10;

long lastTime;
int interval = 200;
auto ledState = LOW;

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
        interval++;
    }
    if(digitalRead(kPinBtnGas) == LOW){
        interval--;
    }

    interval = adjustValue(interval, kMinInterval, kMaxInterval);
    if(millis() > lastTime + interval){
        ledState = !ledState;
        digitalWrite(kPinLed, ledState);
        lastTime = millis();
    }

    delay(10); // give basic interval 3ms between loop
}

int adjustValue(int val, int mini, int maks){
    if (val > maks){
        val = maks;
    } else if (val < mini){
        val = mini;
    }

    return val;
}
