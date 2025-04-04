#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  // Log the device name
  logI("Device name: %s", settings.getDeviceName());
}

void loop()
{
  /*
  logI("Free heap memory: %d bytes", ESP.getFreeHeap());
  logI("Total heap memory: %d bytes", ESP.getHeapSize());
  logI("Software version: %s", SOFTWARE_VERSION);
  static int count = 0;
  logI("Loop iteration %d started.", count);
  count++;
  delay(1000);
  */
}