const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;
void setup()
{
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd, OUTPUT);
  pinMode(Left_Enable, OUTPUT);
  pinMode(Right_Enable, OUTPUT);
  pinMode(Right_Rev, OUTPUT);
  pinMode(Right_Fwd, OUTPUT);
}
void forward()
{
digitalWrite(Left_Rev, LOW);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Right_Rev, LOW);
  digitalWrite(Right_Fwd, HIGH);
}
void stop()
{
   digitalWrite(Left_Rev, LOW);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Left_Enable, LOW);
  digitalWrite(Right_Enable, LOW);
  digitalWrite(Right_Rev, LOW);
  digitalWrite(Right_Fwd, LOW);
}
void reverse()
{
   digitalWrite(Left_Rev, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Right_Rev, HIGH);
  digitalWrite(Right_Fwd, LOW);
}


void loop()
{
 forward();
  delay(5000);
  stop();
  delay(1000);
  reverse();
  delay(2000);
}
