# Nexloft [ IoT x Automated Smart Home ]

## Abstract
Smart Home Automation with Arduino and ESP32

This project presents a comprehensive smart home system that integrates Arduino Uno and ESP32 microcontrollers to enhance safety, convenience, and energy efficiency.

## Arduino Uno Features:
-Automated Water Tank Refill: Prevents overflow and ensures efficient water management.

-Fire and Smoke Detection: Activates an alarm system in case of fire hazards to ensure household safety.

-Environmental Monitoring: Measures humidity and temperature to maintain a comfortable living environment.

-Smart Lighting: Controls light-dependent evening lights around the house, along with a motion-sensor light for the bathroom, maximizing energy 
 efficiency.
 
## ESP32 Features:

-Remote Control: Allows for seamless operation of lights from anywhere in the world via a mobile app.

-Remote Door Access: Provides a secure method for controlling entry to your home.

The system utilizes a serial connection between the ESP32 and Arduino Uno, enabling the transmission of sensor data, including humidity, temperature, fire hazard status, and water levels. This data exchange is facilitated through Blynk Cloud and the Blynk mobile app, ensuring effective monitoring and control.

This project aims to share insights and methodologies for creating a smart home system, making it accessible for others interested in exploring similar IoT applications.

## REQUIREMENTS

### Hardwares ⚙️
Microcontrollers :    Arduino Uno, Esp32

Sensors :    Flame Sensor, MQ2 Smoke Sensor, Ultrasonic Sensor, PIR Motion Sensor (Passive Infrared Sensor),
             LDR sensor Module, DHT11 Temperature & Humidity Sensor
          
Actuators :   Buzzer Module, L293D Motor Driver Module, 5V DC Pump Motor, LEDs, Servo Motor

### Softwares 💾
Arduino IDE

Blynk Libraries

Arduino IoT Cloud Library

Various Sensors and Acuators libraries

Arduino IoT |  Blynk apps [ You can directly control and monitor via web apps too ]

## SETUP INSTRUCTIONS

- Clone the repository

- Install required Library

- Compile and Upload Each Codes to corresponding microcontrollers

  You can check out the following walkthrough to how to quickly setup Arduino IoT Cloud and Blynk Cloud services on a single Esp32 Microcontroller
  
  [https://dev.to/mytx/blueprint1-arduino-cloud-x-blynk-cloud-integration-347]

- Read the full documentation here
  
 [https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/Smart%20Home.pdf]

## Acknowledgements
This project is a collaborative effort, and while I contributed approximately 90% of the codebase, the success of the smart home system is due to the hard work and dedication of the team. Their contributions in hardware installations, wiring, house architecture, design, building, decoration, pcb design, project management, testing and debugging were invaluable to the project's overall development. I appreciate their support and collaboration throughout this journey.

### Final Note:
This project was developed twice—once as a 2nd-year academic project and later as an improved version for a science fair. The pictures and testing video are from the first iteration, while the PCB design image is from the second iteration. The core functionality remains consistent, with enhancements made in the second version.

## VISUAL REPRESENTATION
![PCB Design](https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/20240701_154245.jpg?raw=true)

![Final Product](https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/photo_2_2024-12-21_21-22-09.jpg?raw=true)

![Software1](https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/photo_1_2024-12-21_21-42-02.jpg?raw=true)

![Software2](https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/photo_2_2024-12-21_21-42-02.jpg?raw=true)


You can watch the demo video of our projects in following link
![Demo Template](https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/photo_3_2024-12-21_21-42-02.jpg?raw=true)


![Demo Video](https://github.com/MythflashX/Nexloft-IoT-x-Automated-Smart-Home-/blob/main/resources/video_2024-12-21_21-27-21.mp4)





