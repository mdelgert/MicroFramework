#include "timer.h"

#if ENABLE_TIMER

#include <WiFi.h>

// Static member initialization
uint32_t Timer::lastHalfSec = 0;
uint32_t Timer::lastOneSec = 0;
uint32_t Timer::lastFifteenSec = 0;
uint32_t Timer::lastThirtySec = 0;
uint32_t Timer::lastOneMin = 0;
uint32_t Timer::lastFifteenMin = 0;
uint32_t Timer::lastThirtyMin = 0;
uint32_t Timer::lastOneHour = 0;
uint64_t Timer::uptimeSeconds = 0;

bool Timer::halfSecondElapsed = false;
bool Timer::oneSecondElapsed = false;
bool Timer::fifteenSecondsElapsed = false;
bool Timer::thirtySecondsElapsed = false;
bool Timer::oneMinuteElapsed = false;
bool Timer::fifteenMinutesElapsed = false;
bool Timer::thirtyMinutesElapsed = false;
bool Timer::oneHourElapsed = false;

// Helper function to check if a time interval has elapsed
static bool hasIntervalElapsed(uint32_t &lastTime, uint32_t interval)
{
    uint32_t currentMillis = millis();
    if (currentMillis - lastTime >= interval)
    {
        lastTime = currentMillis;
        return true;
    }
    return false;
}

void Timer::init()
{
    uint32_t currentMillis = millis();
    lastHalfSec = currentMillis;
    lastOneSec = currentMillis;
    lastFifteenSec = currentMillis;
    lastThirtySec = currentMillis;
    lastOneMin = currentMillis;
    lastFifteenMin = currentMillis;
    lastThirtyMin = currentMillis;
    lastOneHour = currentMillis;
    uptimeSeconds = 0;
}

void Timer::update()
{
    // Check for half-second interval
    halfSecondElapsed = hasIntervalElapsed(lastHalfSec, 500);

    // Check for 1-second interval
    oneSecondElapsed = hasIntervalElapsed(lastOneSec, 1000);

    // Check for 15-second interval
    fifteenSecondsElapsed = hasIntervalElapsed(lastFifteenSec, 15000);

    // Check for 30-second interval
    thirtySecondsElapsed = hasIntervalElapsed(lastThirtySec, 30000);

    // Check for 1-minute interval (60,000 ms)
    oneMinuteElapsed = hasIntervalElapsed(lastOneMin, 60000);

    // Check for 15-minute interval (900,000 ms)
    fifteenMinutesElapsed = hasIntervalElapsed(lastFifteenMin, 900000);

    // Check for 30-minute interval (1,800,000 ms)
    thirtyMinutesElapsed = hasIntervalElapsed(lastThirtyMin, 1800000);

    // Check for 1-hour interval (3,600,000 ms)
    oneHourElapsed = hasIntervalElapsed(lastOneHour, 3600000);

    // Update uptime seconds
    if (oneSecondElapsed)
    {
        uptimeSeconds++;
        //printDebug();
    }
}

bool Timer::isHalfSecondElapsed()
{
    return halfSecondElapsed;
}

bool Timer::isOneSecondElapsed()
{
    return oneSecondElapsed;
}

bool Timer::isFifteenSecondsElapsed()
{
    return fifteenSecondsElapsed;
}

bool Timer::isThirtySecondsElapsed()
{
    return thirtySecondsElapsed;
}

bool Timer::isOneMinuteElapsed()
{
    return oneMinuteElapsed;
}

bool Timer::isFifteenMinutesElapsed()
{
    return fifteenMinutesElapsed;
}

bool Timer::isThirtyMinutesElapsed()
{
    return thirtyMinutesElapsed;
}

bool Timer::isOneHourElapsed()
{
    return oneHourElapsed;
}

uint64_t Timer::getUptimeSeconds()
{
    return uptimeSeconds;
}

void Timer::printDebug()
{
    // debugV("Last Half Sec: %u ms", lastHalfSec);
    // debugV("Last One Sec: %u ms", lastOneSec);
    // debugV("Last Fifteen Sec: %u ms", lastFifteenSec);
    // debugV("Last Thirty Sec: %u ms", lastThirtySec);
    // debugV("Last One Min: %u ms", lastOneMin);
    // debugV("Last Fifteen Min: %u ms", lastFifteenMin);
    // debugV("Last Thirty Min: %u ms", lastThirtyMin);
    // debugV("Last One Hour: %u ms", lastOneHour);
    // debugV("Uptime Seconds: %llu", uptimeSeconds);
    debugV("Uptime: %llu seconds", uptimeSeconds);
    debugV("Free heap: %d bytes", ESP.getFreeHeap());
    if (WiFi.status() == WL_CONNECTED)
    {
        debugV("IP Address: %s", WiFi.localIP().toString().c_str());
    }
    else
    {
        debugV("WiFi Status: Disconnected");
    }
}

#endif