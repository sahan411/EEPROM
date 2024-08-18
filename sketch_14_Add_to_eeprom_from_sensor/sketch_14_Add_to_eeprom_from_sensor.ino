#include <Keypad.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int y;
int i = 0;
float count;
int temp = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  count = EEPROM.read(0);
  Serial.begin(9600);
  lcd.init();
  lcd.init();

  while (i < count) {
    i = i + 1;
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("LED BLINKING..");
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(7);
  y = digitalRead(6);

  if (x == temp) {
    if (x == 0) {
      count = count + 1.5;
      lcd.setCursor(0, 0);
      lcd.print("               ");
      EEPROM.write(0, count);
      delay(300);
    }
    temp = !x;
  }

  if (y == 0) {
    count = 0;
    EEPROM.write(0, count);
    lcd.setCursor(0, 0);
    lcd.print("COUNT RESET");
    delay(300);

  }
  Serial.print("count :");
  Serial.println(count);
  Serial.print(" Km");
  lcd.setCursor(0, 0);
  lcd.print("COUNT IS : ");
  lcd.setCursor(0, 1);
  lcd.print(count);

}
