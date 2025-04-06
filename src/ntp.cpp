#include "ntp.h"
#include "globals.h"

#if ENABLE_NTP

#include <time.h>

// Helper function (could also be static or in a namespace)
void logCurrentTime(const struct tm& timeInfo) {
    debugI("Current time: %s", asctime(&timeInfo));
}

void Ntp::update() {
    if (!timer.isOneHourElapsed()) {
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

void Ntp::init() {
    const int syncTimeoutMs = 10000; // 10 seconds timeout
    const char *ntpServer1 = "time.google.com";
    const char *ntpServer2 = "time.cloudflare.com";
    const char *ntpServer3 = "pool.ntp.org"; //time.nist.gov
    //const char* defaultTimezone = "America/New_York";
    
    //setenv("TZ", defaultTimezone, 1); // 1 means overwrite existing value
    setenv("TZ", settings.getTimezone(), 1); // 1 means overwrite existing value

    tzset(); // Apply the timezone settings

    // Configure NTP servers (no manual offset needed since TZ handles it)
    configTime(0, 0, ntpServer1, ntpServer2, ntpServer3);

    // Log the timezone being set
    debugI("NTP initialized. Waiting for time sync with timezone: %s", settings.getTimezone());

    struct tm timeInfo;
    if (!getLocalTime(&timeInfo, syncTimeoutMs)) {
        debugE("Failed to obtain time from NTP servers after %d ms", syncTimeoutMs);
        return;
    }

    debugI("Time synchronized successfully.");
    logCurrentTime(timeInfo);

    // Determine offset and DST status
    int isDst = timeInfo.tm_isdst > 0 ? 1 : 0; // DST active if > 0
    long offsetSeconds = isDst ? (-4 * 3600) : (-5 * 3600); // EDT = -4h, EST = -5h
    debugI("Current timezone offset: %ld seconds, DST: %d", offsetSeconds, isDst);
}

/*
void Ntp::init()
{
    // Set timezone to America/New_York using TZ environment variable
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
*/

#endif // ENABLE_NTP