#include <Arduino.h>
#include "secrets.h"
#include "logger.h"

void setup() {
  Logger::init(); // Initialize the logger
  logV("0. Verbose logging is enabled.");
  logD("1  Debug logging is enabled.");
  logI("2. Info logging is enabled.");
  logW("3. Warning logging is enabled.");
  logE("4. Error logging is enabled.");
}

void loop() {
  // static int count = 0;
  // logI("Loop iteration %d started.", count);
  // count++;
  // delay(1000);
}