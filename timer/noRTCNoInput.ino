#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int peizoPin = 6;
int timer = 10;

void setup() {
  lcd.begin(16, 2);
  pinMode(peizoPin, OUTPUT);
  # testing purposes, set to 10 seconds
  lcd.print("Timer set!");
  lcd.setCursor(0, 1);
  lcd.print("00:00:10");
}

void loop() {
  // just set a countdown for 10 seconds
  while (timer > 0) {
    timer -= 1;
    lcd.setCursor(0, 1);
    lcd.print("00:00:");
    lcd.print(String(timer));
    delay(1000);
  }

  callPeizo();
}


void callPeizo() {
  // set a default frequency alarm for 2 seconds
  tone(peizoPin, 1000, 2000);
}
