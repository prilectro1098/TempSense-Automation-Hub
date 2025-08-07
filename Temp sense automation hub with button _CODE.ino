#include <LiquidCrystal.h>

// Pin assignments
const int LM35Pin = A0;        // LM35 Temperature Sensor
const int fanPin = 3;          // Fan control (PWM pin)
const int buzzerPin = 5;       // Buzzer
const int redLEDPin = 9;       // RGB LED Red
const int yellowLEDPin = 10;   // RGB LED Yellow
const int blueLEDPin = 11;     // RGB LED Blue
const int buttonPin = 8;       // Push button

// LCD pin assignments
LiquidCrystal lcd(A1, A2, A3, A4, A5, 6);  // RS, E, D4, D5, D6, D7

int temperatureC;
int buttonState = 0;
bool fanOverride = false;

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Internal pull-up for button
  
  lcd.begin(16, 2);  // Initialize LCD
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);  // Move cursor to second line
  lcd.print("Fan: ");
}

void loop() {
  // Correct formula to read temperature from LM35
  float voltage = analogRead(LM35Pin) * (5.0 / 1023.0);  // Convert analog reading to voltage
  temperatureC = voltage * 100;  // Convert voltage to temperature (LM35 provides 10mV per degree Celsius)

  // Display temperature on LCD
  lcd.setCursor(6, 0);  // Move cursor after "Temp: "
  lcd.print(temperatureC);
  lcd.print("C  ");     // Extra spaces to clear old digits

  // Read the push button state
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    fanOverride = !fanOverride;  // Toggle fan override when button is pressed
    delay(300);  // Debounce delay
  }

  // Control fan and LEDs based on temperature
  if (!fanOverride) {
    if (temperatureC < 25) {
      analogWrite(fanPin, 0);  // Turn fan off
      digitalWrite(redLEDPin, LOW);
      digitalWrite(yellowLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);  // Cool temperature - Blue LED
      lcd.setCursor(6, 1);  // Move cursor after "Fan: "
      lcd.print("Off ");
    } else if (temperatureC >= 25 && temperatureC <= 35) {
      analogWrite(fanPin, 128);  // Medium speed
      digitalWrite(redLEDPin, LOW);
      digitalWrite(yellowLEDPin, HIGH);  // Moderate temperature - Yellow LED
      digitalWrite(blueLEDPin, LOW);
      lcd.setCursor(6, 1);
      lcd.print("Med ");
    } else if (temperatureC > 35) {
      analogWrite(fanPin, 255);  // Max speed
      digitalWrite(redLEDPin, HIGH);  // Hot temperature - Red LED
      digitalWrite(yellowLEDPin, LOW);
      digitalWrite(blueLEDPin, LOW);
      lcd.setCursor(6, 1);
      lcd.print("Max ");
      
      // Activate buzzer when temperature is too high
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
    }
  } else {
    // Fan override mode (manual fan control)
    analogWrite(fanPin, 255);  // Set fan to max speed
    digitalWrite(redLEDPin, HIGH);  // Indicate override mode with Red LED
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(blueLEDPin, LOW);
    lcd.setCursor(6, 1);
    lcd.print("Over");  // Display override status
  }

  delay(500);  // Delay for next reading
}