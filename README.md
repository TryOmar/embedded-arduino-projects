# Arduino Motor Control Projects

This repository contains two Arduino-based motor control systems, each demonstrating different approaches to embedded systems development with various input and control mechanisms.

## Projects Overview

### [Motor Control Timer](./motor_control_timer)

A timer-based motor control system that allows precise timing control of motor operation. This project demonstrates:

- Timer-based control mechanisms
- User interface with push buttons and LEDs
- H-Bridge motor driver integration
- Multiple operation modes (timing sequences)
- Circuit design and implementation in multiple versions

**[Tinkercad Simulation Link](https://www.tinkercad.com/things/0b62HdQeuvJ-fantimerarduino/editel?sharecode=PgaGDTmQbONCeW47sdQN1KdSD-fAZ8Uuix6WDo6ymUI)**

#### Demo Video
<!-- Motor Control Timer demo video will be placed here -->


https://github.com/user-attachments/assets/b76491ef-2071-493e-850b-0aa1ad663357

https://github.com/user-attachments/assets/832782b9-9fdc-4a7b-ae2a-68c089bfcff4





### [Motor Control Sensor](./motor_control_sensor)

A temperature-activated motor control system that dynamically adjusts motor speed based on environmental temperature readings. This project features:

- Real-time temperature monitoring and feedback
- Dual operation modes (automatic and manual)
- Interactive 4×4 keypad interface
- Status display via 16×2 LCD
- RGB visual temperature indication
- Customizable temperature thresholds

**[Tinkercad Simulation Link](https://www.tinkercad.com/things/iVBhH4Ugtej-motor-control-sensor/editel?sharecode=QxMnT5Qqpf0yYdPWEPi-bYSkW_10RLPMeTTnAAkVjkk)**

#### Demo Video
<!-- Motor Control Sensor demo video will be placed here -->

https://github.com/user-attachments/assets/2a200b7f-6b46-4110-a51f-e88b192c6234



## Repository Structure

```
embedded-arduino-projects/
├── motor_control_timer/     # Timer-based motor control project
│   ├── v1/                  # Initial implementation
│   ├── v2/                  # Improved version with H-Bridge
│   └── README.md            # Project documentation
│
├── motor_control_sensor/    # Temperature-based motor control
│   ├── main.ino             # Main program code
│   └── README.md            # Project documentation
│
└── README.md                # This file
```

## Development Environment

These projects are designed for Arduino-compatible hardware and can be compiled and uploaded using the Arduino IDE or compatible development environments.

## Getting Started

1. Browse to the project directory you're interested in
2. Review the project's README.md for specific requirements and setup instructions
3. Open the .ino file in Arduino IDE
4. Connect your Arduino board
5. Upload and run the program

Each project includes detailed documentation and circuit diagrams to help with implementation. 
