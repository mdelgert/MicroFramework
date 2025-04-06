#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  // example.init();
  // button.init();
  // led.init();
  // tft.init();
  
}

void loop()
{
  timer.update();
  // example.update();
  // button.update();
  // led.flash();
  // tft.update();
}