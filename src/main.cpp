#include "globals.h"

void setup()
{
  logger.init(); // Initialize the logger
  logI("Free heap memory: %d bytes", ESP.getFreeHeap());
  logI("Total heap memory: %d bytes", ESP.getHeapSize());
}

void loop()
{
  /*
  static int count = 0;
  logI("Loop iteration %d started.", count);
  count++;
  delay(1000);
  */
}