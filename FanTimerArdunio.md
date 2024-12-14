# FanTimer - Omar Abdelrahman Abbas

## Project Overview
The **FanTimer** is an Arduino-based project designed to control a fan based on a user-defined timer.

This project was created by **Omar Abdelrahman Abbas** on **12/10/2024**. All files and source code will be found here:\
📽️ **Watch the preview video**: [FanTimer in action](https://youtu.be/WxNZjEOgeos)  
📁 **Google Drive**: [Access project files here](https://drive.google.com/drive/folders/1t7pokOaPTi40edPa0rQoVFkKiX6PXEVr?usp=sharing)  
📂 **GitHub Repo**: [Check out the repository here](https://github.com/Omar7001-B/FanTimerArduio)

## Ideas and Benefits
The **FanTimer** offers several practical applications:
- **Home Automation**: Schedule fan operation for added comfort. 🏡
- **Greenhouses**: Automate cooling for optimal plant growth. 🌱
- **Workshops**: Ensure air circulation and reduce fumes. 🛠️

## Use Cases
- **Home Automation**: Cool the room before you arrive.
- **Temperature Regulation**: Schedule the fan to run during peak heat hours, providing a cooler environment without air conditioning. 🌞
- **Odor Control**: Automatically activate the fan after cooking or other odor-producing activities to maintain a fresh indoor atmosphere. 🍲
- **Cooking**: Ventilate the kitchen after cooking.
- **Pet Comfort**: Keep pets cool during hot days. 🐾
- **Grow Room**: Maintain optimal conditions for plants.
- **Dehumidification**: Reduce humidity in damp areas.
- **Event Preparation**: Cool the space before guests arrive. 🎉
- **Study Environment**: Create a comfortable study area. 📚

<div style="page-break-after: always;"></div>

## Circuit Design Schematic View
The circuit design of the FanTimer is shown below:  
![image](https://i.imgur.com/nb6bQAn.png)

<div style="page-break-after: always;"></div>

## Tinkercad Project
The following image shows the Tinkercad representation of the project:  
![image](https://i.imgur.com/HVxelNO.png)

<div style="page-break-after: always;"></div>

## Usage Manual
The FanTimer is controlled through a 4x4 keypad with the following functions:

### Keypad Controls
| Key | Function | Description |
|-----|----------|-------------|
| 0-9 | Enter Time | Input numbers to set the timer duration in seconds |
| A | Start Timer | Begin the countdown with the set duration |
| B | Pause/Resume | Toggle between pausing and resuming the timer |
| C | Reset | Clear the current time and reset the timer |
| D | Quick Add | Add 10 seconds to the current time |
| # | Show Credits | Display creator information |

### Basic Operation
1. **Setting the Time**: 
   - Use the numeric keys (0-9) to enter your desired duration in seconds
   - The time will be displayed on the LCD screen

2. **Timer Controls**:
   - Press 'A' to start the countdown
   - Press 'B' to pause/resume the timer
   - Press 'C' to reset everything
   - Press 'D' to quickly add 10 seconds
   - Press '#' to view creator credits

3. **Fan Operation**:
   - The fan will automatically start when the timer reaches zero
   - The fan will run for 5 seconds and then stop
   - The system will return to the time entry mode

## Code
The Arduino code responsible for controlling the FanTimer can be found in the file **`FanTimerArduino1.ino`**. This code handles user input from a keypad, manages timer functionality, and controls the fan operation.

## Components
The project consists of the following components:
- **Arduino Uno R3**: The main microcontroller board.
- **MCP23008-based, 32 (0x20) LCD 16 x 2 (I2C)**: For displaying timer values and status messages.
- **Keypad 4x4**: To input time and control the timer.
- **DC Motor**: Acts as the fan.

### Components List
| Component   | Quantity | Description                                   |
|-------------|----------|-----------------------------------------------|
| U1          | 1        | Arduino Uno R3                               |
| U2          | 1        | MCP23008-based, 32 (0x20) LCD 16 x 2 (I2C)   |
| KEYPAD1     | 1        | Keypad 4x4                                   |
| M1          | 1        | DC Motor                                     |

## Conclusion
The FanTimer project is a versatile and practical solution for automating fan operation based on user-defined schedules. Its ease of use and potential applications make it a valuable addition to any automated system. 🌟

<div style="page-break-after: always;"></div>

## Arduino Code
```c
#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_LiquidCrystal lcd(0);
int seconds = 0;
bool timerRunning = false;
bool timerPaused = false;
unsigned long previousMillis = 0;
const long interval = 1000;
const int motorPin = 13;
bool showOmarCredits = false;

void resetTimer();
void startTimer();
void pauseTimer();
void add10Seconds();
void enterTime(char key);
void displayTimerValue();
void runMotor(int duration);

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.print("Enter Time: ");
  pinMode(motorPin, OUTPUT);
}
```

<div style="page-break-after: always;"></div>


```c
void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == 'A') startTimer();
    else if (key == 'B') pauseTimer();
    else if (key == 'C') resetTimer();
    else if (key == 'D') add10Seconds();
    else if (key == '#') showOmarCredits = true;
    else if (key >= '0' && key <= '9') enterTime(key);
  }
  unsigned long currentMillis = millis();
  if (timerRunning && !timerPaused && currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (seconds > 0) {
      seconds--;
      lcd.setCursor(0, 1);
      lcd.print("Time: ");
      lcd.print(seconds);
      lcd.print("s   ");
    } else if (seconds == 0 && timerRunning) {
      timerRunning = false;
      lcd.clear();
      lcd.print("Time's up!");
      runMotor(5000);
      delay(2000);
      lcd.clear();
      lcd.print("Enter Time: ");
    }
  }

  if (showOmarCredits) {
    lcd.clear();
    lcd.print("Was made by");
    lcd.setCursor(0, 1);
    lcd.print("Omar Abdelrahman");
    delay(3000);
    lcd.clear();
    lcd.print("Enter Time: ");
    showOmarCredits = false;
  }
}
void resetTimer() {
  seconds = 0;
  timerRunning = false;
  timerPaused = false;
  lcd.clear();
  lcd.print("Enter Time: ");
}
```
```c

void startTimer() {
  if (seconds > 0) {
    timerRunning = true;
    timerPaused = false;
    previousMillis = millis();
  }
}

void pauseTimer() {
  if (timerRunning) timerPaused = !timerPaused;
}

void add10Seconds() {
  seconds += 10;
  lcd.setCursor(0, 1);
  lcd.print(seconds);
}

void enterTime(char key) {
  seconds = seconds * 10 + (key - '0');
  lcd.setCursor(0, 1);
  lcd.print(seconds);
}

void displayTimerValue() {
  lcd.setCursor(0, 1);
  lcd.print("Set: ");
  lcd.print(seconds);
  lcd.print("s ");
}

void runMotor(int duration) {
  digitalWrite(motorPin, HIGH);
  delay(duration);
  digitalWrite(motorPin, LOW);
}
```