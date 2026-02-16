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

  pinMode(LEFT_FEEDBACK, INPUT);
  pinMode(RIGHT_FEEDBACK, INPUT);
    
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
    
}

void moveForward() {
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Left_Rev, LOW);
  digitalWrite(Right_Fwd, HIGH);
  digitalWrite(Right_Rev, LOW);
  analogWrite(Left_Enable, 250);  
  analogWrite(Right_Enable, 250);          
}

void loop() {
  if (leftcounter < TARGET_DISTANCE) {    
    moveForward();        
  } else {
    //stop engine
    analogWrite(Left_Enable, 0);
    analogWrite(Right_Enable, 0);
    exit(0);   
  }

  Serial.print("Current Pulse left Count: ");
  Serial.println(leftcounter);
  Serial.print("Current Pulse right Count: ");
  Serial.println(rightcounter);  
}

void LeftMotorISR() {
  leftcounter++;
}
void RightMotorISR(){
  rightcounter++;
}
