#include <LiquidCrystal_I2C.h>
// #include <Wire.h>

int ledPin = 13; // Nano board LED.
int hallSensorPin = 3; // Hall effect sensor to Pin D3.
int state = LOW; // Starting state for LEDpin.
int counter = 0; // Counter for wheel rotations.
LiquidCrystal_I2C lcd(0x27, 20, 4); // Screen initialisation.

void setup() {
lcd.init(); // Initialisation screen
lcd.clear(); // Clear screen
lcd.backlight(); // Activate screen Backlight.

pinMode(ledPin, OUTPUT); // 
pinMode(hallSensorPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(hallSensorPin), switch1, FALLING); // Activate switch1() on interupt LOW TO HIGH aka RISING.
}

//80.5cm Circumference of wheel used.

void loop(){
  
// delay(1000);
// lcd.setBacklight(LOW); // Turn off Backlight.

state = digitalRead(hallSensorPin);

float cmRan = counter * 80.5;
float mRan = cmRan / 100;
float milesRan = cmRan / 160934.4;
float kmRan = cmRan / 100000;
float calories = milesRan * 100;

if (state == HIGH) {
lcd.setBacklight(HIGH);
digitalWrite(ledPin, state);
// ++counter;
}
else {
digitalWrite(ledPin, LOW);
}

lcd.setCursor(0,0);
// lcd.print("Name   : Milk");
lcd.print("    Milk's Wheel");

lcd.setCursor(0,1);
lcd.print("Spins   : ");
lcd.print(counter);

lcd.setCursor(0,2);
lcd.print("Metres  : ");
lcd.print(mRan, 1);

lcd.setCursor(0,3);
lcd.print("Calories: ");
lcd.print(calories, 0); 
}

void switch1() {
  state = !state;
  ++counter;
}
