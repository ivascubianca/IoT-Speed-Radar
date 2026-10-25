# IoT Speed Radar

An ESP32-based speed detection system that measures the speed of a moving object using two infrared sensors. The system displays speed measurements on an OLED screen and uses LEDs to indicate whether the measured speed exceeds a configurable limit.

## Features

- **Speed Measurement:** Calculates speed based on the time taken to pass between two IR sensors.
- **OLED Display:** Displays measured speed and the current speed status.
- **LED Indicators:** Green LED for normal speed and red LED for overspeed.
- **Speed Limit Detection:** Compares the measured speed against a predefined threshold.
- **Wi-Fi Connectivity:** Supports IoT functionality through the ESP32's built-in Wi-Fi.

## Hardware Components

- ESP32-WROOM-32 development board
- 2 × Infrared obstacle detection sensors
- 0.96-inch OLED display (128×64, I²C)
- Green LED
- Red LED
- 2 × 470 Ω resistors
- Breadboard and jumper wires

## Technologies Used

- C/C++
- Arduino IDE
- ESP32
- I²C communication
- Wi-Fi

## How It Works

1. The first IR sensor detects the moving object and records the start time.
2. The second sensor records the time when the object reaches it.
3. The ESP32 calculates speed using the distance between the sensors and the elapsed time.
4. The measured speed is displayed on the OLED screen.
5. The LEDs indicate whether the speed is within the configured limit or exceeds it.

## Future Improvements

- Web dashboard for real-time speed monitoring.
- Remote speed limit configuration through a browser.
- Measurement history and maximum speed tracking.
- Improved measurement accuracy and sensor calibration.

