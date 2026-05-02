# 🌱 Smart Crop Stress Detection System

## 📌 Overview
The Smart Crop Stress Detection System is an IoT-based solution designed to monitor crop health in real-time and automate irrigation based on environmental conditions. The system uses an ESP32 microcontroller integrated with multiple sensors to detect stress levels in crops and control a water pump accordingly.

---

## 🎯 Objective
To develop an intelligent system that:
- Monitors environmental parameters affecting crop health  
- Detects stress conditions using sensor data  
- Automates irrigation to optimize water usage  
- Enables remote monitoring through IoT  

---

## ⚙️ System Architecture
The system consists of:
- ESP32 microcontroller (core processing unit)  
- Sensors for data collection  
- Relay module for pump control  
- IoT platform for remote monitoring  

---

## 🧩 Components Used
- ESP32  
- Capacitive Soil Moisture Sensor  
- DHT11 (Temperature & Humidity Sensor)  
- BH1750 (Light Intensity Sensor)  
- Relay Module  
- Water Pump  
- 5V Power Adapter  

---

## 🔧 Working Principle
1. Sensors continuously collect environmental data:
   - Soil moisture  
   - Temperature & humidity  
   - Light intensity  

2. The ESP32 processes this data to determine crop stress conditions.

3. If stress is detected (e.g., low soil moisture):
   - The relay module activates the water pump  
   - Irrigation is automatically triggered  

4. All sensor data and system status are updated in real-time on the Blynk dashboard.

---

## 🌐 Features
- Real-time crop monitoring  
- Automated irrigation system  
- Remote monitoring via Blynk  
- Efficient water usage  
- Sensor-based decision making  

---

## 🛠️ Technologies Used
- Embedded C  
- ESP32 (Wi-Fi enabled microcontroller)  
- IoT (Blynk Platform)  
- Communication: Wi-Fi  

---

## 📊 Output
- Live sensor data displayed on Blynk dashboard  
- Automatic pump activation based on stress conditions  

---

## 🚀 Future Enhancements
- Integration of Machine Learning for better stress prediction  
- Mobile notifications for alerts  
- Cloud data storage and analytics  
- Solar-powered system for sustainability  

---

## 👩‍💻 Author
Sneha Gorla  
B.Tech ECE | Embedded Systems & IoT Enthusiast  

---

## 📎 Note
This project demonstrates practical implementation of IoT in agriculture, focusing on automation and efficient resource management.
