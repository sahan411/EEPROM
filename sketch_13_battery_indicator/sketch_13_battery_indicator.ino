//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int i;
float an;
int x = 0;
byte s[8] = {B11111,
             B10001,
             B10001,
             B10001,
             B10001,
             B10001,
             B10001,
             B11111
            };

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.createChar(0, s);
}


void loop()
{
  //bool pb = digitalRead(7);
  //bool qb = digitalRead(6);
  int value = analogRead(A0);
  x = map(value, 1023, 0, 16, 0);
  an = map(value, 16, 0, 255, 0);
  analogWrite(11, an);

  i = 0;
  while (i < x) {
    lcd.setCursor(i, 0);
    lcd.write(0);
    i = i + 1;
  }
  lcd.setCursor(i, 0);
  lcd.print("                 ");



}
