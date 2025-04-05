#include "timer.h"
#include "globals.h"

#if ENABLE_TIMER

unsigned long Timer::last1Sec = 0;
unsigned long Timer::last30Sec = 0;
unsigned long Timer::last60Sec = 0;

bool Timer::oneSecondElapsed = false;
bool Timer::thirtySecondsElapsed = false;
bool Timer::sixtySecondsElapsed = false;

void Timer::init()
{
    last1Sec = millis();
    last30Sec = millis();
    last60Sec = millis();
}

void Timer::update()
{
    unsigned long currentMillis = millis();

    // Check for 1-second interval
    if (currentMillis - last1Sec >= 1000) {
        last1Sec = currentMillis;
        oneSecondElapsed = true;
        debugV("1 second elapsed");
    } else {
        oneSecondElapsed = false;
    }

    // Check for 30-second interval
    if (currentMillis - last30Sec >= 30000) {
        last30Sec = currentMillis;
        thirtySecondsElapsed = true;
        debugV("30 seconds elapsed");
    } else {
        thirtySecondsElapsed = false;
    }

    // Check for 60-second interval
    if (currentMillis - last60Sec >= 60000) {
        last60Sec = currentMillis;
        sixtySecondsElapsed = true;
        debugV("60 seconds elapsed");
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

#endif