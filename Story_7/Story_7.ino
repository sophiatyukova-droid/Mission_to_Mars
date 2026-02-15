const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;

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

  pinMode(LEFT_FEEDBACK, INPUT_PULLUP);
  pinMode(RIGHT_FEEDBACK, INPUT_PULLUP);
    
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
    
}

void moveForward() {
  
  unsigned long  initialTime = millis();     
  while(millis()-initialTime < 2000)
  {
    analogWrite(Left_Fwd, 250);
    analogWrite(Left_Rev, 0);
    analogWrite(Right_Fwd, 250);
    analogWrite(Right_Rev, 0);
    analogWrite(Left_Enable, 250);  
    analogWrite(Right_Enable, 250);          
  }
}

void loop() {

   int counter=0;
   for(counter=0; counter<3; counter++)
   {
     moveForward();        
     turnLeft();
   }
  moveForward(); 
     
  for(counter=0; counter<3; counter++)
   {
     moveForward();        
     turnRight();
   }
  moveForward(); 
exit(0);
}

void turnLeft()
{
  unsigned long  initialTime = millis();   
  while(millis() - initialTime < 850){  
  
  //left wheel stops  
    analogWrite(Left_Fwd, 0);
    analogWrite(Left_Rev, 0);
    analogWrite(Left_Enable, 0);  
    
    //right wheel rotates
    analogWrite(Right_Fwd, 250);
    analogWrite(Right_Rev, 0);    
    analogWrite(Right_Enable, 250);    
  }
}
void turnRight()
{
  unsigned long  initialTime = millis();   
  while(millis() - initialTime < 850){  
  
  //left wheel rotates  
    analogWrite(Left_Fwd, 250);
    analogWrite(Left_Rev, 0);
    analogWrite(Left_Enable, 250);  
    
    //right wheel stops
    analogWrite(Right_Fwd, 0);
    analogWrite(Right_Rev, 0);    
    analogWrite(Right_Enable, 0);    
  }
}

void LeftMotorISR() {
  leftcounter++;
}
void RightMotorISR(){
  rightcounter++;
}
