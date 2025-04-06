#include "ntp.h"
#include "globals.h"

#if ENABLE_NTP

#include <time.h>

// Helper function (could also be static or in a namespace)
void logCurrentTime(const struct tm& timeInfo) {
    debugI("Current time: %s", asctime(&timeInfo));
}

// Set the timezone to America/New_York (UTC-5 with DST adjustment)
void Ntp::init()
{
    const long gmtOffsetSec = -5 * 3600; // GMT offset in seconds
    const int daylightOffsetSec = 3600;  // Daylight Saving Time offset in seconds
    const int syncTimeoutMs = 10000; // 10 seconds timeout
    const char *ntpServer1 = "time.google.com";
    const char *ntpServer2 = "time.cloudflare.com";
    const char *ntpServer3 = "pool.ntp.org"; //time.nist.gov

    configTime(gmtOffsetSec, daylightOffsetSec, ntpServer1, ntpServer2, ntpServer3);
    debugI("NTP initialized. Waiting for time sync...");

    // Wait for time to be set
    struct tm timeInfo;
    if (!getLocalTime(&timeInfo, syncTimeoutMs))
    {
        debugE("Failed to obtain time from NTP servers after %d ms", syncTimeoutMs);
        return;
    }

    debugI("Time synchronized successfully.");
    logCurrentTime(timeInfo);
}

void Ntp::update() {
    if (!timer.isTenMinutesElapsed()) {
        return;
    }

    struct tm timeInfo;
    if (!getLocalTime(&timeInfo)) {
        debugI("Time sync lost. Attempting to resync...");
        init();
        return;
    }

    logCurrentTime(timeInfo);
}

#endif // ENABLE_NTP