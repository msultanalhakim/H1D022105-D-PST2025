#include <Arduino.h>

// Definisikan pin untuk lampu
int redPin = D0;
int yellowPin = D3;
int greenPin = D5;

void setup() {
  // Set pin sebagai output
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // **Pola 1: Semua lampu menyala sekaligus**
  for (int i = 0; i <= 2; i++) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);
    delay(500); // Lampu menyala selama 0.5 detik

    // Matikan semua lampu
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(500); // Semua lampu mati selama 1 detik
  }

  // **Pola 2: Lampu berkedip (nyala-mati) secara bersamaan**
  for (int i = 0; i <= 8; i++) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);
    delay(200); // Lampu menyala selama 0.1 detik

    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(200); // Semua lampu mati selama 0.1 detik
  }

  // **Pola 3: Lampu nyala bergantian (merah, kuning, hijau)**
  for (int i = 0; i <= 18; i++) {
    // Lampu merah menyala, matikan lampu lainnya
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(200); // Lampu merah menyala selama 0.1 detik

    // Lampu kuning menyala, matikan lampu lainnya
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(200); // Lampu kuning menyala selama 0.1 detik

    // Lampu hijau menyala, matikan lampu lainnya
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(200); // Lampu hijau menyala selama 0.1 detik
  }

    // **Pola 3: Lampu nyala bergantian secara acak (merah, kuning, hijau)**
  for (int i = 0; i <= 30; i++) {
    // Pilih angka acak antara 0, 1, atau 2 untuk memilih lampu
    int lampu = random(0, 3);  // 0 = merah, 1 = kuning, 2 = hijau

    // Matikan semua lampu terlebih dahulu
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    
    // Tentukan lampu yang akan menyala
    if (lampu == 0) {
      digitalWrite(redPin, HIGH);  // Lampu merah menyala
    } else if (lampu == 1) {
      digitalWrite(yellowPin, HIGH);  // Lampu kuning menyala
    } else {
      digitalWrite(greenPin, HIGH);  // Lampu hijau menyala
    }

    delay(200); // Durasi lampu menyala selama 0.2 detik
  }
}
