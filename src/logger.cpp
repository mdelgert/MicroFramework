#include "logger.h"
#include <stdarg.h>

void Logger::init() {
#if ENABLE_LOGGING
    Serial.begin(115200);
    delay(1000);  // Optional: wait for Serial stabilization
    debugI("Logger initialized.");
#endif
}

void Logger::log(LogLevel level, const char* format, ...) {
#if ENABLE_LOGGING
    if (level < LOG_LEVEL) return;

    static char buffer[LOG_BUFFER_SIZE] = {0};

    // Get log level prefix
    const char* prefix = "";
    switch (level) {
        case LOG_LEVEL_VERBOSE: prefix = "[V] "; break;
        case LOG_LEVEL_DEBUG:   prefix = "[D] "; break;
        case LOG_LEVEL_INFO:    prefix = "[I] "; break;
        case LOG_LEVEL_WARNING: prefix = "[W] "; break;
        case LOG_LEVEL_ERROR:   prefix = "[E] "; break;
        default:                prefix = "[?] "; break;
    }

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    static char finalBuffer[LOG_BUFFER_SIZE] = {0};
    snprintf(finalBuffer, sizeof(finalBuffer), "%s%s", prefix, buffer);

    output(finalBuffer);
#endif
}

void Logger::output(const char* message) {
#if ENABLE_LOGGING
    Serial.println(message);
    // Extend here for TFT, SD, or network logging
#endif
}