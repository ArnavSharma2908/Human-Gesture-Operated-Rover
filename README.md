# 🚗 Human Gesture Operated Rover

An Arduino UNO–based rover controlled using **hand gestures** via the **PAJ7620 gesture sensor**, driving DC motors through an **L293D motor driver**. The system can optionally use an **RF module** for wireless control.

---

## ✨ Features
- Gesture-based rover control 🤚
- Smooth motor control using L293D ⚙️
- I2C-based PAJ7620 gesture sensor
- Modular and beginner-friendly design ✅

---

## 🧰 Components Required
- Arduino UNO
- PAJ7620 Gesture Sensor
- L293D Motor Driver IC / Module
- DC Motors + Rover Chassis
- RF Module (optional)
- External Motor Power Supply
- Jumper Wires

---

## 📦 Prerequisites
- Arduino IDE installed
- Basic Arduino programming knowledge
- PAJ7620 library added to Arduino IDE
- Circuit assembled as per pin connections

---

## 🔌 Pin Connections

### ➤ PAJ7620 Gesture Sensor (I2C)
- VCC → 5V  
- GND → GND  
- SDA → A4  
- SCL → A5  

### ➤ L293D Motor Driver → Arduino UNO

**Left Motor**
- EN1 → D5  
- IN1 → D6  
- IN2 → D7  

**Right Motor**
- EN2 → D9  
- IN3 → D10  
- IN4 → D11  

*Motor supply via external source if required*

---

## ✋ Gesture Mapping
| Gesture | Action |
|------|------|
| Up | Move Forward |
| Down | Move Backward |
| Left | Turn Left |
| Right | Turn Right |
| Push | Stop Rover |

---

## 🚀 How to Run
1. Clone this repository
2. Open `Gesture_Rover.ino` from `src/`
3. Select **Arduino UNO** & correct COM Port
4. Upload the code 📤
5. Power the rover and perform gestures 🎯

---

## 📂 Project Structure
