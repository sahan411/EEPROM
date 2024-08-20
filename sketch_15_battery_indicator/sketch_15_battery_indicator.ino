//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int i;
float an;
int x = 0;
int a, b;
byte zero[8] = {B00000,
                B00000,
                B00000,
                B00000,
                B00000,
                B00000,
                B00000,
                B00000
               };

byte one[8] = {B10000,
               B10000,
               B10000,
               B10000,
               B10000,
               B10000,
               B10000,
               B10000
              };

byte two[8] = {B11000,
               B11000,
               B11000,
               B11000,
               B11000,
               B11000,
               B11000,
               B11000
              };

byte three[8] = {B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100
                };

byte four[8] = {B11110,
                B11110,
                B11110,
                B11110,
                B11110,
                B11110,
                B11110,
                B11110
               };

byte five[8] = {B11111,
                B11111,
                B11111,
                B11111,
                B11111,
                B11111,
                B11111,
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
  lcd.createChar(0, zero);
  lcd.createChar(1, one);
  lcd.createChar(2, two);
  lcd.createChar(3, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
  Serial.begin(9600);
}


void loop()
{
  int value = analogRead(A0);
  x = map(value, 1023, 0, 80, 0);

  a = x / 5;
  b = x - (a * 5);

  i = 0;
  while (i < a) {
    lcd.setCursor(i, 0);
    lcd.write(5);

    lcd.setCursor(i, 1);
    lcd.write(5);
    i = i + 1;
  }

  lcd.setCursor(i, 0);
  lcd.write(b);
  lcd.print("                 ");
  lcd.setCursor(i, 1);
  lcd.write(b);
  lcd.print("                 ");

}
