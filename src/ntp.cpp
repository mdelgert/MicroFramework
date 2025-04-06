#include "ntp.h"
#include "globals.h"

#if ENABLE_NTP

#include <time.h>

// Helper function (could also be static or in a namespace)
void logCurrentTime(const struct tm& timeInfo) {
    debugI("Current time: %s", asctime(&timeInfo));
}

// Set the timezone to America/New_York (UTC-5 with DST adjustment)
void Ntp::init() {
    const int EST_OFFSET_SECONDS = -5 * 3600;    // UTC-5 hours in seconds
    const int DST_OFFSET_SECONDS = 3600;         // Daylight Saving Time offset
    const int SYNC_TIMEOUT_MS = 10000;           // 10 seconds timeout
    const char* NTP_SERVER1 = "time.cloudflare.com";
    const char* NTP_SERVER2 = "time.google.com";
    const char* NTP_SERVER3 = "pool.ntp.org"; //time.nist.gov

    configTime(EST_OFFSET_SECONDS, DST_OFFSET_SECONDS, NTP_SERVER1, NTP_SERVER2, NTP_SERVER3);
    debugI("NTP initialized. Waiting for time sync...");

    struct tm timeInfo;
    if (!getLocalTime(&timeInfo, SYNC_TIMEOUT_MS)) {
        debugE("Failed to obtain time from NTP servers after %d ms", SYNC_TIMEOUT_MS);
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