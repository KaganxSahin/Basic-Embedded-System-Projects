// Wiring
/*
- **Horizontal Servo Wiring**:
  - Connect the `VCC` pin of the horizontal servo to the `5V` pin of the STM32F103C8T6.
  - Connect the `GND` pin of the horizontal servo to the `GND` pin of the STM32F103C8T6.
  - Connect the `Control` pin of the horizontal servo to pin `PA9` on the STM32F103C8T6.

- **Vertical Servo Wiring**:
  - Connect the `VCC` pin of the vertical servo to the `5V` pin of the STM32F103C8T6.
  - Connect the `GND` pin of the vertical servo to the `GND` pin of the STM32F103C8T6.
  - Connect the `Control` pin of the vertical servo to pin `PA8` on the STM32F103C8T6.

- **LDR Sensor Wiring**:
  - Connect the `VCC` pin of each LDR sensor to the `5V` pin of the STM32F103C8T6.
  - Connect the `GND` pin of each LDR sensor to the `GND` pin of the STM32F103C8T6.
  - Connect the `Output` pin of the top left LDR to analog pin `PA0` on the STM32F103C8T6.
  - Connect the `Output` pin of the top right LDR to analog pin `PA3` on the STM32F103C8T6.
  - Connect the `Output` pin of the bottom left LDR to analog pin `PA1` on the STM32F103C8T6.
  - Connect the `Output` pin of the bottom right LDR to analog pin `PA2` on the STM32F103C8T6.

- **Battery Wiring**:
  - Connect the `VCC` pin of the battery to the `5V` pin of the STM32F103C8T6.
  - Connect the `GND` pin of the battery to the `GND` pin of the STM32F103C8T6.
*/

// Arduino IDE Code

#include <Servo.h>

// Horizontal and Vertical Servo Motor Pin Assignments
Servo horizontal;  // Horizontal Servo Motor
int servohori = 180;
int servohoriLimitHigh = 175;
int servohoriLimitLow = 5;

Servo vertical; // Vertical Servo Motor
int servovert = 45;
int servovertLimitHigh = 100;
int servovertLimitLow = 1;

// LDR sensor pin assignments
int ldrlt = A0; // Top Left LDR (PA0)
int ldrrt = A3; // Top Right LDR (PA3)
int ldrld = A1; // Bottom Left LDR (PA1)
int ldrrd = A2; // Bottom Right LDR (PA2)

void setup() {
  horizontal.attach(PA9); // Attach the horizontal servo to pin PA9
  vertical.attach(PA8); // Attach the vertical servo to pin PA8
  horizontal.write(180); // Initialize the horizontal servo to 180 degrees
  vertical.write(45); // Initialize the vertical servo to 45 degrees
  delay(2500); // Wait for 2.5 seconds to allow the servos to initialize
}

void loop() {
  // Read data from the LDR sensors
  int lt = analogRead(ldrlt); // Top Left LDR
  int rt = analogRead(ldrrt); // Top Right LDR
  int ld = analogRead(ldrld); // Bottom Left LDR
  int rd = analogRead(ldrrd); // Bottom Right LDR

  int tol = 90; // Tolerance value for adjustment

  // Calculate the average values of the LDR sensors
  int avt = (lt + rt) / 2; // Average value of top sensors
  int avd = (ld + rd) / 2; // Average value of bottom sensors
  int avl = (lt + ld) / 2; // Average value of left sensors
  int avr = (rt + rd) / 2; // Average value of right sensors

  // Calculate the difference between sensors for vertical and horizontal adjustments
  int dvert = avt - avd; // Difference between top and bottom sensors
  int dhoriz = avl - avr; // Difference between left and right sensors

  // Adjust the vertical servo motor
  if (abs(dvert) > tol) {
    if (avt > avd) { // If the top sensors receive more light
      servovert = ++servovert;
      if (servovert > servovertLimitHigh) servovert = servovertLimitHigh; // Ensure it doesn't exceed the limit
    } else { // If the bottom sensors receive more light
      servovert = --servovert;
      if (servovert < servovertLimitLow) servovert = servovertLimitLow; // Ensure it doesn't go below the limit
    }
    vertical.write(servovert); // Set the vertical servo to the new angle
  }

  // Adjust the horizontal servo motor
  if (abs(dhoriz) > tol) {
    if (avl > avr) { // If the left sensors receive more light
      servohori = --servohori;
      if (servohori < servohoriLimitLow) servohori = servohoriLimitLow; // Ensure it doesn't exceed the lower limit
    } else { // If the right sensors receive more light
      servohori = ++servohori;
      if (servohori > servohoriLimitHigh) servohori = servohoriLimitHigh; // Ensure it doesn't exceed the upper limit
    }
    horizontal.write(servohori); // Set the horizontal servo to the new angle
  }

  delay(10); // Wait for a short time before the next sensor reading
}
