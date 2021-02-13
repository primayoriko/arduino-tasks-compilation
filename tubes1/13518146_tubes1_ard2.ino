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

byte motorSpeed;
byte substractCount;
bool isPersonCome;

void setup() {
  motorSpeed = 100;
  substractCount = 0;

  pinMode(kPin_PIR, INPUT);
  pinMode(kPin_Motor, OUTPUT);

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
  
  /* Move DC motor */
  moveDoor();
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
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
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