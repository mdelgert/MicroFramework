#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  //network.init();
  //ntp.init();
  //ota.init();
  mqtt.init();
  button.init();
  led.init();
  tft.init();
  kmd.init();
  // This will reboot if network is not connected after a timeout
  //web.init();
}

void loop()
{
  timer.update();
  //network.update();
  //ntp.update();
  //ota.update();
  mqtt.update();
  button.update();
  tft.update();
}