#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  led.init();
  example.init();
}

void loop()
{
  led.flash();
}