#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  network.init();
  ota.init();
  ntp.init();
  button.init();
  led.init();
  tft.init();
}

void loop()
{
  timer.update();
  network.update();
  ota.update();
  ntp.update();
  button.update();
  tft.update();
}