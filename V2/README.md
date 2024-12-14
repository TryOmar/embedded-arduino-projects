# FanTimer V2 - Enhanced Motor Control

## What's New in V2
This version enhances the original FanTimer project with the following improvements:
- **H-Bridge Integration**: Added L298N motor driver for better motor control
- **Speed Control**: Variable speed settings for the fan
- **Direction Control**: Ability to reverse motor direction
- **Protected Circuit**: Better electrical isolation between Arduino and motor
- **Improved Power Handling**: Can handle higher power motors

## Circuit Changes
- Added L298N H-Bridge motor driver
- Updated motor connections to use H-Bridge outputs
- Additional power supply connections for motor driver
- Modified Arduino pin assignments for H-Bridge control

## Components (Additional/Changed)
| Component | Description |
|-----------|-------------|
| L298N | H-Bridge motor driver module |
| Power Supply | 12V for motor (separate from Arduino) |
| Capacitors | For motor noise suppression |

## Installation
1. Follow the updated circuit diagram
2. Connect the H-Bridge module:
   - ENA -> Arduino PIN 10
   - IN1 -> Arduino PIN 11
   - IN2 -> Arduino PIN 12
   - Motor outputs to motor terminals
   - Power supply to H-Bridge VCC
3. Upload the V2 code to Arduino

## Usage
All original timer functions remain the same as V1. See the main [usage manual](../README.md#usage-manual) for basic operation.

## Resources
- 📽️ [Watch V2 Demo Video](https://youtu.be/WxNZjEOgeos)
- 📁 [Project Files](https://drive.google.com/drive/folders/1t7pokOaPTi40edPa0rQoVFkKiX6PXEVr?usp=sharing)
- 📚 [Full Documentation](./FanTimerArdunio.md) 