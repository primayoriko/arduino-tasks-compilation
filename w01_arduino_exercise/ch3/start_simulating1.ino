int A = 0;

void setup()
{
  pinMode(2, OUTPUT);
}

void loop()
{
  while (1 == 1) {
    digitalWrite(2, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(2, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}