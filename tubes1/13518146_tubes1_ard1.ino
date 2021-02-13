/*
	13518146 - Naufal Prima Yoriko
	TUBES 1 - ARDUINO 1

	TOOLS:
	1. Arduino
	2. Breadboard
	3. LCD 16x2
	4. TMP36
	5. Piezo
	6. Potentiometer
	7. Motor DC
	8. PIR Sensor
	9. Ultrasonic Distance Sensor
*/

#include <LiquidCrystal.h>

const int kPin_Temp = A0;
const int kPin_Potentiometer = A5;
const int kPin_Speaker = 7;
const int kPin_Motor = 9;
const int kPin_PIR = 8;
const int kPin_Ultrasonic = 13;

/* LCD Pins */
const int kPin_RS = 12;
const int kPin_Enable = 11;
const int kPin_D4 = 5;
const int kPin_D5 = 4;
const int kPin_D6 = 3;
const int kPin_D7 = 2;

/* Global vars */
int distance;
bool isOpened;
bool isCome;
byte motorSpeed;
int peopleCount;
byte substractCount;
float tempC;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(kPin_RS, kPin_Enable, kPin_D4,
            kPin_D5, kPin_D6, kPin_D7);

void setup() {
	peopleCount = 0;
	isOpened = false;
	isCome = false;

	pinMode(kPin_PIR, INPUT);
	pinMode(kPin_Motor, OUTPUT);

	lcd.begin(16, 2);

	Serial.setTimeout(3000);
	Serial.begin(9600);
}

void loop() {
	/* Read of people change from ard2  */
	byte x = Serial.read();

	/* decrement / no change of people count  */
	if(x == 1){
		peopleCount--;
	}

	/* Read Temp Sensor */
	tempC = getTemperatureC();

	/* Read potentiometer */
	motorSpeed = getMotorSpeed();

	/* Send potentiometer data to ard1 */
	Serial.write(motorSpeed);

	/* Beep alarm temp > 37 */
	if(tempC > 37.0){

		ringAlarm();

		if(isOpened){

			/* Close the door */
			isOpened = false;
			writeLCD();

			moveDoor(isOpened);

		}

	} else {

		/* Check if there is person come by ultrasonic sensor */
		distance = readDistanceInCM(kPin_Ultrasonic, kPin_Ultrasonic);
		if(distance > 40 && distance < 190){
			isCome = true;
		}

		/* Person come and the door just want to be opened */
		if(isCome && !isOpened && peopleCount < 10){

			/* Open the door */
			isOpened = true;
			writeLCD();

			moveDoor(isOpened);

		}
		
		if(digitalRead(kPin_PIR) == HIGH && isOpened) { /* Condition where people already enter the room / enter PIR zone */

			isOpened = false;
			isCome = false;

			moveDoor(isOpened);

			peopleCount++;

		}
	}

	writeLCD();

}

float getTemperatureC(){
	return map(((analogRead(kPin_Temp) - 20) * 3.04), 0, 1023, -40, 125);
}

float getMotorSpeed(){
	return map(analogRead(kPin_PIR), 0, 1023, 30, 250);
}

// Try to change to non-blocking
void ringAlarm(){
	for(int i = 450; i < 15000; i = i * 2 - i / 2){
		tone(kPin_Speaker, 450);
		delay(35);
	}
	delay(1000);
	noTone(kPin_Speaker);
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

/* LCD Display
	lagi dibuka: tidak siap dibuka -> people ++
	people < 10 && temp <= 7  : Siap dibuka
	(people => 10): penuh
*/
void writeLCD(){
	lcd.setCursor(0, 0);
	if(!isOpened){
			if(peopleCount < 10 && tempC <= 37.0){
					lcd.print("siap dibuka       ");

			}
			else if (peopleCount >= 10){
					lcd.print("penuh          "); 

			} else if(tempC > 37.0){
					// Perlu message??
			}
	} else {
			lcd.print("tidak siap dibuka");

	}
	lcd.setCursor(0, 1);
	lcd.print("cnt: ");
	lcd.print(peopleCount);
	lcd.print("/10 ");
	lcd.setCursor(0, 0);
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
