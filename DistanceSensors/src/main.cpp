#include <Arduino.h>

int trigPin = D3;
int echoPin = D0;
int led = D2;

long duration;
float distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT); 
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.034) / 2;

    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance < 20) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }

    delay(500);
}