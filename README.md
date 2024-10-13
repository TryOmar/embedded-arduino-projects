# FanTimer

## Description
The **FanTimer** is an Arduino-based project designed to control a fan based on a user-defined timer. This project is particularly useful for situations where scheduled airflow is needed, such as in greenhouses, workshops, or home automation systems.

## Ideas and Benefits
The **FanTimer** offers several practical applications:

- **Home Automation**: Enables users to schedule fan operation, improving comfort without manual intervention.
- **Greenhouses**: Automates cooling for plants during hot periods, ensuring optimal growth conditions.
- **Workshops**: Maintains air circulation when working with materials that require ventilation, reducing fumes and enhancing comfort.

## Use Cases
- **Home Automation**: Cool the room before you arrive.
- **Temperature Regulation**: Schedule the fan to run during peak heat hours, providing a cooler environment without air conditioning.
- **Odor Control**: Automatically activate the fan after cooking or other odor-producing activities to maintain a fresh indoor atmosphere.
- **Cooking**: Ventilate the kitchen after cooking.
- **Pet Comfort**: Keep pets cool during hot days.
- **Grow Room**: Maintain optimal conditions for plants.
- **Allergy Management**: Circulate air to reduce allergens.
- **Dehumidification**: Reduce humidity in damp areas.
- **Event Preparation**: Cool the space before guests arrive.
- **Study Environment**: Create a comfortable study area.

## Circuit Design
The circuit design of the FanTimer is shown below:

![image](https://github.com/user-attachments/assets/e7dfdd6d-fa30-4715-9db2-9caa3c013001)


## Tinkercad Project
The following image shows the Tinkercad representation of the project:

![image](https://github.com/user-attachments/assets/1c2e1ca6-91b5-4c42-985e-fa33a89b0000)


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
| U2          | 1        | MCP23008-based, 32 (0x20) LCD 16 x 2 (I2C) |
| KEYPAD1     | 1        | Keypad 4x4                                   |
| M1          | 1        | DC Motor                                     |

## Preview Video
Watch a preview of the FanTimer in action: 


https://github.com/user-attachments/assets/f536ef3b-aed4-4579-8873-657e9ec8d6e6



## Conclusion
The FanTimer project is a versatile and practical solution for automating fan operation based on user-defined schedules. Its ease of use and potential applications make it a valuable addition to any automated system.
