// examples.cpp
#include "example.h"
#include "globals.h"

#if ENABLE_EXAMPLE

static int count = 0;

void Example::init()
{
    logI("Example initialized.");
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

#endif