/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 3.3 RGB button with 'from' and 'to' color to store val, 
                and when neither pressed LED will change from 'from'
                to 'to' range, vice-versa
*/

const int kPinPot_R = A0;
const int kPinPot_G = A1;
const int kPinPot_B = A2;

const int kPinLed_R = 4;
const int kPinLed_G = 2;
const int kPinLed_B = 3;

const int kPinBtnFrom = 7;
const int kPinBtnTo = 8;

int from_R = 0;
int from_G = 0;
int from_B = 0;
int to_R = 255;
int to_G = 255;
int to_B = 255;

int now = 0;
int change = 1;

void setup(){
    pinMode(kPinLed_R, OUTPUT);
    pinMode(kPinLed_G, OUTPUT);
    pinMode(kPinLed_B, OUTPUT);
    pinMode(kPinBtnFrom, INPUT);
    pinMode(kPinBtnTo, INPUT);

    digitalWrite(kPinBtnFrom, HIGH);
    digitalWrite(kPinBtnTo, HIGH);

}

void loop(){
    if(digitalRead(kPinBtnFrom) == LOW){
        from_R = analogRead(kPinPot_R);
        from_G = analogRead(kPinPot_G);
        from_B = analogRead(kPinPot_B);
    } else if(digitalRead(kPinBtnTo) == LOW){
        to_R = analogRead(kPinPot_R);
        to_G = analogRead(kPinPot_G);
        to_B = analogRead(kPinPot_B);
    } else {
        now += change;
        if(now > 255){
            now = 255;
            change = -1;
        } else if (now < 0){
            now = 0;
            change = 1;
        }

        int ledValue = map(now, 0, 255, from_R, to_R);
        digitalWrite(kPinLed_R, ledValue);

        ledValue = map(now, 0, 255, from_G, to_G);
        digitalWrite(kPinLed_G, ledValue);

        ledValue = map(now, 0, 255, from_B, to_B);
        digitalWrite(kPinLed_B, ledValue);

        delay(5);
    }
}
