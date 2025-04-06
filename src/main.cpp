#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  timer.init();
  network.init();
  // example.init();
  // button.init();
  // led.init();
  // tft.init();
  
}

void loop()
{
  timer.update();
  network.update();
  // example.update();
  // button.update();
  // led.flash();
  // tft.update();
}