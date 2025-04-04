#include <Arduino.h>
#include "secrets.h"
#include "logger.h"

void setup() {
  //Logger::init(); // Initialize the logger
  logger.init(); // Initialize the logger

  if (psramInit()) {
    Serial.println("✅ PSRAM initialized successfully!");
    Serial.printf("PSRAM total: %u bytes\n", ESP.getPsramSize());
    Serial.printf("PSRAM free : %u bytes\n", ESP.getFreePsram());
    } else {
      Serial.println("❌ PSRAM not found or failed to initialize");
  }

  logI("Free heap memory: %d bytes", ESP.getFreeHeap());
  logI("Total heap memory: %d bytes", ESP.getHeapSize());
  logI("Free PSRAM memory: %d bytes", ESP.getFreePsram());
  logI("Total PSRAM memory: %d bytes", ESP.getPsramSize());
}

void loop() {
  /*
  static int count = 0;
  logI("Loop iteration %d started.", count);
  count++;
  delay(1000);
  */
}