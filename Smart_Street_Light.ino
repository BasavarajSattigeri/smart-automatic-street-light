#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3p1EbpWpQ"
#define BLYNK_TEMPLATE_NAME "Street Light"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Pins
#define LDR_PIN 34
#define IR1_PIN 26
#define IR2_PIN 27
#define IR3_PIN 33

#define LED1_PIN 18
#define LED2_PIN 19
#define LED3_PIN 32

bool lastLightState = false;  // To track ON/OFF state

void setup() {
  Serial.begin(115200);

  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  int ldrValue = analogRead(LDR_PIN);   // 0–4095
  int ir1State = digitalRead(IR1_PIN);  // LOW = object detected
  int ir2State = digitalRead(IR2_PIN);
  int ir3State = digitalRead(IR3_PIN);

  bool isDay = (ldrValue > 2000);
  bool lightsOn = false;

  if (isDay) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    lightsOn = false;
  } else {
    digitalWrite(LED1_PIN, (ir1State == LOW) ? HIGH : LOW);
    digitalWrite(LED2_PIN, (ir2State == LOW) ? HIGH : LOW);
    digitalWrite(LED3_PIN, (ir3State == LOW) ? HIGH : LOW);

    if (ir1State == LOW || ir2State == LOW || ir3State == LOW) {
      lightsOn = true;
    }
  }

  // Send notification only when state changes
  if (lightsOn != lastLightState) {
    if (lightsOn) {
      Blynk.logEvent("street_lights_on");
      Serial.println("Notification: Street lights ON");
    } else {
      Blynk.logEvent("street_lights_off");
      Serial.println("Notification: Street lights OFF");
    }

    lastLightState = lightsOn;
  }

  delay(200);
}
