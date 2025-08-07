# 🌡️ TempSense Automation Hub

**Smart Temperature-Based Fan and LED Control System with LCD Display**

TempSense Automation Hub is an Arduino-based automation system that intelligently monitors ambient temperature using an LM35 sensor and responds by automatically controlling a fan and RGB LEDs. It features an LCD display for real-time temperature and fan status, a buzzer for high-temperature alerts, and a manual override button for user control.

---

## 🛠️ Features

- 📈 Real-time temperature monitoring via LM35 sensor
- 🌀 Automatic fan speed control using PWM
- 🔴🟡🔵 RGB LED indication (Cool, Moderate, Hot)
- 📟 16x2 LCD Display for live temperature and fan status
- 🚨 Buzzer alert for high temperatures (>35°C)
- 🔘 Manual override mode for full-speed fan control

---

## 🧰 Hardware Components

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| LM35 Temperature Sensor| 1        |
| 16x2 LCD Display       | 1        |
| DC Fan (5V)            | 1        |
| NPN Transistor (2N2222)| 1        |
| Red, Yellow, Blue LEDs | 1 each   |
| Buzzer                 | 1        |
| Push Button            | 1        |
| Resistors (220Ω, 1kΩ)  | As needed|
| Power Supply (5V)      | 1        |

---

## 🧑‍💻 Software Tools

- Arduino IDE (code uploading)
- Proteus (circuit simulation)

---

## ⚙️ Working Principle

1. **Temperature Measurement:**
   - LM35 sensor outputs voltage linearly proportional to temperature.
   - Arduino converts analog voltage into °C.

2. **Fan & LED Control:**
   - < 25°C → Fan off, Blue LED on
   - 25–35°C → Fan medium speed, Yellow LED on
   - > 35°C → Fan full speed, Red LED + Buzzer alert

3. **Manual Override:**
   - Push button toggles fan to max speed, regardless of temperature.

4. **Display:**
   - LCD shows: `Temp: XX°C` and `Fan: Off / Med / Max / Over`

---

## 🧪 Circuit Diagram

Simulated in **Proteus**. Files included:
- `Smart Temperature-Based Fan and LED Control System with LCD Display.DSN`
- `Smart Temperature-Based Fan and LED Control System with LCD Display.PWI`

![Circuit Design Screenshot](./assets/Screenshot1.png)
![Simulation Running](./assets/Screenshot2.png)

---

## 📂 Project Structure

TempSense-Automation-Hub/
├── code/
│ └── POLTREE_FIRM_WITH_EMERGENCY_BUTTON_CODE.ino
├── simulation/
│ ├── Smart Temperature-Based Fan and LED Control System with LCD Display.DSN
│ └── Smart Temperature-Based Fan and LED Control System with LCD Display.PWI
├── assets/
│ ├── Screenshot1.png
│ └── Screenshot2.png
├── Project Report(Poultry Farm).pdf
└── README.md

yaml
Copy
Edit

---

## 🧪 How to Run

1. **Upload Code:**
   - Open `.ino` file in Arduino IDE.
   - Select correct board & port.
   - Upload to Arduino Uno.

2. **Simulate (Optional):**
   - Open `.DSN` file in Proteus.
   - Run the simulation to visualize the system.

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙋‍♀️ Author

**Saloni Sharma**  
Intern Project – Smart Embedded Systems  
Year: 2025

---

## ⭐ Support

If you find this project useful, feel free to ⭐ star it and fork it for your own custom automation systems!

---
