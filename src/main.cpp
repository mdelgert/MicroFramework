#include "globals.h"

void setup()
{
  logger.init();
  timer.init();
  settings.init();
  led.init();
  led.off();
  tft.init();
  button.init();
}

void loop()
{
  timer.update();
  //tft.update();
  //led.flash();
  //button.update();
}