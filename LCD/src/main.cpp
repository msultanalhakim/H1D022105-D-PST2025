#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SDA_PIN D3
#define SCL_PIN D4

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0); // Kolom 0, Baris 0
  lcd.print("Sistem Tertanam Indonesia");

  lcd.setCursor(0, 1); // Kolom 0, Baris 1
  lcd.print("Muhammad Sultan Alhakim!");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}
