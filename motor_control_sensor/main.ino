#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>

// Keypad Configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};

// Pin Definitions
const int tempPin = A0;
const int motorPin = 9;
const int blueModePin = 8;
const int greenModePin = 10;
const int redTempPin = 13;
const int greenTempPin = 11;
const int blueTempPin = 12;

// Global Variables
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_LiquidCrystal lcd_1(0);

bool isAutomaticMode = true;
bool isSystemOn = true;
bool isSpeedTableMode = false;
int manualSpeedLevel = 0; // Speed level 0-9 for manual mode
int currentSpeedLevel = 0; // Current speed level 0-9 for display
int motorSpeed = 0;       // Actual PWM value 0-255
float lowerTempBound = 20.0;
float upperTempBound = 50.0;
String inputBuffer = "";
bool settingLowerBound = false;
bool settingUpperBound = false;
int currentSpeedTablePage = 0;

void setup() {
  // Initialize Pins
  pinMode(motorPin, OUTPUT);
  pinMode(blueModePin, OUTPUT);
  pinMode(greenModePin, OUTPUT);
  pinMode(redTempPin, OUTPUT);
  pinMode(greenTempPin, OUTPUT);
  pinMode(blueTempPin, OUTPUT);
  
  // Initial LCD Setup
  lcd_1.begin(16, 2);
  lcd_1.print("Motor Control");
  delay(1000);
  
  // Initial Mode Setup
  updateModeLEDs();
  updateLCD();
}

void updateModeLEDs() {
  digitalWrite(greenModePin, isSystemOn && isAutomaticMode ? HIGH : LOW);
  digitalWrite(blueModePin, isSystemOn && !isAutomaticMode ? HIGH : LOW);
}

void calculateRGBColor(float temperatureC) {
  // Map temperature to RGB values
  int red = map(temperatureC, -40, 125, 0, 255);
  int green = map(temperatureC, -40, 125, 255, 0);
  int blue = (temperatureC < lowerTempBound) ? 255 : 0;
  
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);
  
  // Set RGB LED only if system is on
  if (isSystemOn) {
    analogWrite(redTempPin, red);
    analogWrite(greenTempPin, green);
    analogWrite(blueTempPin, blue);
  } else {
    analogWrite(redTempPin, 0);
    analogWrite(greenTempPin, 0);
    analogWrite(blueTempPin, 0);
  }
}

void updateLCD() {
  if (!isSystemOn) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("System Off");
    return;
  }

  if (isSpeedTableMode) {
    displaySpeedTable();
  } else if (settingLowerBound) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Enter Lower Temp:");
    lcd_1.setCursor(0, 1);
    lcd_1.print(inputBuffer);
  } else if (settingUpperBound) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Enter Upper Temp:");
    lcd_1.setCursor(0, 1);
    lcd_1.print(inputBuffer);
  } else {
    // Read Temperature
    int rawValue = analogRead(tempPin);
    float voltage = rawValue * (5.0 / 1023.0);
    float temperatureC = (voltage - 0.5) * 100.0;
    
    // Calculate speed level for display (0-9)
    currentSpeedLevel = isAutomaticMode ? calculateSpeedLevel(temperatureC) : manualSpeedLevel;
    
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("T:");
    lcd_1.print(temperatureC, 1);
    lcd_1.print("C S:");
    lcd_1.print(currentSpeedLevel);  // Display speed level 0-9
    lcd_1.print("/9");
    
    lcd_1.setCursor(0, 1);
    lcd_1.print("B:");
    lcd_1.print((int)lowerTempBound);
    lcd_1.print("-");
    lcd_1.print((int)upperTempBound);
    lcd_1.print("C ");
    lcd_1.print(isAutomaticMode ? "Auto" : "Manual");
  }
}

void displaySpeedTable() {
  lcd_1.clear();
  float range = upperTempBound - lowerTempBound;
  float step = range / 9.0;  // Divide the range into 9 equal steps for speeds 1-8

  for (int i = 0; i < 2; i++) {
    int speedIndex = currentSpeedTablePage * 2 + i;
    if (speedIndex > 9) break;

    lcd_1.setCursor(0, i);
    lcd_1.print("S");
    lcd_1.print(speedIndex);
    lcd_1.print(": ");

    if (speedIndex == 0) {
      lcd_1.print("<=");
      lcd_1.print(lowerTempBound, 1);
      lcd_1.print("C");
    } else if (speedIndex == 9) {
      lcd_1.print(">=");
      lcd_1.print(upperTempBound, 1);
      lcd_1.print("C");
    } else {
      float startTemp = lowerTempBound + (speedIndex - 1) * step;
      float endTemp = startTemp + step - 0.1;
      if (endTemp > upperTempBound - 0.1) {
        endTemp = upperTempBound - 0.1;
      }
      lcd_1.print(startTemp, 1);
      lcd_1.print("-");
      lcd_1.print(endTemp, 1);
      lcd_1.print("C");
    }
  }
}

int calculateSpeedLevel(float temperatureC) {
  if (temperatureC <= lowerTempBound) {
    return 0;
  } else if (temperatureC >= upperTempBound) {
    return 9;
  } else {
    float range = upperTempBound - lowerTempBound;
    return round(((temperatureC - lowerTempBound) / range) * 9);
  }
}

int speedLevelToPWM(int speedLevel) {
  return map(speedLevel, 0, 9, 0, 255); // Convert speed level 0-9 to PWM 0-255
}

int calculateMotorSpeed(float temperatureC) {
  if (!isSystemOn) return 0;
  
  if (isAutomaticMode) {
    currentSpeedLevel = calculateSpeedLevel(temperatureC);
    return speedLevelToPWM(currentSpeedLevel);
  } else {
    currentSpeedLevel = manualSpeedLevel;
    return speedLevelToPWM(manualSpeedLevel);
  }
}

void loop() {
  if (!isSystemOn) {
    char key = keypad.getKey();
    if (key == '#') {
      isSystemOn = true;
      updateModeLEDs();
      updateLCD();
    }
    return;
  }

  // Read Temperature
  int rawValue = analogRead(tempPin);
  float voltage = rawValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Calculate Motor Speed
  motorSpeed = calculateMotorSpeed(temperatureC);
  analogWrite(motorPin, isSystemOn ? motorSpeed : 0);
  
  // Update RGB Temperature Indicator
  calculateRGBColor(temperatureC);
  
  // Check for keypad input
  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
      isSystemOn = !isSystemOn;
      updateModeLEDs();
      updateLCD();
      if (!isSystemOn) {
        analogWrite(motorPin, 0);
      }
    } else if (isSpeedTableMode) {
      if (key == '*') {
        currentSpeedTablePage = (currentSpeedTablePage + 1) % 5;  // There are 5 pages (0-4) for 10 speeds
        updateLCD();
      } else if (key == 'C') {
        isSpeedTableMode = false;
        updateLCD();
      }
    } else if (key == '*' && !settingLowerBound && !settingUpperBound) {
      isSpeedTableMode = true;
      currentSpeedTablePage = 0;
      updateLCD();
    } else if (key == 'A' && !settingLowerBound && !settingUpperBound) {
      isAutomaticMode = !isAutomaticMode;
      updateModeLEDs();
      updateLCD();
    } else if (key == 'B' && !settingLowerBound && !settingUpperBound) {
      settingLowerBound = true;
      inputBuffer = "";
      updateLCD();
    } else if (key == 'C') {
      if (settingLowerBound || settingUpperBound) {
        settingLowerBound = false;
        settingUpperBound = false;
        inputBuffer = "";
      }
      updateLCD();  // Refresh LCD even if on default panel
    } else if (settingLowerBound || settingUpperBound) {
      if (key >= '0' && key <= '9') {
        inputBuffer += key;
        updateLCD();
      } else if (key == 'D') {
        if (settingLowerBound) {
          lowerTempBound = inputBuffer.toFloat();
          settingLowerBound = false;
          settingUpperBound = true;
          inputBuffer = "";
          updateLCD();
        } else if (settingUpperBound) {
          upperTempBound = inputBuffer.toFloat();
          settingUpperBound = false;
          inputBuffer = "";
          updateLCD();
        }
      }
    } else if (!isAutomaticMode && key >= '0' && key <= '9') {
      manualSpeedLevel = key - '0';  // Set speed level directly as 0-9
      updateLCD();
    }
  }
  
  delay(200);
}