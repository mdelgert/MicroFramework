#include "timer.h"
#include "globals.h"

#if ENABLE_TIMER

unsigned long Timer::lastOneSec = 0;
unsigned long Timer::lastThirtySec = 0;
unsigned long Timer::lastSixtySec = 0;
uint64_t Timer::uptimeSeconds = 0;

bool Timer::oneSecondElapsed = false;
bool Timer::thirtySecondsElapsed = false;
bool Timer::sixtySecondsElapsed = false;

void Timer::init()
{
    lastOneSec = millis();
    lastThirtySec = millis();
    lastSixtySec = millis();
}

void Timer::update()
{
    unsigned long currentMillis = millis();

    // Check for 1-second interval
    if (currentMillis - lastOneSec >= 1000) {
        lastOneSec = currentMillis;
        oneSecondElapsed = true;
        uptimeSeconds++;
        //debugV("1 second elapsed");
        debugV("Uptime: %llu seconds", uptimeSeconds);
    } else {
        oneSecondElapsed = false;
    }

    // Check for 30-second interval
    if (currentMillis - lastThirtySec >= 30000) {
        lastThirtySec = currentMillis;
        thirtySecondsElapsed = true;
        //debugV("30 seconds elapsed");
    } else {
        thirtySecondsElapsed = false;
    }

    // Check for 60-second interval
    if (currentMillis - lastSixtySec >= 60000) {
        lastSixtySec = currentMillis;
        sixtySecondsElapsed = true;
        //debugV("60 seconds elapsed");
    } else {
        sixtySecondsElapsed = false;
    }
}

bool Timer::isOneSecondElapsed()
{
    return oneSecondElapsed;
}

bool Timer::isThirtySecondsElapsed()
{
    return thirtySecondsElapsed;
}

bool Timer::isSixtySecondsElapsed()
{
    return sixtySecondsElapsed;
}

unsigned long long Timer::getUptimeSeconds()
{
    return uptimeSeconds;
}

#endif