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
#define RedPin 4
#define YellowPin 7
#define GreenPin 13
byte noLed = 100;
byte lastLedState = LOW;
int redBtn = 8;
int yellBtn = 9;
int greenBtn = 10;
int btnState = 0;
byte ledArray[4] = { RedPin, GreenPin, YellowPin, noLed };
unsigned long debounceDuration = 50;  // millis
unsigned long lastTimeButtonStateChanged = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);

  //set the LED pins to output
  pinMode(redBtn, INPUT_PULLUP);
  pinMode(yellBtn, INPUT_PULLUP);
  pinMode(greenBtn, INPUT_PULLUP);
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
  digitalWrite(greenBtn, 0);
  digitalWrite(redBtn, 0);
  digitalWrite(yellBtn, 0);
}

byte stateCheck(byte val1, byte val2, byte val3) {
  if (val1 == HIGH) return val1;
  if (val2 == HIGH) return val2;
  if (val3 == HIGH) return val3;
  return LOW;
}

void lightOff(int led) {
  digitalWrite(led, LOW);
}

void loop() {
  //set the cursor to column 0, line 1
  //(note: line 1 is the second row, since counting begins with 0):
  // lcd.setCursor(0, 1);
  //Select random LED to turn on
  byte led = ledArray[random(0, 4)];

  // Read LED states
  byte red = digitalRead(RedPin);
  byte green = digitalRead(GreenPin);
  byte yellow = digitalRead(YellowPin);
  // Serial.println(red);
  // Serial.println(yellow);
  // Serial.println(green);

  byte anyLedOn = stateCheck(yellow, red, green);
  if (anyLedOn == LOW) {
    if (led != noLed) {
      delay(random(10000, 60000));
      digitalWrite(led, HIGH);
    }
  }

  // Read Button States and change LED state
  byte redState = digitalRead(redBtn);
  byte greenState = digitalRead(greenBtn);
  byte yellowState = digitalRead(yellBtn);

  if (redState == LOW) {
    digitalWrite(RedPin, LOW);
    delay(2000);
  }
  if (yellowState == LOW) {
    digitalWrite(YellowPin, LOW);
    delay(2000);
  }
  if (greenState == LOW) {
    digitalWrite(GreenPin, LOW);
    delay(2000);
  }
}