#include <Arduino.h>
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(D2);
  Serial.begin(9600);
}

void loop() {
  for (int pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(10);
  }
  delay(500);

  for (int pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(10);
  }
  delay(500);
}