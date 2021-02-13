/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 7.1 make LED that it's brightness will
        adjust to the environment using photoresistor
*/

const int kPin_Photocell = A0;    
const int kPin_LED = 9;        

const int sensorMin = 0;        
const int sensorMax = 1023;

int sensorValue = 0;

void setup() {
  pinMode(kPin_LED, OUTPUT);
}

void loop() {
  sensorValue = analogRead(kPin_Photocell);

  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  sensorValue = constrain(sensorValue, 0, 255);

  analogWrite(kPin_LED, sensorValue);

  delay(150);
}	