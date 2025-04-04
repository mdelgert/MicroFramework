#include "logger.h"
#include <stdarg.h>

void Logger::init() {
#if ENABLE_LOGGING
    Serial.begin(115200); // Initialize Serial (adjust baud rate as needed)
    delay(1000); // Wait for Serial to stabilize (optional)
    logI("Logger initialized.");
#endif
}

void Logger::log(uint8_t level, const char* format, ...) {
#if ENABLE_LOGGING
    if (level < LOG_LEVEL) return; // Skip if below current log level

    // Static buffer to avoid heap allocation
    static char buffer[LOG_BUFFER_SIZE];
    buffer[0] = '\0';

    // Prefix based on log level
    const char* prefix = "";
    switch (level) {
        case LOG_LEVEL_VERBOSE: prefix = "[V] "; break;
        case LOG_LEVEL_DEBUG:   prefix = "[D] "; break;
        case LOG_LEVEL_INFO:    prefix = "[I] "; break;
        case LOG_LEVEL_WARNING: prefix = "[W] "; break;
        case LOG_LEVEL_ERROR:   prefix = "[E] "; break;
        default: break;
    }

    // Format the message
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, LOG_BUFFER_SIZE, format, args);
    va_end(args);

    // Combine prefix and message
    char finalBuffer[LOG_BUFFER_SIZE];
    snprintf(finalBuffer, LOG_BUFFER_SIZE, "%s%s", prefix, buffer);

    output(finalBuffer);
#endif
}

void Logger::output(const char* message) {
#if ENABLE_LOGGING
    Serial.println(message); // Default output to Serial
    // Add alternative outputs here (e.g., file, network) if needed
#endif
}