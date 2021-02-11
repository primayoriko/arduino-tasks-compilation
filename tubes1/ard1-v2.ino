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
*/

#include <LiquidCrystal.h>

const int kPin_Temp = A0;
const int kPin_Potentiometer = A5;
const int kPin_Speaker = 7;
const int kPin_Motor = 9;
const int kPin_PIR = 8;

const int kPin_RS = 12;
const int kPin_Enable = 11;
const int kPin_D4 = 5;
const int kPin_D5 = 4;
const int kPin_D6 = 3;
const int kPin_D7 = 2;

byte motorSpeed;
byte substractCount;
int peopleCount;
bool isPersonCome;
float tempC;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(kPin_RS, kPin_Enable, kPin_D4,
            kPin_D5, kPin_D6, kPin_D7);

void setup() {
	peopleCount = 0;
	isPersonCome = false;

	pinMode(kPin_PIR, INPUT);
	pinMode(kPin_Motor, OUTPUT);

	lcd.begin(16, 2);

	Serial.setTimeout(3000);
	Serial.begin(9600);
}

void loop() {
	/* Read Temp Sensor */
	tempC = getTemperatureC();

	/* Beep alarm temp > 37 */
	if(tempC > 37.0){
		ringAlarm();
	}

	/* Read of people change from ard2  */
	byte x = Serial.read();

	/* decrement / no change of people count  */
	if(x == 1){
		peopleCount--;
	}

	/* LCD Display
		lagi dibuka: tidak siap dibuka -> people ++
		people < 10 && temp <= 7  : Siap dibuka
		(people => 10): penuh
	*/
	writeLCD();

	/* Read Motion Sensor */
	if(digitalRead(kPin_PIR) == HIGH){
		isPersonCome = true;
	}

	/* Read potentiometer */
	motorSpeed = analogRead(kPin_Potentiometer);

	/* Send potentiometer data to ard1 */
	Serial.write(motorSpeed);

	/* Move DC motor */
	if(isPersonCome && peopleCount < 10 && tempC <= 37.0){
		writeLCD();

		// Logic of opening door, need to be adjusted
		moveDoor();
		peopleCount++;
		isPersonCome = false;
		
		writeLCD();
	}

//   delay(250);
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

void moveDoor(){
	// open the door
  for(int cnt = 0 ; cnt <= 200; cnt++){
    analogWrite(kPin_Motor, int(motorSpeed)); 
    delay(5);      
  }

  delay(3000);

	// close the door
  for(int cnt = 0 ; cnt <= 200; cnt++){
    analogWrite(kPin_Motor, -1 * int(motorSpeed)); 
    delay(5);      
  }
}

void writeLCD(){
    lcd.setCursor(0, 0);
    if(!isPersonCome){
        if(peopleCount < 10 && tempC <= 37.0){
            lcd.print("siap dibuka");

        }
        else if (peopleCount >= 10){
            lcd.print("penuh"); 

        } else if(tempC > 37.0){
            // Perlu message??
        }
    } else {
        lcd.print("tidak siap dibuka");

    }
    lcd.setCursor(0, 0);
}
