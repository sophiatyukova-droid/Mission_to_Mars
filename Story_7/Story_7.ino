const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;

unsigned long currentTime;

const int RIGHT_FEEDBACK = 2; 
const int LEFT_FEEDBACK = 3;

volatile int leftcounter = 0;
volatile int rightcounter = 0;

const int TARGET_DISTANCE = 870;

void setup()
{
  pinMode(Left_Rev, OUTPUT);      
  pinMode(Left_Fwd, OUTPUT);
  pinMode(Left_Enable, OUTPUT);
  pinMode(Right_Enable, OUTPUT);
  pinMode(Right_Fwd, OUTPUT);
  pinMode(Right_Rev, OUTPUT);

  pinMode(LEFT_FEEDBACK, INPUT);
  pinMode(RIGHT_FEEDBACK, INPUT);
    
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
    
}

void loop() {
  
   int counter=0;
   for(counter=0; counter<4; counter++)
   {
     moveForward();        
     turnLeft();
   }
       
  for(counter=0; counter<4; counter++)
   {
     moveForward();        
     turnRight();
   }
  
  exit(0);
}


void moveForward() {
  
  unsigned long  initialTime = millis();     
  while(millis()-initialTime < 2000)
  {
    digitalWrite(Left_Fwd, HIGH);
    digitalWrite(Left_Rev, LOW);
    digitalWrite(Right_Fwd, HIGH);
    digitalWrite(Right_Rev, LOW);
    analogWrite(Left_Enable, 250);  
    analogWrite(Right_Enable, 250);          
  }
}


void turnLeft()
{
  unsigned long  initialTime = millis();   
  while(millis() - initialTime < 850){  
  
  //left wheel stops  
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Left_Rev, LOW);
  analogWrite(Left_Enable, 250);  
  
  //right wheel rotates
  digitalWrite(Right_Fwd, HIGH);
  digitalWrite(Right_Rev, LOW);    
  analogWrite(Right_Enable, 250);    
  }
}
void turnRight()
{
  unsigned long  initialTime = millis();   
  while(millis() - initialTime < 850){  
  
  //left wheel rotates  
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Left_Rev, LOW);
  analogWrite(Left_Enable, 250);  
  
  //right wheel stops
  digitalWrite(Right_Fwd, LOW);
  digitalWrite(Right_Rev, LOW);    
  analogWrite(Right_Enable, 0);    
  }
}

void LeftMotorISR() {
  leftcounter++;
}
void RightMotorISR(){
  rightcounter++;
}
