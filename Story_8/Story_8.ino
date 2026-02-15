#include <NewPing.h>


#define TRIGGER_PIN  4
#define ECHO_PIN     5
#define MAX_DISTANCE 200 


const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;


const int TRIGGER_DOWN = 13;
const int ECHO_DOWN = 17;


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
    
  delay(50); 
  sonar.ping_cm(); 
}

void loop() {
  delay(50);                     
  int distance = sonar.ping_cm(); 
    
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  
  if (distance > 0 && distance < 12) {
     stopRover(); 
     moveback();
     turnLeft(); //by 90 degrees
     moveforward();
  }
}

void stopRover() { 
  Serial.println("OBSTACLE DETECTED: STOPPING!");
}

void moveback() { 
    unsigned long  initialTime = millis();     
  while(millis()-initialTime < 1000)
  {
    analogWrite(Left_Fwd, 0);
    analogWrite(Left_Rev, 250);
    analogWrite(Right_Fwd, 0);
    analogWrite(Right_Rev, 250);
    analogWrite(Left_Enable, 250);  
    analogWrite(Right_Enable, 250);    
  }
}

void turnLeft() { 
  //turn left by 90 degrees
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


void moveforward() { 
  //move forward for 2 sconds
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
