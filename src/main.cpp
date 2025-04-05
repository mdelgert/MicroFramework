#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  button.init();
  led.init();
  led.off();
  tft.init();
  
}

void loop()
{
  timer.update();
  button.update();
  tft.update();
  led.flash();
  example.update();
}