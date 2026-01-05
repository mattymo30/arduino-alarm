#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int peizoPin = 8;
int timer = 10;
bool done = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(peizoPin, OUTPUT);
  lcd.print("Timer set!");
  lcd.setCursor(0, 1);
  lcd.print("00:00:10");
}

void loop() {
  while (timer > 0) {
    delay(1000);
    timer -= 1;
    lcd.setCursor(0, 1);
    lcd.print("00:00:0");
    lcd.print(String(timer));
    
  }
  if (!done) {
    lcd.setCursor(0, 0);
    lcd.print("Timer done!");
    callPeizo();
    done = true;
  }

}


void callPeizo() {
  tone(peizoPin, 500, 1500);
}
