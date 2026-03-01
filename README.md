# Real Time Wireless Smart Home Automation System using IoT

This project is a **Real-Time Wireless Smart Home Automation System** developed using Arduino.
It enables users to control multiple home appliances wirelessly using a **4x4 keypad interface** and displays real-time device status on a **16x4 LCD display**.

The system supports wireless communication using:

* **Bluetooth module (HC-05 / HC-06)**
* **WiFi module (ESP8266 / ESP32)**

In simulation, wireless communication is implemented using **direct serial connection** to represent Bluetooth/WiFi data transmission.

The system controls the following appliances:

* Light 1
* Fan 1
* Light 2
* AC (with real-time temperature monitoring)
* Fan 2

When AC is turned ON, the room temperature is continuously displayed using an **LM35 temperature sensor**.

## Circuit

<img width="1394" height="853" alt="image" src="https://github.com/user-attachments/assets/7823700d-88e0-4f62-a297-7a4ebe336472" />

## Objective

To design and implement a low-cost, real-time wireless home automation system that demonstrates:

* Embedded device control
* Bluetooth/WiFi-based communication
* LCD menu-driven interface
* Temperature monitoring integration
* IoT-ready system architecture

## System Working

### 1. User Input

* User presses a key on the 4x4 keypad.
* The command is transmitted wirelessly via Bluetooth or WiFi.
* In simulation, this transmission is represented using Serial communication.

### 2. Wireless Communication Layer

* Bluetooth (HC-05/HC-06) or WiFi (ESP8266/ESP32) sends command data.
* Arduino receives the data through serial interface.
* Commands are processed in real time.

### 3. Device Control

* Based on received command:

  * Corresponding device is toggled (ON/OFF).
  * Output pins are activated/deactivated.
  * LCD is updated instantly.

### 4. LCD Interface

* Displays device name and status.
* Shows ON/OFF indication.
* Supports scroll-based menu navigation.
* Displays live temperature when AC is active.

### 5. Temperature Monitoring

* LM35 sensor reads analog temperature.
* Arduino converts voltage into Celsius.
* Temperature is shown on LCD continuously.

## Hardware Components Used

* Arduino Uno
* 16x4 LCD Display
* 4x4 Matrix Keypad
* LM35 Temperature Sensor
* Bluetooth Module (HC-05 / HC-06)
* WiFi Module (ESP8266 / ESP32)
* LEDs (Light simulation)
* DC Motors (Fan simulation)
* Jumper Wires
* 5V Power Supply

> 🔹 Note: In simulation, Bluetooth/WiFi communication is represented using direct serial wireless connection.

## Output
<img width="1390" height="851" alt="Screenshot 2026-03-01 103245" src="https://github.com/user-attachments/assets/b1ffe4bd-18cc-4abb-96e8-8be6d17842dd" />


## Software Used

* Arduino IDE
* LiquidCrystal Library
* Keypad Library
* Serial Communication

## Skills Demonstrated

* Embedded C Programming
* LCD & Keypad Interfacing
* Bluetooth Communication
* WiFi Communication
* Serial Communication
* Analog Sensor Integration
* Real-Time Embedded System Design
* IoT Architecture Development
