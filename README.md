# 17_Basic_calculator
# LCD Calculator with Single-Digit Operands

## Overview

This project implements a simple calculator using an LCD display and a keypad. The user can enter two single-digit numbers and select an operation (addition, subtraction, multiplication, division), and the result is displayed on the LCD. After displaying the result, the user is prompted to press any key to restart the calculation.

## Components

- Arduino Board (e.g., Arduino Uno)
- 16x2 LCD with I2C interface
- 4x4 Keypad
- Connecting wires

## Libraries Used

- `LiquidCrystal_I2C` for interfacing with the I2C LCD.
- `Keypad` for handling keypad input.

## Circuit Diagram

| LCD Pin | Arduino Pin | | Keypad Row/Col | Arduino Pin |
|---------|--------------| |----------------|-------------|
| VCC     | 5V           | | R1             | 2           |
| GND     | GND          | | R2             | 3           |
| SDA     | A4           | | R3             | 4           |
| SCL     | A5           | | R4             | 5           |
|         |              | | C1             | 6           |
|         |              | | C2             | 7           |
|         |              | | C3             | 8           |
|         |              | | C4             | 9           |

## Installation and Setup

1. **Install Arduino IDE**: Ensure you have the Arduino IDE installed on your computer.
2. **Install Required Libraries**: 
   - Open the Arduino IDE.
   - Go to `Sketch -> Include Library -> Manage Libraries`.
   - Search for `LiquidCrystal_I2C` and `Keypad`, then install them.

3. **Connect the Components**:
   - Follow the circuit diagram to connect the LCD and the keypad to the Arduino.
   - Ensure the connections are secure and correct.

4. **Upload the Code**:
   - Open the Arduino IDE.
   - Copy the provided code into the IDE.
   - Select the correct board and port from `Tools -> Board` and `Tools -> Port`.
   - Click on the upload button to upload the code to the Arduino.

## Code Explanation

### Main Functions

1. **getNumber()**:
   - Reads a single-digit number from the keypad.
   - Returns the entered number.

2. **getOperation()**:
   - Waits for a valid operation key (A, B, C, D) to be pressed.
   - Maps keys to operations: A -> `+`, B -> `-`, C -> `x`, D -> `/`.

3. **setup()**:
   - Initializes the LCD.

4. **loop()**:
   - Main loop that handles the flow of the calculator.
   - Prompts the user to enter two numbers and an operation.
   - Displays the result or an error message if the operation is invalid (e.g., division by zero).
   - Displays a message prompting the user to restart the calculation.

## Limitations

This calculator only operates with single-digit operands. Attempting to input multi-digit numbers will not produce correct results.

## License

This project is open-source and free to use. Feel free to modify and distribute as needed.

---
