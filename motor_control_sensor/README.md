# Temperature-Based Motor Control System

## Overview
This Arduino-based system provides intelligent motor speed control based on temperature readings. It features dual operation modes (automatic temperature-based control and manual user control), real-time temperature monitoring, visual feedback through RGB indicators, and an interactive user interface via LCD display and keypad input.

![Motor Control System Overview](./Motor%20Control%20Sensor.png)

## Features
- **Dual Operation Modes**:
  - **Automatic Mode**: Dynamic motor speed adjustment based on ambient temperature
  - **Manual Mode**: Direct user control of motor speed (levels 0-9)
- **Real-time Temperature Monitoring** via TMP36 sensor
- **Visual Feedback**:
  - Mode indicator LEDs (Blue for Manual, Green for Automatic)
  - RGB LED temperature visualization
  - 16×2 LCD status display
- **User Interface**:
  - 4×4 matrix keypad for system control
  - Speed table visualization and navigation
  - Customizable temperature thresholds

## Hardware Requirements
- Arduino board (Uno or compatible)
- 4×4 matrix keypad
- 16×2 LCD display with I²C interface
- TMP36 temperature sensor
- DC motor with suitable driver
- LEDs:
  - Blue LED (Manual Mode indicator)
  - Green LED (Automatic Mode indicator)
  - RGB LED (Temperature indicator)
- Resistors, wiring, and breadboard/prototyping board

## Pin Configuration
- **Keypad**: Digital pins 0-3 and 4-7
- **LCD Display**: I²C address 0
- **Temperature Sensor**: Analog pin A0
- **DC Motor Control**: PWM on digital pin 9
- **Mode Indicator LEDs**:
  - Blue (Manual Mode): Digital pin 8
  - Green (Automatic Mode): Digital pin 10
- **RGB LED**:
  - Red: Digital pin 13
  - Green: Digital pin 11
  - Blue: Digital pin 12

## Operation Guide

### Keypad Controls Reference

| Key | Function |
|-----|----------|
| `#` | System power toggle (On/Off) |
| `A` | Toggle between Automatic and Manual modes |
| `B` | Begin setting temperature bounds |
| `C` | Cancel current operation or exit menu |
| `D` | Confirm input (when setting bounds) |
| `*` | Enter/exit Speed Table view mode |
| `0-9` | In Manual Mode: Set motor speed level<br>In Bounds Setting: Enter numeric values |

### System Controls
- **Power Toggle**: Press '#' to turn the system on or off
- **Mode Switching**: Press 'A' to toggle between Automatic and Manual modes
- **Speed Table**: Press '*' to view/navigate the temperature-to-speed mapping table
- **Temperature Bounds Setting**:
  - Press 'B' to begin setting temperature bounds
  - Enter lower bound, press 'D' to confirm
  - Enter upper bound, press 'D' to confirm
- **Manual Speed Control**: In Manual Mode, press '0'-'9' to set motor speed level
- **Cancel/Exit**: Press 'C' to cancel current operation or exit menu

### Temperature-to-Speed Mapping
- Default temperature range: 20.0°C (lower) to 50.0°C (upper)
- Speed levels automatically mapped between bounds:
  - Below lower bound: Speed level 0
  - Above upper bound: Speed level 9
  - Between bounds: Proportionally calculated

### Visual Indicators
- **Mode LEDs**:
  - Green LED on: Automatic Mode active
  - Blue LED on: Manual Mode active
- **RGB Temperature Indicator**:
  - Color gradient from blue (cold) to red (hot)
  - Reflects current temperature reading

## Implementation Details
- Main loop delay: 200ms
- Non-blocking sensor reads and keypad scans
- LCD and LEDs updated on any state or key change
- Temperature calculation: `temperatureC = (voltage - 0.5) × 100` where `voltage = raw × (5.0/1023)`
- RGB color calculation based on temperature mapping from -40°C to 125°C

## Development
This project is part of an embedded systems learning path focusing on real-time sensor integration and responsive control systems. 