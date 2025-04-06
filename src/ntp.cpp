#include "ntp.h"
#include "globals.h"

#if ENABLE_NTP

#include <time.h>

void Ntp::init()
{
    // Set the timezone to America/New_York (UTC-5 with DST adjustment)
    const long gmtOffsetSec = -5 * 3600; // GMT offset in seconds
    const int daylightOffsetSec = 3600;  // Daylight Saving Time offset in seconds
    const char *ntpServer1 = "time.google.com";
    const char *ntpServer2 = "time.cloudflare.com";
    const char *ntpServer3 = "pool.ntp.org"; //time.nist.gov

    configTime(gmtOffsetSec, daylightOffsetSec, ntpServer1, ntpServer2, ntpServer3);
    debugI("NTP initialized. Waiting for time sync...");

    // Wait for time to be set
    struct tm timeInfo;
    if (!getLocalTime(&timeInfo, 10000)) // Wait up to 10 seconds
    {
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
    // Periodically check if the time is synchronized
    if (timer.isTenMinutesElapsed())
    {
        struct tm timeInfo;
        if (!getLocalTime(&timeInfo))
        {
            debugW("Time sync lost. Attempting to resync...");
            init(); // Reinitialize NTP if time sync is lost
        }
        else
        {
            debugI("Current time: %s", asctime(&timeInfo));
        }
    }
}

#endif