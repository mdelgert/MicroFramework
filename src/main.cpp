#include "globals.h"

void setup()
{
  logger.setup();
  settings.setup();
  example.setup();
}

void loop()
{
  example.loop();
}