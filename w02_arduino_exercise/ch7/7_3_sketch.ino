/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 7.3 Use the reed switch and the magnet 
            to make a sound when the magnet is close.
*/

const int kPin_Reed = 5;    
const int kPin_Speaker = 10;        

void setup() {
  pinMode(kPin_Reed, INPUT);
  pinMode(kPin_Speaker, OUTPUT);

  digitalWrite(kPin_Reed, HIGH);
}

void loop() {
    if(digitalRead(kPin_Reed) == LOW){
        tone(kPin_Speaker, 450);
    } else {
        noTone(kPin_Speaker);
    }
}