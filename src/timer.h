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
    static uint64_t getUptimeSeconds();

private:
    static unsigned long lastOneSec;
    static unsigned long lastThirtySec;
    static unsigned long lastSixtySec;
    static bool oneSecondElapsed;
    static bool thirtySecondsElapsed;
    static bool sixtySecondsElapsed;
    static uint64_t uptimeSeconds;
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
    static uint64_t getUptimeSeconds() { return 0; }
};

#endif

// External references
extern Timer& timer;