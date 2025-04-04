#include "secrets.h"  // Include your secrets header file
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Print a message to the Serial Monitor with a number
  static int count = 0;
  Serial.print("Test: ");
  Serial.println(count);
  count++;

  // Print the device name and Wi-Fi credentials
  Serial.print("Device Name: ");
  Serial.println(SECURE_DEVICE_NAME);
  Serial.print("Wi-Fi SSID: ");
  Serial.println(SECURE_WIFI_SSID);
  Serial.print("Wi-Fi Password: ");
  Serial.println(SECURE_WIFI_PASSWORD);

  delay(1000);
}