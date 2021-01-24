/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 4.3 change exercise 4.1 without tone() and noTone()
*/

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349

const int kPinSpeaker = 2;

const int noteNum = 6;
const int notes[noteNum] = {
    NOTE_C4, NOTE_C4, NOTE_D4, 
    NOTE_C4, NOTE_F4, NOTE_E4
};
const int beats[noteNum] = {
    1, 1, 2, 2, 2, 4
};

const int tempo = 350;

void setup(){
    pinMode(kPinSpeaker, OUTPUT);
}

void loop(){
    for(int i = 0; i < noteNum; i++){
        playTone(notes[i], beats[i] * tempo);
        delay(tempo/2);
    }

    delay(tempo * 4);
}

void playTone(int freq, int duration){
    // TODO : 
    tone(kPinSpeaker, freq, duration);
    delay(duration);
}