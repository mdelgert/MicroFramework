#include <Arduino.h>
#include "secrets.h"
#include "logger.h"

void setup() {
  //Logger::init(); // Initialize the logger
  logger.init(); // Initialize the logger

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