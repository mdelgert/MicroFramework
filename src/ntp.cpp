#include "ntp.h"
#include "globals.h"

#if ENABLE_NTP

#include <time.h>

void Ntp::init()
{
    // Set the timezone to America/New_York
    configTime(-5 * 3600, 3600, "pool.ntp.org", "time.nist.gov"); // UTC-5 with DST adjustment
    debugI("NTP initialized. Waiting for time sync...");

    // Wait for time to be set
    struct tm timeInfo;
    if (!getLocalTime(&timeInfo, 10000))
    { // Wait up to 10 seconds
        debugE("Failed to obtain time from NTP servers.");
    }
    else
    {
        debugI("Time synchronized successfully.");
        debugI("Current time: %s", asctime(&timeInfo));
    }
}

void Ntp::update()
{
    // Check if the time is synchronized
    if(timer.isTenMinutesElapsed())
    {
        struct tm timeInfo;
        if (!getLocalTime(&timeInfo))
        {
            debugI("Time sync lost. Attempting to resync...");
            init(); // Reinitialize NTP if time sync is lost
            return;
        }
        else
        {
            debugI("Current time: %s", asctime(&timeInfo));
        }
    }

    /*
    if(timer.isOneSecondElapsed())
    {
        // Print the current time every 1 second
        struct tm timeInfo;
        if (getLocalTime(&timeInfo))
        {
            char timeString[26];
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", &timeInfo);
            debugI("Current time: %s", timeString);
        }
        else
        {
            debugE("Failed to get local time.");
        }
    }
    */
}

#endif