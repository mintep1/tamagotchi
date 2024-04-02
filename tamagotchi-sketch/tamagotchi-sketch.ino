/*c
Hookup guide used:
https://learn.sparkfun.com/tutorials/basic-character-lcd-hookup-guide

Hardware Hookup:

    LCD VSS pin to GND
    LCD VCC pin to 5V
    10kΩ Potentiometer to LCD VO pin (pin 3)
    LCD RS pin to digital pin 13
    LCD R/W pin to GND
    LCD Enable pin to digital pin 12
    .
    .
    .
    .
    LCD D4 pin to digital pin 11
    LCD D5 pin to digital pin 10
    LCD D6 pin to digital pin 9
    LCD D7 pin to digital pin 8
    LCD-Backlight - Anode to 10KΩ resistor to +5V (optional depending on your LC
Chat



D)
    LCD Backlight - K to GND
*/

#include <LiquidCrystal.h>
#define RedPin 3
#define GreenPin 6
#define YellowPin 5

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 12);

void setup() {
  Serial.begin(9600);

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(YellowPin, OUTPUT);

  //set up the LCD's number of columns and rows:
  // lcd.begin(16, 2);
}
void turnOff() {
  //set all three LED pins to 0 or OFF
  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, LOW);
  digitalWrite(YellowPin, LOW);
}

void loop() {
  //set the cursor to column 0, line 1
  //(note: line 1 is the second row, since counting begins with 0):
  // lcd.setCursor(0, 1);
  int rand = random(1, 100);
  Serial.println(rand);

  if (rand <= 25) digitalWrite(RedPin, HIGH);

  if (rand > 25 && rand <= 50) digitalWrite(YellowPin, HIGH);

  if (rand > 50) digitalWrite(GreenPin, HIGH);

  delay(2000);
  turnOff();
}