# FanTimer Arduino Project

## Overview
The FanTimer is an Arduino-based project that allows you to control a fan with a customizable timer. Perfect for home automation, ventilation control, and various timing-based applications.

## Features
- Digital timer control through a 4x4 keypad
- LCD display for timer status and feedback
- Pause/Resume functionality
- Quick time adjustment options
- Automatic fan control

## Usage Manual

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

## Components Required
- Arduino Uno R3
- MCP23008-based LCD 16x2 (I2C)
- 4x4 Keypad
- DC Motor (Fan)
- Connecting wires

## Installation
1. Connect the components according to the circuit diagram
2. Upload the Arduino code to your board
3. Power up the system
4. Start using the timer!

## Resources
- 📽️ [Watch Demo Video](https://youtu.be/WxNZjEOgeos)
- 📁 [Project Files (Google Drive)](https://drive.google.com/drive/folders/1t7pokOaPTi40edPa0rQoVFkKiX6PXEVr?usp=sharing)
- 📚 [Full Documentation](./FanTimerArdunio.md)

## Creator
**Omar Abdelrahman Abbas**  
Created: 12/10/2024

## License
This project is open source and available under the MIT License.
