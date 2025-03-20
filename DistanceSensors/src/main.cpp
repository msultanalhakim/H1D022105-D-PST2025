#include <Arduino.h>

int trigPin = D3;  // Trigger pin sensor ke D3
int echoPin = D0;  // Echo pin sensor ke D0
int led = D2;      // LED ke D2 (FIXED MISSING SEMICOLON)

long duration;
float distance;

void setup() {
    pinMode(trigPin, OUTPUT);  // TRIG harus OUTPUT
    pinMode(echoPin, INPUT);   // ECHO harus INPUT
    pinMode(led, OUTPUT);      // Gunakan variabel led, bukan LED_PIN
    Serial.begin(9600);
}

void loop() {
    // Kirim pulsa ultrasonik
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