# FanTimer V2 - Enhanced Motor Control

## What's New in V2
This version enhances the original FanTimer project with the following improvements:
- **H-Bridge Integration**: Added L298N motor driver for better motor control
- **Protected Circuit**: Better electrical isolation between Arduino and motor

## Circuit Changes
- Added L298N H-Bridge motor driver
- Updated motor connections to use H-Bridge outputs
- Modified Arduino pin assignments for H-Bridge control

## Components (Additional/Changed)
| Component | Description |
|-----------|-------------|
| L298N | H-Bridge motor driver module |
| Power Supply | 12V for motor (separate from Arduino) |
| Capacitors | For motor noise suppression |

## Usage
All original timer functions remain the same as V1. See the main [usage manual](../README.md#usage-manual) for basic operation.

## Resources
- 📽️ [Watch V2 Demo Video](https://youtu.be/WxNZjEOgeos)
- 📁 [Project Files](https://drive.google.com/drive/folders/1t7pokOaPTi40edPa0rQoVFkKiX6PXEVr?usp=sharing)
- 📚 [Full Documentation](./FanTimerArdunio.md) 