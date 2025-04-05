#pragma once

#ifndef ENABLE_TIMER
#define ENABLE_TIMER 1
#endif

#if ENABLE_TIMER

#include <Arduino.h>

class Timer
{
public:
    static void init();
    static void update();
    static bool isOneSecondElapsed();
    static bool isThirtySecondsElapsed();
    static bool isSixtySecondsElapsed();

private:
    static unsigned long last1Sec;
    static unsigned long last30Sec;
    static unsigned long last60Sec;
    static bool oneSecondElapsed;
    static bool thirtySecondsElapsed;
    static bool sixtySecondsElapsed;
};

#else

class Timer
{
public:
    static void init() {}
    static void update() {}
    static bool isOneSecondElapsed() { return false; }
    static bool isThirtySecondsElapsed() { return false; }
    static bool isSixtySecondsElapsed() { return false; }
};

#endif

// External references
extern Timer& timer;