// examples.cpp
#include "example.h"
#include "globals.h"

#if ENABLE_EXAMPLE

static int count = 0;

void Example::init()
{
    logI("Example initialized.");
    printInfo();
    printLoglevel();
}

void Example::update()
{
    logI("Loop iteration %d started.", count);
    count++;
    delay(1000);
}

void Example::printInfo()
{
    logI("Free heap memory: %d bytes", ESP.getFreeHeap());
    logI("Total heap memory: %d bytes", ESP.getHeapSize());
    logI("Software version: %s", SOFTWARE_VERSION);
    logI("Device name: %s", settings.getDeviceName());
}

void Example::printLoglevel()
{
    // Log levels
    logV("Current log level: VERBOSE");
    logD("Current log level: DEBUG");
    logI("Current log level: INFO");
    logW("Current log level: WARNING");
    logE("Current log level: ERROR");
}

#endif