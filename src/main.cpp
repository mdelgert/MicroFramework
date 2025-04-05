#include "globals.h"

void setup()
{
  logger.init();
  settings.init();
  led.init();
  led.off();
  gfx.init();
  gfx.test();
}

void loop()
{
  //gfx.update();
  //led.flash();
}