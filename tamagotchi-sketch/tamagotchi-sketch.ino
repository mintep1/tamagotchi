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
#define RedPin 6
#define YellowPin 7
#define GreenPin 13
byte noLed = 100;
int redBtn = 8;
int yellBtn = 9;
int greenBtn = 10;
byte ledArray[4] = { RedPin, GreenPin, YellowPin, noLed };

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// String display = "(^ > o <^)!!";
// int row = 0;
// int column = 2;

byte knife[8] = {
  0b00010,
  0b00110,
  0b01110,
  0b01110,
  0b01110,
  0b00110,
  0b00110,
  0b00110
};

byte fork[8] = {
  0b10101,
  0b10101,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};

void setup() {
  Serial.begin(9600);

  //set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  //create unique characters using byte array
  lcd.createChar(0, knife);
  lcd.createChar(1, fork);

  //set the button pins to receive input on release
  pinMode(redBtn, INPUT_PULLUP);
  pinMode(yellBtn, INPUT_PULLUP);
  pinMode(greenBtn, INPUT_PULLUP);

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(YellowPin, OUTPUT);

  printNormal();
}

// Check if any LEDs are on or off. Return the value or LOW.
byte stateCheck(byte val1, byte val2, byte val3) {
  if (val1 == HIGH) return val1;
  if (val2 == HIGH) return val2;
  if (val3 == HIGH) return val3;
  return LOW;
}

// Print the character in it's normal state
void printNormal() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("(^ > o <^)!!");
}

void loop() {
  //Select random LED to turn on
  byte led = ledArray[random(0, 4)];

  // Read LED states
  byte red = digitalRead(RedPin);
  byte green = digitalRead(GreenPin);
  byte yellow = digitalRead(YellowPin);

  //Store state of LEDs
  byte anyLedOn = stateCheck(yellow, red, green);

  //If any of the LEDs are NOT on, turn on the randomly selected LED
  if (anyLedOn == LOW) {
    delay(random(1000, 5000));
    if (led != noLed) {
      digitalWrite(led, HIGH);
      anyLedOn = HIGH;
    }
  }

  // If an LED is on, print the corresponding character state
  if (anyLedOn == HIGH) {
    lcd.clear();
    if (red == HIGH) {
      lcd.print("(_ _ ). . z Z");
      lcd.setCursor(3, 1);
      lcd.print("Sleepy...");
    }
    if (yellow == HIGH) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.write((byte)1);
      lcd.setCursor(5, 0);
      lcd.print("(^q^)");
      lcd.setCursor(10, 0);
      lcd.write((byte)0);
      lcd.setCursor(4, 1);
      lcd.print("Feed Me!");
    }
    if (green == HIGH) {
      lcd.setCursor(3, 0);
      lcd.print("(  ; ^ ; )");
      lcd.setCursor(5, 1);
      lcd.print("Pet Me!");
    }
  }

  // Read Button States
  byte redState = digitalRead(redBtn);
  byte greenState = digitalRead(greenBtn);
  byte yellowState = digitalRead(yellBtn);

  // Change LED and character state when the corresponding button is pressed
  if (redState == LOW && red == HIGH) {
    digitalWrite(RedPin, LOW);
    printNormal();
  }
  if (yellowState == LOW && yellow == HIGH) {
    digitalWrite(YellowPin, LOW);
    printNormal();
  }
  if (greenState == LOW && green == HIGH) {
    digitalWrite(GreenPin, LOW);
    printNormal();
  }
}