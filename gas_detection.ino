#include <ESP8266WiFi.h>

#define GAS_SENSOR A0
#define BUZZER D2

const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > 400) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("Gas Detected! Buzzer ON");
  } else {
    digitalWrite(BUZZER, LOW);
    Serial.println("Safe Environment");
  }

  delay(2000);
}
