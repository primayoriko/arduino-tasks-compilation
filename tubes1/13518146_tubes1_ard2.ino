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

  /* send data to ard1  */
  Serial.write(substractCount);
  substractCount = 0;

  if(!isOpened){
    if (isComeAndCounted){

      /* Read of potentiometer data from ard1  */
      int lastMotorSpeed = motorSpeed;

      motorSpeed = Serial.read();

      // Turn it back to initial value if no data received
      if(motorSpeed == -1){
        motorSpeed = lastMotorSpeed;
      }
      
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
  delay(2000);      
	analogWrite(kPin_Motor, 0); 

}

long readDistanceInCM(int triggerPin, int echoPin)
{
	// Clear the trigger
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return 0.01723 * pulseIn(echoPin, HIGH);
}
