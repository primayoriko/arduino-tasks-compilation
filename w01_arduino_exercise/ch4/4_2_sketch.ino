/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 4.2 
*/

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349

const int kPinSpeaker = 4;
const int kPinBtn1 = 8;
const int kPinBtn2 = 10;

const int noteNum1 = 6;
const int noteNum2 = 12;

const int notes1[noteNum1] = {
    NOTE_C4, NOTE_C4, NOTE_D4, 
    NOTE_C4, NOTE_F4, NOTE_E4
};
const int notes2[noteNum2] = {
    NOTE_F4, NOTE_C4, NOTE_D4, 
    NOTE_D4, NOTE_F4, NOTE_E4,
    NOTE_D4, NOTE_C4, NOTE_F4, 
    NOTE_E4, NOTE_C4, NOTE_C4
};

const int beats1[noteNum1] = {
    1, 1, 2, 2, 2, 4
};

const int beats2[noteNum2] = {
    2, 3, 2, 1, 1, 4,
    2, 3, 2, 1, 1, 4
};

const int tempo = 250;

void setup(){
    pinMode(kPinSpeaker, OUTPUT);
    pinMode(kPinBtn1, INPUT);
    pinMode(kPinBtn2, INPUT);

    digitalWrite(kPinBtn1, HIGH);
    digitalWrite(kPinBtn2, HIGH);
}

void loop(){
    if(digitalRead(kPinBtn1) == LOW){
        playMusic1();
    } 
    if(digitalRead(kPinBtn2) == LOW){
        playMusic2();
    }
}

void playMusic1(){
    for(int i = 0; i < noteNum1; i++){
        playTone(notes1[i], beats1[i] * tempo);
        delay(tempo/2);
    }

    delay(tempo * 4);
}

void playMusic2(){
    for(int i = 0; i < noteNum2; i++){
        playTone(notes2[i], beats2[i] * tempo);
        delay(tempo/2);
    }

    delay(tempo * 4);
}

void playTone(int freq, int duration){
    tone(kPinSpeaker, freq, duration);
    delay(duration);
}