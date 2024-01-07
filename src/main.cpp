#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE_IN_CM 500

LiquidCrystal_I2C lcd(0x27, 16, 2);

int getVolume();

NewPing sonic = NewPing(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE_IN_CM);

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  unsigned long distance = sonic.ping_cm();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000);
}
