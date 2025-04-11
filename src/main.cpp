#include "globals.h"

void setup()
{
  logger.init();
  // settings.clear();
  // settings.setDefaults();
  settings.init();
  lfs.init();
  timer.init();
  network.init();
  ntp.init();
  ota.init();
  mqtt.init();
  button.init();
  led.init();
  tft.init();
  kmd.init();
  web.init();
}

void loop()
{
  timer.update();
  network.update();
  ntp.update();
  ota.update();
  mqtt.update();
  button.update();
  led.flash();
  tft.update();
}