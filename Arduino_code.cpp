// Name: Zunaira Ahmed
// Roll no: fa24b1-cs-030

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

