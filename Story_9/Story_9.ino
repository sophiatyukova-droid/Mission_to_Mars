#include <NewPing.h>


#define TRIGGER_PIN  4
#define ECHO_PIN     5
#define MAX_DISTANCE 200 
#define TRIGGER_DOWN 13
#define ECHO_DOWN 17


const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonarDown(TRIGGER_DOWN, ECHO_DOWN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  delay(50); 
  
  int distance = sonar.ping_cm(); 
  int floorDistance = sonarDown.ping_cm(); 
}

void loop() {
  delay(50);     
  int floorDistance = sonarDown.ping_cm();
  
  //Detect drop over 12cm, stop, reverse 0.5s, remain stopped
  if (floorDistance > 5) {
      stopRover();
      Serial.println("Warning: No ground detected!");
     
      if (floorDistance > 12) {
        Serial.println("Drop over 12cm");
         stopRover(); 
         moveback();
         delay(500);
         stopRover();
         while(true); //remains stopped
      }
      return;
      }

  //If ground is detected within 5cm, move forward
  moveforward_continuous();
                       
  Serial.print("Distance: ");
  Serial.print(floorDistance);
  Serial.println(" cm");
}
void stopRover() { 
  Serial.println("OBSTACLE DETECTED: STOPPING!");
  analogWrite(Left_Enable, 0);  
  analogWrite(Right_Enable, 0); 
}

void moveback() { 
    digitalWrite(Left_Fwd, LOW);
    digitalWrite(Left_Rev, HIGH);
    digitalWrite(Right_Fwd, LOW);
    digitalWrite(Right_Rev, HIGH);
    analogWrite(Left_Enable, 250);  
    analogWrite(Right_Enable, 250);    
}

void turnLeft() { 
  //turn left by 90 degrees
  unsigned long  initialTime = millis();   
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
void moveforward_continuous() { 
    digitalWrite(Left_Fwd, HIGH);
    digitalWrite(Left_Rev, LOW);
    digitalWrite(Right_Fwd, HIGH);
    digitalWrite(Right_Rev, LOW);
    analogWrite(Left_Enable, 250);  
    analogWrite(Right_Enable, 250);  
}
