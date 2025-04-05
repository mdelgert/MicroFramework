#include "example.h"
#include "globals.h"

#if ENABLE_EXAMPLE

static int count = 0;

void Example::init()
{
    debugI("Example initialized.");
    printInfo();
    printLoglevel();
}

void Example::update()
{
    debugI("Loop iteration %d started.", count);
    count++;
    delay(1000);
}

void Example::printInfo()
{
    debugI("Free heap memory: %d bytes", ESP.getFreeHeap());
    debugI("Total heap memory: %d bytes", ESP.getHeapSize());
    debugI("Software version: %s", SOFTWARE_VERSION);
    debugI("Device name: %s", settings.getDeviceName());
}

void Example::printLoglevel()
{
    // Log levels
    debugV("Current log level: VERBOSE");
    debugD("Current log level: DEBUG");
    debugI("Current log level: INFO");
    debugW("Current log level: WARNING");
    debugE("Current log level: ERROR");
}

#endif