#include <Arduino.h>
#include <Wire.h>

#define SDA_PIN D2
#define SCL_PIN D3

void setup() {
  Serial.begin(9600);
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.println("Memulai I2C Scanner...");
}

void loop() {
  byte error, address;
  int nDevices;
  nDevices = 0;
  
  Serial.println("Mencari perangkat I2C...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Perangkat I2C ditemukan di alamat 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    } else if (error == 4) {
      Serial.print("Kesalahan tak dikenal di alamat 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("Tidak ada perangkat I2C ditemukan.\n");
  else
    Serial.println("Pencarian selesai.\n");

  delay(5000);
}