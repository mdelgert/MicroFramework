#include "globals.h"

void setup()
{
  logger.init();
  // Heap memory information
  logI("Free heap memory: %d bytes", ESP.getFreeHeap());
  logI("Total heap memory: %d bytes", ESP.getHeapSize());
  // Log the software version
  logI("Software version: %s", SOFTWARE_VERSION);
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