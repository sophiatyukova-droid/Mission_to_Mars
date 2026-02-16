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
  Serial.begin(115200);
  int distance =sonar.ping_cm(); 
}

void loop() {
  delay(50);                     
  int distance = sonar.ping_cm(); 
    
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  
  if (distance > 0 && distance < 12) {
     stopRover();
     delay(1000); 
     moveback();
     turnLeft(); //by 90 degrees
     moveforward();
  }
}

void stopRover() { 
  Serial.println("OBSTACLE DETECTED: STOPPING!");
  analogWrite(Left_Enable, 0);  
  analogWrite(Right_Enable, 0); 
}

void moveback() { 
  {
    digitalWrite(Left_Fwd, LOW);
    digitalWrite(Left_Rev, HIGH);
    digitalWrite(Right_Fwd, LOW);
    digitalWrite(Right_Rev, HIGH);
    analogWrite(Left_Enable, 250);  
    analogWrite(Right_Enable, 250);    
  }
}

void turnLeft() { 
  //turn left by 90 degrees
  unsigned long initialTime = millis();   
  while(millis() - initialTime < 850){  
  
  //left wheel stops  
    digitalWrite(Left_Fwd, LOW);
    digitalWrite(Left_Rev, LOW);
    analogWrite(Left_Enable, 0);  
    
    //right wheel rotates
    digitalWrite(Right_Fwd, HIGH);
    digitalWrite(Right_Rev, LOW);    
    analogWrite(Right_Enable, 250);    
  }
}

void moveforward() { 
  //move forward for 2 sconds
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
