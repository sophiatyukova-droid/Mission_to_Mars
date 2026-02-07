const int RED_LED =12;
const int GREEN_LED =11;
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop()
{
  digitalWrite(RED_LED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(RED_LED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(GREEN_LED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(GREEN_LED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
