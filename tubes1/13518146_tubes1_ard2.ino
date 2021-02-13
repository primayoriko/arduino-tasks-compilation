/*
  13518146 - Naufal Prima Yoriko
  TUBES 1 - ARDUINO 2

  TOOLS:
  1. Arduino
  2. Breadboard
  3. Motor DC
  4. PIR Sensor
	5. Ultrasonic Distance Sensor
*/

const int kPin_Motor = 11;
const int kPin_PIR = 4;

bool isOpened;
bool isComeAndCounted;
byte motorSpeed;
byte substractCount;

void setup() {
  motorSpeed = 100;
  substractCount = 0;
  isComeAndCounted = false;

  pinMode(kPin_PIR, INPUT);
  pinMode(kPin_Motor, OUTPUT);

  Serial.setTimeout(3000);
  Serial.begin(9600);
}

void loop() {
  /* Read Motion Sensor */
  if(digitalRead(kPin_PIR) == HIGH && !isComeAndCounted){

    /* set to true if change detected */
    substractCount = 1;
    isComeAndCounted = true;
    
  } else if(digitalRead(kPin_PIR) == LOW){

    isComeAndCounted = false;

  }

   /* Read of potentiometer data from ard1  */
  int lastMotorSpeed = motorSpeed;

  while(Serial.available()){
		motorSpeed = Serial.read();
    Serial.print(motorSpeed);
    Serial.print("\n");
	}

  // Turn it back to initial value if no data received
  if(motorSpeed == -1){
    motorSpeed = lastMotorSpeed;
  }

  /* send data to ard1  */
  Serial.write(substractCount);
  substractCount = 0;

  if(!isOpened){
    if (isComeAndCounted){

      /* Move DC motor */
      isOpened = true;

      moveDoor(isOpened);

    } 

  } else if(!isComeAndCounted) {

    /* Move DC motor */
    isOpened = false;
    isComeAndCounted = false;

    moveDoor(isOpened);
  
  }

}

void moveDoor(bool moveForward){
	/* Control door move direction */
	if(!moveForward){
		// Some method

	}

	analogWrite(kPin_Motor, int(motorSpeed)); 
  delay(300);      
	analogWrite(kPin_Motor, 0); 

}
