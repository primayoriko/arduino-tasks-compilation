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
	10. LED (addition for potentiometer indicator)
*/

#include <LiquidCrystal.h>

const int kPin_Temp36 = A0;
const int kPin_Potentiometer = A5;
const int kPin_LED = 6;
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

/* Needed Const */
const long minDistanceThreshold = 40;
const long maxDistanceThreshold = 190;
const int maxPeopleThreshold = 10;
const float maxTemperatureThreshold = 37.0;

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
	pinMode(kPin_LED, OUTPUT);

	lcd.begin(16, 2);

	Serial.setTimeout(3000);
	Serial.begin(9600);
}

void loop() {
	/* Read of people change from ard2  */
	byte x = 0;
	while(Serial.available()){
		x = Serial.read();

	}

	/* decrement / no change of people count  */
	if(x == 1){

		// Check to avoid negative
		if(peopleCount > 0)
			peopleCount--;

	} 

	/* Read potentiometer */
	motorSpeed = getMotorSpeed();

	/* set LED Light to become indicator by it's brightness */
	setLEDLight(motorSpeed);	

	/* Send potentiometer data to ard1 */
	Serial.write(motorSpeed);

	/* Read Temp Sensor */
	tempC = getTemperatureC();

	/* Beep alarm temp > 37 */
	bool isDangerTemp = tempC > maxTemperatureThreshold;
	
	ringAlarm(isDangerTemp);

	if(isOpened && isDangerTemp){

		/* Close the door */
		isOpened = false;

		writeLCD();

		moveDoor(isOpened, motorSpeed);

	}

	/* Check if there is person come by ultrasonic sensor */
	distance = readDistanceInCM(kPin_Ultrasonic, kPin_Ultrasonic);
	
	if(distance >= minDistanceThreshold && distance <= maxDistanceThreshold && peopleCount < maxPeopleThreshold){
		isCome = true;
	}

	/* Person come and the door just want to be opened */
	if(isCome && !isOpened && peopleCount < maxPeopleThreshold){

		/* Open the door */
		isOpened = true;
		writeLCD();

		moveDoor(isOpened, motorSpeed);

	}
	
	/* When person entering PIR zone and being sign of person entered successfully */
	if(digitalRead(kPin_PIR) == HIGH && isOpened) {

		/* Close the door mechanism */
		isOpened = false;
		isCome = false;

		moveDoor(isOpened, motorSpeed);

		peopleCount++;

	}

	writeLCD();

}

void setLEDLight(int brightness){
	analogWrite(kPin_LED, brightness);
}

float getTemperatureC(){
	return map(((analogRead(kPin_Temp36) - 20) * 3.04), 0, 1023, -40, 125);
}

float getMotorSpeed(){
	return map(analogRead(kPin_Potentiometer), 0, 1023, 30, 250);
}

// Try to change to non-blocking
void ringAlarm(bool trigger){
	noTone(kPin_Speaker);
	if(trigger){
		for(int i = 450; i < 5000; i = i * 2 - i / 2){
			tone(kPin_Speaker, 450);
			delay(35);
		}

		delay(250);
		noTone(kPin_Speaker);
	}
}

void moveDoor(bool moveForward, int motorSpeed){
	/* Set time based on speed */
	int delayTime = 250 * 125 / (motorSpeed / 2);

	/* Control door move direction */
	if(!moveForward){
		// Some method if there is special mechanism of DC Motor when closing door

	}

	analogWrite(kPin_Motor, int(motorSpeed)); 
	delay(300);      
	analogWrite(kPin_Motor, 0); 

}

/* LCD Display
	lagi dibuka: tidak siap dibuka -> people ++
	people < 10 && temp <= 37  : Siap dibuka
	(people => 10): penuh
*/
void writeLCD(){
	lcd.setCursor(0, 0);
	if(!isOpened){
		if(peopleCount < maxPeopleThreshold && tempC <= maxTemperatureThreshold){
			lcd.print("siap dibuka       ");

		}
		else if (peopleCount >= maxPeopleThreshold){
			lcd.print("penuh            "); 

		} else if(tempC > maxTemperatureThreshold){
			// Perlu message??
		}
	} else {
		lcd.print("tidak siap dibuka");

	}
	lcd.setCursor(0, 1);
	lcd.print("cnt:");
	lcd.print(peopleCount);
	lcd.print("/10;");
	lcd.print("T:");
	lcd.print(tempC);
	lcd.print("C  ");
	lcd.setCursor(0, 0);
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
