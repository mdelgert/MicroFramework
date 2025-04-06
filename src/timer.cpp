#include "timer.h"
#include "globals.h"

#if ENABLE_TIMER

// Static member initialization
uint32_t Timer::lastOneSec = 0;
uint32_t Timer::lastThirtySec = 0;
uint32_t Timer::lastSixtySec = 0;
uint64_t Timer::uptimeSeconds = 0;

bool Timer::oneSecondElapsed = false;
bool Timer::thirtySecondsElapsed = false;
bool Timer::sixtySecondsElapsed = false;

// Helper function to check if a time interval has elapsed
static bool hasIntervalElapsed(uint32_t &lastTime, uint32_t interval)
{
    uint32_t currentMillis = millis();
    if (currentMillis - lastTime >= interval) {
        lastTime = currentMillis;
        return true;
    }
    return false;
}

void Timer::init()
{
    uint32_t currentMillis = millis();
    lastOneSec = currentMillis;
    lastThirtySec = currentMillis;
    lastSixtySec = currentMillis;
    uptimeSeconds = 0;
}

void Timer::update()
{
    // Check for 1-second interval
    oneSecondElapsed = hasIntervalElapsed(lastOneSec, 1000);

    // Check for 30-second interval
    thirtySecondsElapsed = hasIntervalElapsed(lastThirtySec, 30000);

    // Check for 60-second interval
    sixtySecondsElapsed = hasIntervalElapsed(lastSixtySec, 60000);

    // Update uptime seconds only if one second has elapsed
    if (oneSecondElapsed) {
        uptimeSeconds++;
        debugV("Uptime: %llu seconds", uptimeSeconds);
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

uint64_t Timer::getUptimeSeconds()
{
    return uptimeSeconds;
}

#endif