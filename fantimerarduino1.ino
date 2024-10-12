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

void resetTimer();
void startTimer();
void pauseTimer();
void add10Seconds();
void enterTime(char key);
void displayTimerValue();
void backspace();
void runMotor(int duration);

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.print("Enter Time: ");
  pinMode(motorPin, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == 'A') startTimer();
    else if (key == 'B') pauseTimer();
    else if (key == 'C') resetTimer();
    else if (key == 'D') add10Seconds();
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
}

void resetTimer() {
  seconds = 0;
  timerRunning = false;
  timerPaused = false;
  lcd.clear();
  lcd.print("Enter Time: ");
}

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
