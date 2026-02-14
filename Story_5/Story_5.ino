const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;

unsigned long currentTime;

void setup()
{
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd, OUTPUT);
  pinMode(Left_Enable, OUTPUT);
  pinMode(Right_Enable, OUTPUT);
  pinMode(Right_Fwd, OUTPUT);
  pinMode(Right_Rev, OUTPUT);

digitalWrite(Left_Rev, LOW);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Rev, LOW);
  digitalWrite(Right_Fwd, HIGH);
  
  currentTime = millis();
}

void forward()
{
digitalWrite(Left_Rev, LOW);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Rev, LOW);
  digitalWrite(Right_Fwd, HIGH);
  analogWrite(Left_Enable, 200);
  analogWrite(Right_Enable, 200);
}
void left_forward()
{
digitalWrite(Left_Rev, LOW);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Rev, LOW);
  digitalWrite(Right_Fwd, HIGH);
  analogWrite(Left_Enable, 140);
  analogWrite(Right_Enable, 200);
}
void right_forward()
{
digitalWrite(Left_Rev, LOW);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Rev, LOW);
  digitalWrite(Right_Fwd, HIGH);
  analogWrite(Left_Enable, 200);
  analogWrite(Right_Enable, 140);
}
void stop()
{
  analogWrite(Left_Enable, 0);
  analogWrite(Right_Enable, 0);
}
void loop(){
  unsigned long elapsed = millis()-currentTime;
  
  if(elapsed <= 10000){
    if (elapsed < 2000){
      forward();      
    }
    else if (elapsed < 4000){
      left_forward();
    }
    else if (elapsed < 6000){
      right_forward();
    }
    else if (elapsed < 8000) {
      left_forward();
    }
    else {     
      right_forward();
       }
     } 
  else {
      stop();
       }
  }
