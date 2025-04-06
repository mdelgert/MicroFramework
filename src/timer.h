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
    static bool isHalfSecondElapsed();
    static bool isOneSecondElapsed();
    static bool isFifteenSecondsElapsed();
    static bool isThirtySecondsElapsed();
    static bool isOneMinuteElapsed();
    static bool isFifteenMinutesElapsed();
    static bool isThirtyMinutesElapsed();
    static bool isOneHourElapsed();
    static uint64_t getUptimeSeconds();

private:
    static uint32_t lastHalfSec;
    static uint32_t lastOneSec;
    static uint32_t lastFifteenSec;
    static uint32_t lastThirtySec;
    static uint32_t lastOneMin;
    static uint32_t lastFifteenMin;
    static uint32_t lastThirtyMin;
    static uint32_t lastOneHour;
    static uint64_t uptimeSeconds;

    static bool halfSecondElapsed;
    static bool oneSecondElapsed;
    static bool fifteenSecondsElapsed;
    static bool thirtySecondsElapsed;
    static bool oneMinuteElapsed;
    static bool fifteenMinutesElapsed;
    static bool thirtyMinutesElapsed;
    static bool oneHourElapsed;
};

#else

class Timer
{
public:
    static void init() {}
    static void update() {}
    static bool isHalfSecondElapsed() { return false; }
    static bool isOneSecondElapsed() { return false; }
    static bool isFifteenSecondsElapsed() { return false; }
    static bool isThirtySecondsElapsed() { return false; }
    static bool isOneMinuteElapsed() { return false; }
    static bool isFifteenMinutesElapsed() { return false; }
    static bool isThirtyMinutesElapsed() { return false; }
    static bool isOneHourElapsed() { return false; }
    static uint64_t getUptimeSeconds() { return 0; }
};

#endif

// External references
extern Timer &timer;