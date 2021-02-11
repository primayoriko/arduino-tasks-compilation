/*
    13518146 - Naufal Prima Yoriko
    TUBES 1 - ARDUINO 2

    TOOLS:
    1. Arduino
    2. Breadboard
    3. Motor DC
    4. PIR Sensor
*/

const int kPin_Motor = 11;
const int kPin_PIR = 2;

byte motorSpeed;
byte substractCount;
bool isPersonCome;

void setup() {
  motorSpeed = 100;
  substractCount = 0;

  Serial.setTimeout(3000);
  Serial.begin(9600);
}

void loop() {
    /* Read Motion Sensor */
    /* send data to ard1 (set true if change detected)  */
    if(digitalRead(kPin_PIR) == HIGH){
      substractCount = 1;
      Serial.write(substractCount);
      substractCount = 0;
    }

    /* Read of potentiometer data from ard1  */
    int lastMotorSpeed = motorSpeed;

    motorSpeed = Serial.read();

    // Turn it back to initial value if no data received
    if(motorSpeed == -1){
      motorSpeed = lastMotorSpeed;
    }
    
    /* Set motor DC speed */

    
    /* Move DC motor */
    openDoor();
}

void openDoor(){

}