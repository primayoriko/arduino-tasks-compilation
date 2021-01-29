/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 7.4 Hook up the piezo element
        and use it to play a tune after someone knocks.
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

const int kPin_Sensor = A0;
const int kPin_Speaker = 4;

const int k_threshold = 120; 
const int tempo = 250;

void setup() {
  pinMode(kPin_Speaker, OUTPUT);
}

void loop() {
    int val = analogRead(kPin_Sensor);

    if(val >= k_threshold){
        playMusic();
    }
}

void playMusic(){
    for(int i = 0; i < noteNum; i++){
        playTone(notes[i], beats[i] * tempo);
        delay(tempo/2);
    }

    delay(tempo * 4);
}

void playTone(int freq, int duration){
    tone(kPin_Speaker, freq, duration);
    delay(duration);
}