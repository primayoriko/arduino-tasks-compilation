/*
    13518146 - Naufal Prima Yoriko
    EXERCISE 3.4 count duration between first and last command in a loop
*/

void setup(){
    // If you need any setup
}

void loop(){
    long startTime = micros();
    /* type your own code here
    :
    :
    your code */
    Serial.print ("time in uS: ");
    Serial.println (micros() - startTime);
    delay (2000); // delay to avoid burst of print to your console
}