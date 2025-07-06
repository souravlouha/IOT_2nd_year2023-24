#include <Servo.h>

Servo servoMotor;

int potPin = A0;  
int potValue;
int angle = 0;    
int speed;

bool increasing = true;  

void setup() {
  servoMotor.attach(9);  
}

void loop() {
  potValue = analogRead(potPin);  
  speed = map(potValue, 0, 1023, 10, 100);  

  if (increasing) {
    angle += 1;  
    if (angle >= 27) {
      increasing = false;  
    }
  } else {
    angle -= 1;  
    if (angle <= 0) {
      increasing = true;  
    }
  }

  servoMotor.write(angle);  

  
  delay(speed);
}