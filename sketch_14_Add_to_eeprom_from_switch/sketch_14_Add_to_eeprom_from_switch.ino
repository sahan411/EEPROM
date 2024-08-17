#include <Keypad.h>
#include <EEPROM.h>

int x;
int i=0;
int count;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  count = EEPROM.read(0);
  Serial.begin(9600);

  while (i < count) {
    i = i + 1;
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(7);

  if (x == 0) {
    count = count + 1;
    EEPROM.write(0, count);
    delay(300);

  }
  Serial.print("   count :");
  Serial.println(count);

  

}
