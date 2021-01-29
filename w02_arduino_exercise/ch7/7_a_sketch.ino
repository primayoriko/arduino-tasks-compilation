/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 7.a Light an LED after someone knocks a correct
        pattern (say 3 in a row followed by silence.)
*/

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349

const int noteNum = 6;
const int notes[noteNum] = {
    NOTE_C4, NOTE_C4, NOTE_D4, 
    NOTE_C4, NOTE_F4, NOTE_E4
};

const int beats[noteNum] = {
    1, 1, 2, 2, 2, 4
};

const int kPin_LED = 5;
const int kPin_Sensor = A0;
const int k_threshold = 120;   

void setup() {
  pinMode(kPin_LED, OUTPUT);
}

void loop() {
    if(analogRead(kPin_Reed) == LOW){
        tone(kPin_Speaker, 450);
    } else {
        noTone(kPin_Speaker);
    }
}	