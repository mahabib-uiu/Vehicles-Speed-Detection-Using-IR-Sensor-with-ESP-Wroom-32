# Vehicles-Speed-Detection-Using-IR-Sensor-with-ESP-Wroom-32
Vehicle Speed Monitoring and Violation Detection System

This project implements a Vehicle Speed Monitoring and Violation Detection System using an ESP32 microcontroller, IR sensors, and the Arduino IoT Cloud. It calculates the speed of vehicles in two lanes, checks for speed limit violations, and updates the results on a cloud-based dashboard.

#Features

Speed Monitoring:

Calculates the speed of vehicles passing through two lanes using IR sensors.

The distance between two IR sensors is fixed at 6 cm.

Speed Violation Detection:

Detects if a vehicle exceeds the speed limit of 20 km/h.

Updates the violation status for each lane.

Cloud Integration:

Sends real-time speed and violation status updates to the Arduino IoT Cloud.

Displays the data on an Arduino IoT Cloud Dashboard.

Components Used

Hardware

ESP32 (WROOM-32) microcontroller

4 IR Sensors

Wi-Fi Network for cloud connectivity

Software

Arduino IoT Cloud

Arduino IDE / Online IDE

GitHub for version control

Pin Configuration

IR Sensor

ESP32 Pin

Lane 1, Sensor 1 (Entrance)

D35

Lane 1, Sensor 2 (Exit)

D34

Lane 2, Sensor 1 (Entrance)

VN (D39)

Lane 2, Sensor 2 (Exit)

VP (D36)

Working Principle

Speed Calculation:

When a vehicle triggers the first IR sensor, the system notes the timestamp.

When the vehicle triggers the second IR sensor, the system calculates the time difference.

Speed is computed using the formula:



Violation Detection:

If the calculated speed exceeds the threshold (20 km/h), the system flags the vehicle for a violation.

IoT Dashboard:

Real-time speed and violation status are displayed on the Arduino IoT Cloud dashboard.

Files in Repository

main.ino:

Contains the main code to calculate speed, check violations, and update the IoT Cloud.

thingProperties.h:

Defines the IoT Cloud variables and initializes cloud connectivity.

README.md:

Provides a comprehensive overview of the project.

Setup Instructions

Hardware Setup

Connect the IR sensors to the ESP32 as per the pin configuration table above.

Ensure a stable Wi-Fi network is available for cloud connectivity.

Software Setup

Clone this repository:

git clone https://github.com/your-repo-name/vehicle-speed-monitoring.git

Open the main.ino file in the Arduino IDE or Online IDE.

Update the Wi-Fi credentials in thingProperties.h:

const char SSID[] = "your_wifi_ssid";  // Replace with your Wi-Fi SSID
const char PASS[] = "your_wifi_password";  // Replace with your Wi-Fi password

Upload the code to your ESP32 board.

IoT Cloud Setup

Create an account on the Arduino IoT Cloud.

Add a new Thing and configure the following variables:

speed01 (float, Read/Write)

speed02 (float, Read/Write)

status01 (boolean, Read/Write)

status02 (boolean, Read/Write)

Link the ESP32 board to your Thing.

Dashboard Setup

Create a new dashboard on the Arduino IoT Cloud.

Add widgets to display:

speed01 (Lane 1 Speed)

speed02 (Lane 2 Speed)

status01 (Lane 1 Violation Status)

status02 (Lane 2 Violation Status)

How to Use

Power on the ESP32 and ensure it is connected to the Wi-Fi network.

Place the IR sensors on the lanes at the defined positions.

Monitor vehicle speeds and violation statuses on the Arduino IoT Cloud Dashboard.

Troubleshooting

No Data on Dashboard:

Verify Wi-Fi credentials in thingProperties.h.

Check cloud connectivity and ensure the ESP32 is linked to your Thing.

Incorrect Speed Calculation:

Ensure the IR sensors are aligned correctly.

Verify the distance between sensors is set to 6 cm.

Future Enhancements

Add support for additional lanes.

Integrate GPS for vehicle tracking.

Implement a camera module for license plate recognition.

License

This project is licensed under the MIT License. See the LICENSE file for details.

Author

Md Ahsan Habib (mahabib.uiu@gmail.com)
