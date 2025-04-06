#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  network.init();
  button.init();
  led.init();
  tft.init();
}

void loop()
{
  timer.update();
  network.update();
  button.update();
  tft.update();
}