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
| Breadboard | ❌ | ✅ |

## Version Details

### [V1 - Basic Version](./v1/)
- Basic fan control using direct Arduino pin
- Simple direct connections

### [V2 - Enhanced Version](./v2/)
- Added H-Bridge motor driver (L298N)
- Implemented breadboard for better organization

## Project Structure
```
FanTimerArduino/
├── README.md
├── v1/
└── v2/
```

## Getting Started
Choose the version that best suits your needs:
- Use V1 for simple timer-based fan control with direct connections
- Use V2 for organized breadboard layout with H-Bridge motor control

## Creator
**Omar Abdelrahman Abbas**  
Created: 12/10/2024

## License
This project is open source and available under the MIT License.
