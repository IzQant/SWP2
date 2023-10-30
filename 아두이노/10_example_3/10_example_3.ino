#include <Servo.h>

#define PIN_SERVO 10

Servo myServo;
unsigned long MOVING_TIME = 1000; // moving time is 3 seconds
unsigned long moveStartTime;
int startAngle = 30; // 30°
int stopAngle  = 120; // 90°

void setup() {
  myServo.attach(PIN_SERVO);
  moveStartTime = millis(); // start moving

  myServo.write(startAngle); // Set position
  delay(500);
}

void loop() {
  unsigned long progress = millis() - moveStartTime;

  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, startAngle, stopAngle);
    myServo.write(angle); 
  }
}