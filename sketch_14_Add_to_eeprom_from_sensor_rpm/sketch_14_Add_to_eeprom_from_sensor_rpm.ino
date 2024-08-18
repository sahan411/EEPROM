#include <Keypad.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int y;
int i = 0;
float count;
int temp = 0;
long last_t = 0; long t = 0; long rpm = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
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

  lcd.backlight();
  if (x == temp) {
    if (x == 0) {
      // count = count + 1.5;
      t = millis() - last_t;
      last_t = millis();
      rpm = 60000 / t;
      lcd.setCursor(0, 1);
      lcd.print("Time is ->");
      lcd.setCursor(12, 1);
      lcd.print(t);
        lcd.print("    ");
      delay(300);
    }
    temp = !x;
  }

  if (y == 0) {
    count = 0;
    lcd.setCursor(0, 0);
    lcd.print("COUNT RESET");
    delay(300);

  }

  Serial.println(rpm);
  Serial.print(" RPM");
  lcd.setCursor(0, 0);
  lcd.print("RPM IS : ");
  lcd.setCursor(11, 0);
  lcd.print(rpm);
  lcd.print("    ");

}
