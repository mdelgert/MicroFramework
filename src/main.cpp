#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  network.init();
  ntp.init();
  ota.init();
  mqtt.init();
  button.init();
  led.init();
  tft.init();
}

void loop()
{
  timer.update();
  network.update();
  ntp.update();
  ota.update();
  mqtt.update();
  button.update();
  tft.update();
}