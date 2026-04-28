## 👩‍💻 Author
**Zunaira Ahmed**  
*Computer Science Student | Assembly Language Enthusiast*

# 🚀 IoT Motion Detection System using ESP32 & PIR Sensor

![GitHub repo size](https://img.shields.io/github/repo-size/your-username/your-repo-name)
![GitHub stars](https://img.shields.io/github/stars/your-username/your-repo-name?style=social)
![GitHub forks](https://img.shields.io/github/forks/your-username/your-repo-name?style=social)
![GitHub issues](https://img.shields.io/github/issues/your-username/your-repo-name)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

---

## 📌 Overview
This project implements a **real-time motion detection system** using an ESP32 microcontroller and a PIR (Passive Infrared) sensor. When motion is detected, the system sends instant alerts to a smartphone using the **Blynk IoT platform**.

---

## 🧰 Components Used
- ESP32 Development Board  
- PIR Motion Sensor (HC-SR501)  
- Breadboard  
- Jumper Wires  
- Micro-USB Cable  
- Smartphone with Blynk App  
- Wi-Fi Connection  

---

## 🔌 Circuit Connections

| PIR Sensor Pin | ESP32 Connection |
|----------------|------------------|
| VCC            | 3.3V             |
| GND            | GND              |
| OUT            | GPIO 14          |

---

## 📱 Blynk Setup
1. Install the **Blynk IoT App**  
2. Create a new project  
3. Select:
   - Device: ESP32 Dev Board  
   - Connection: Wi-Fi  
4. Add Notification widget and LED widget (V0)  
5. Copy Auth Token  

---

## 💻 Arduino Code

```cpp
// Name: Rimsha Shakeel
// Roll no: fa24b1-cs-002

#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Motion Detector"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "Your_WiFi_SSID"; 
char pass[] = "Your_WiFi_Password"; 

int pirPin = 14;      
int pirValue = 0;     

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  pirValue = digitalRead(pirPin);

  if (pirValue == HIGH) {
    Serial.println("Motion Detected!");
    Blynk.virtualWrite(V0, 255); 
    Blynk.logEvent("motion_detected", "Motion Detected!");
    delay(2000);
  } else {
    Blynk.virtualWrite(V0, 0);   
  }
}