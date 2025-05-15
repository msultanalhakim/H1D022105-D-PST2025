#include <Arduino.h>
#include <Servo.h>

const int trigPin = D0;
const int echoPin = D1;
const int servoPin = D2;

Servo gateServo;

long duration;
float distance;
bool isOpen = false;

void setup () {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  gateServo.attach(servoPin);
  gateServo.write(0);
}

void loop () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  Serial.println("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance <= 15 && !isOpen) {
    for (int pos = 0; pos <= 90; pos++) {
      gateServo.write(pos);
      delay(10);
    }
    isOpen = true;
    Serial.println("Palang terbuka");
  } else if (distance > 20 && isOpen) {
      for (int pos = 90; pos >= 0; pos--) {
        gateServo.write(pos);
        delay(10);
      }
      isOpen = false;
      Serial.println("Palang tertutup");
  }
  delay(500);
}