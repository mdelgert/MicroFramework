#include "timer.h"
#include "globals.h"

#if ENABLE_TIMER

// Static member initialization
uint64_t Timer::uptimeSeconds = 0;
uint32_t Timer::lastOneSec = 0;
uint32_t Timer::lastThirtySec = 0;
uint32_t Timer::lastOneMin = 0;
uint32_t Timer::lastFiveMin = 0;
uint32_t Timer::lastTenMin = 0;

bool Timer::oneSecondElapsed = false;
bool Timer::thirtySecondsElapsed = false;
bool Timer::oneMinuteElapsed = false;
bool Timer::fiveMinutesElapsed = false;
bool Timer::tenMinutesElapsed = false;

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
    uptimeSeconds = 0;
    uint32_t currentMillis = millis();
    lastOneSec = currentMillis;
    lastThirtySec = currentMillis;
    lastOneMin = currentMillis;
    lastFiveMin = currentMillis;
    lastTenMin = currentMillis;
}

void Timer::update()
{
    // Check for 1-second interval
    oneSecondElapsed = hasIntervalElapsed(lastOneSec, 1000);

    // Check for 30-second interval
    thirtySecondsElapsed = hasIntervalElapsed(lastThirtySec, 30000);

    // Check for 1-minute interval (60,000 ms)
    oneMinuteElapsed = hasIntervalElapsed(lastOneMin, 60000);

    // Check for 5-minute interval (300,000 ms)
    fiveMinutesElapsed = hasIntervalElapsed(lastFiveMin, 300000);

    // Check for 10-minute interval (600,000 ms)
    tenMinutesElapsed = hasIntervalElapsed(lastTenMin, 600000);
    
    // Update uptime seconds
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

bool Timer::isOneMinuteElapsed()
{
    return oneMinuteElapsed;
}

bool Timer::isFiveMinutesElapsed()
{
    return fiveMinutesElapsed;
}

bool Timer::isTenMinutesElapsed()
{
    return tenMinutesElapsed;
}

uint64_t Timer::getUptimeSeconds()
{
    return uptimeSeconds;
}

#endif