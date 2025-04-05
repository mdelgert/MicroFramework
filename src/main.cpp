#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  led.init();
  led.off();
  tft.init();
  button.init();
}

void loop()
{
  //tft.update();
  //led.flash();
  //button.update();
}