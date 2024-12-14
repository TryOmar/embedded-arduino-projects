# FanTimer Arduino Project Versions

This repository contains two versions of the FanTimer Arduino project:

## Version Comparison

| Feature | V1 (Basic) | V2 (Enhanced) |
|---------|------------|---------------|
| Timer Control | ✅ | ✅ |
| LCD Display | ✅ | ✅ |
| Keypad Interface | ✅ | ✅ |
| Direct Motor Control | ✅ | ❌ |
| H-Bridge Motor Control | ❌ | ✅ |
| Motor Direction Control | ❌ | ✅ |
| Motor Speed Control | ❌ | ✅ |

## Version Details

### [V1 - Basic Version](./v1/)
- Basic fan control using direct Arduino pin
- Simple ON/OFF motor functionality
- Perfect for basic timing applications
- [View V1 Documentation](./v1/README.md)

### [V2 - Enhanced Version](./v2/)
- Added H-Bridge motor driver (L298N)
- Improved motor control capabilities
- Variable speed control
- Bidirectional motor operation
- [View V2 Documentation](./v2/README.md)

## Project Structure
```
FanTimerArduino/
├── README.md
├── v1/
│   ├── README.md
│   ├── FanTimerArduino1.ino
│   ├── FanTimerArdunio.md
│   └── images/
└── v2/
    ├── README.md
    ├── FanTimerArduino2.ino
    ├── FanTimerArdunio.md
    └── images/
```

## Getting Started
Choose the version that best suits your needs:
- Use V1 for simple timer-based fan control
- Use V2 for advanced motor control features

## Creator
**Omar Abdelrahman Abbas**  
Created: 12/10/2024

## License
This project is open source and available under the MIT License.
