# arduino-robotics-portfolio

TRAFFIC MONITORING SYSTEM

|--> 1. THE PROBLEM:
There is often heavy traffic caused by traffic lights set to time intervals regardless of the traffic present on the road.
Here in our study, we studied how an embedded system detects traffic and responds to the traffic situation regardless of time intervals.

|--> 2. Solution: 
An Arduino-controlled system for traffic management with ultrasonic sensors and LED lights was developed.
Ultrasonic sensors detect the presence of cars on both roads, and Arduino manages traffic lights depending on their signal.

|--> 3. Why Did We Make It?
It was designed to be an actual building project during workshops.
This project was not made to just hand a ready-made circuit to students. They built the system on their own and understood how various components interact in an embedded system.
During the process of making the project, students:
. Learned to control LEDs
. Applied ultrasonic sensors
. Learned to wire circuits
. Worked with Arduino logic
. Learned to program in C++
. Automated using sensors

|--> 4. Workshop Process
The whole process took place gradually in the workshop.
01 — Understanding the LEDs
The students gained knowledge on how to control LEDs and how they work, utilizing the Arduino device.
02 — Introduction of the Ultrasonic Sensor
HC-SR04 sensor was introduced to detect the distance of the approaching vehicle.
03 — Creation of the Circuit
In this process, students connected sensors, LEDs, resistors, and Arduino device to learn how to use circuit diagrams.
04 — Connecting and Testing
Sections were tested independently before integrating the whole system.
05 — Writing and Testing the Code
Students programmed their Arduino devices to receive input data from the ultrasonic sensors and then control the traffic lights.
06 — Integrating Everything Together
Finally, all the elements were integrated into one traffic control system.

|--> 5. How It Works
The HC-SR04 keeps measuring the distance in front of it.
Once a car is sensed at the given distance, the Arduino analyses the measurement and alters the state of the traffic light.
This results in a simple implementation of:
|| Sense → Process → Act

|-->  Circuit Connections
 
 -------------------------------------------------------------------
| Component            | Pin / Terminal | Arduino Connection       |
| -------------------- | -------------- | ------------------------ |
| 🔴 Road 1 Red LED    | Anode (+)      | D2 through 220Ω resistor |
| 🔴 Road 1 Red LED    | Cathode (−)    | GND                      |
| 🟡 Road 1 Yellow LED | Anode (+)      | D3 through 220Ω resistor |
| 🟡 Road 1 Yellow LED | Cathode (−)    | GND                      |
| 🟢 Road 1 Green LED  | Anode (+)      | D4 through 220Ω resistor |
| 🟢 Road 1 Green LED  | Cathode (−)    | GND                      |
| 📡 Road 1 HC-SR04    | TRIG           | D5                       |
| 📡 Road 1 HC-SR04    | ECHO           | D6                       |
| 📡 Road 1 HC-SR04    | VCC            | 5V                       |
| 📡 Road 1 HC-SR04    | GND            | GND                      |
| 🔴 Road 2 Red LED    | Anode (+)      | D7 through 220Ω resistor |
| 🔴 Road 2 Red LED    | Cathode (−)    | GND                      |
| 🟡 Road 2 Yellow LED | Anode (+)      | D8 through 220Ω resistor |
| 🟡 Road 2 Yellow LED | Cathode (−)    | GND                      |
| 🟢 Road 2 Green LED  | Anode (+)      | D9 through 220Ω resistor |
| 🟢 Road 2 Green LED  | Cathode (−)    | GND                      |
| 📡 Road 2 HC-SR04    | TRIG           | D10                      |
| 📡 Road 2 HC-SR04    | ECHO           | D11                      |
| 📡 Road 2 HC-SR04    | VCC            | 5V                       |
| 📡 Road 2 HC-SR04    | GND            | GND                      |
--------------------------------------------------------------------

<img width="1920" height="1080" alt="trific simulatio" src="https://github.com/user-attachments/assets/31296476-8f3e-4ff4-92c7-a08882edd0ed" />
