Project Requirements – Motor Control with Mode Switching & Temperature Feedback

1. Hardware Interfaces
   • Keypad:
     – 4×4 matrix keypad on digital pins 0–3 and 4–7  
     – Used to switch modes, navigate menus, set bounds, and enter manual speed  
   • LCD Display:
     – 16×2 character LCD (via I²C address 0)  
     – Shows temperature, speed level, bounds, mode, and menus  
   • Temperature Sensor:
     – TMP36 on analog pin A0  
     – Read and convert to °C:  
       voltage = raw × (5.0/1023),  
       temperatureC = (voltage – 0.5) × 100  
   • DC Motor:
     – Driven by PWM on digital pin 9  
     – Speed 0–255 by mapping speed levels 0–9  
   • Mode Indicator LEDs:
     – Blue LED (Manual Mode) on D8  
     – Green LED (Automatic Mode) on D10  
   • RGB LED (Temperature Indicator):
     – Red on D13  
     – Green on D11  
     – Blue on D12  
     – Color blended via PWM to reflect temperature  

2. System Modes & Behavior
   • Two Modes:
     1. Automatic Mode  
        – Motor speed is determined automatically from temperature  
        – Green mode LED ON  
     2. Manual Mode  
        – User enters speed level (0–9) via keypad  
        – Blue mode LED ON  
   • System On/Off:
     – Toggle power state with ‘#’ key  
     – When OFF: motor and RGB outputs are off, LCD shows “System Off”  

3. User Interaction via Keypad & LCD
   • ‘A’: Toggle between Automatic and Manual modes  
   • ‘*’: Enter/exit Speed Table display mode  
   • Speed Table Mode:
     – Shows two entries per page (S0…S9), with temperature ranges for each speed level  
     – Navigate pages with ‘*’, exit with ‘C’  
   • ‘B’: Begin setting Lower Temp Bound  
     – Enter numeric characters, confirm with ‘D’  
     – Then prompt Upper Bound  
   • ‘C’: Cancel bound-setting or exit Speed Table  
   • In Manual Mode: numeric keys ‘0’–‘9’ set the motor speed level directly  

4. Temperature-to-Speed Mapping
   • Lower/Upper bounds default to 20.0 °C / 50.0 °C  
   • Speed Level (0–9):
     – ≤ lower bound → 0  
     – ≥ upper bound → 9  
     – Otherwise: round(((temp – lower) / range) × 9)  
   • PWM Value = map(speedLevel, 0–9 → 0–255)

5. RGB LED Color Calculation
   • Red   = map(temp, –40 … 125 °C → 0 … 255)  
   • Green = map(temp, –40 … 125 °C → 255 … 0)  
   • Blue  = 255 if temp < lower bound, else 0  
   • All channels constrained to 0–255  
   • RGB off when system is off  

6. Timing & Refresh
   • Main loop delay: 200 ms  
   • LCD and LEDs updated on any state/key change  
   • Non‐blocking sensor reads and keypad scans  

