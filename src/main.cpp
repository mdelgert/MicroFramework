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
  //tft.printMessage("HELLO:", 5, 5, 20);
  //tft.printMessage("HELLO:", 5, 25, 20);
}

void loop()
{
  timer.update();
  network.update();
  button.update();
  tft.update();
}