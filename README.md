**Temperature and Humidity Sensor with Web UI (Arduino - ESP8266)**

This project was developed during my internship at Deutsche Bank AG and involves creating a temperature and humidity monitoring system using an Arduino (ESP8266 microcontroller).  

The system collects real-time temperature and humidity data from a sensor, and displays it on a simple, user-friendly web interface.  

This way, users can view the environmental conditions in real-time by accessing the sensor data from any device on the same network.  

**Features**  
Real-time Sensor Data -> The sensor reads temperature and humidity levels and transmits them to the web server and interface.  
Simple Web UI -> The data is presented on a minimalistic web page, accessible over Wi-Fi, which automatically updates with the latest readings.  
Wireless Monitoring: -> Thanks to the ESP8266 processor's built-in Wi-Fi capabilities, the system can be accessed wirelessly from any web browser.  
Low Power Consumption -> Using the ESP8266 microcontroller ensures efficient energy usage.  

**Technologies Used**  
Arduino -> The core of the system, programmed in C++ using the Arduino IDE.  
ESP8266 Microcontroller -> A Wi-Fi-enabled microcontroller for real-time data reading and network communication.  
DHT11/DHT22 Sensor -> Used to measure temperature and humidity levels.  
HTML & CSS -> For building a simple web UI that displays sensor data.  
Embedded Web Server -> The ESP8266 hosts a web server that serves the web UI.  

**How It Works**  
1. The ESP8266 is programmed to read temperature and humidity data from the DHT11/DHT22 sensor at regular intervals.  
2. The ESP8266 hosts a small web server and serves a basic HTML page to display the data.  
3. When a user connects to the ESP8266's IP address using a web browser, the page is loaded, displaying the current temperature and humidity readings.  
4. The page auto-refreshes to keep the data updated in real-time.  

**Setup**  

USE the IoT_setup_guide.pdf for for the setup process (in German) or https://homeding.github.io/index.htm#page=/examples/develop.md (in English)  

@author Matthias Hertel, https://www.mathertel.de  

@Copyright Copyright (c) by Matthias Hertel, https://www.mathertel.de.  
  
This work is licensed under a BSD 3-Clause style license,
https://www.mathertel.de/License.aspx.  



More information on https://www.mathertel.de/Arduino  

