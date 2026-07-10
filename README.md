# smart-automatic-street-light
IoT-based Smart Automatic Street Light using ESP32, LDR, IR Sensors, Blynk, and Relay Module.

## Requirements
# Hardware
- ESP32 Development Board
- LDR Sensor
- IR Sensors (3)
- LEDs
- Jumper Wires
- Breadboard
- Power Supply

# Software
- Arduino IDE
- Blynk IoT
- ESP32 Board Package
- Wi-Fi Connection

# Installation
1. Install Arduino IDE.
2. Install the ESP32 board package.
3. Install the Blynk library.
4. Update the Wi-Fi credentials and Blynk Auth Token in the code.
5. Upload the code to the ESP32.


## How It Works
1. The LDR sensor detects whether it is day or night.
2. During the daytime, all street lights remain OFF to save energy.
3. At night, the ESP32 continuously monitors the IR sensors.
4. When a vehicle or pedestrian is detected, the corresponding LED street light turns ON.
5. If no motion is detected, the LED remains OFF, reducing unnecessary power consumption.
6. The ESP32 sends notifications through the Blynk IoT platform whenever the street lights turn ON or OFF.
7. This system provides automatic street lighting, reduces energy consumption, and supports smart city applications.


## Author
Maintained on GitHub by Basavaraj Sattigeri.
This project was developed as a team project during the first semester IoT course.
