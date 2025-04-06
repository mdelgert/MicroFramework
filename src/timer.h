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
    static uint64_t getUptimeSeconds();
    static bool isOneSecondElapsed();
    static bool isThirtySecondsElapsed();
    static bool isOneMinuteElapsed();
    static bool isFiveMinutesElapsed();
    static bool isTenMinutesElapsed();
    
private:
    static uint64_t uptimeSeconds;
    static uint32_t lastOneSec;
    static uint32_t lastThirtySec;
    static uint32_t lastOneMin;
    static uint32_t lastFiveMin;
    static uint32_t lastTenMin;

    static bool oneSecondElapsed;
    static bool thirtySecondsElapsed;
    static bool oneMinuteElapsed;
    static bool fiveMinutesElapsed;
    static bool tenMinutesElapsed;
};

#else

class Timer
{
public:
    static void init() {}
    static void update() {}
    static uint64_t getUptimeSeconds() { return 0; }
    static bool isOneSecondElapsed() { return false; }
    static bool isThirtySecondsElapsed() { return false; }
    static bool isOneMinuteElapsed() { return false; }
    static bool isFiveMinutesElapsed() { return false; }
    static bool isTenMinutesElapsed() { return false; }
};

#endif

// External references
extern Timer &timer;