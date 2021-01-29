/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 7.2 Hook up a Tilt Sensor and the speaker. Have activating of the tilt sensor
            make an alarm go off.
*/

const int kPin_Tilt = 5;    
const int kPin_Speaker = 10;        

void setup() {
  pinMode(kPin_Tilt, INPUT);
  pinMode(kPin_Speaker, OUTPUT);

  digitalWrite(kPin_Tilt, HIGH);
}

void loop() {
    if(digitalRead(kPin_Tilt) == LOW){
        ringAlarm();
    }
}	

void ringAlarm(){
    for(int i = 450; i < 5000; i = i * 2){
        tone(kPin_Speaker, 450);
        delay(10);
    }
    noTone(kPin_Speaker);
}