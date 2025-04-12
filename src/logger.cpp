#include "logger.h"

#if ENABLE_LOGGING

#include <stdarg.h>

void Logger::init()
{
    Serial.begin(115200);
    delay(1000); // Optional: wait for Serial stabilization
    debugI("Logger initialized.");
}

void Logger::log(LogLevel level, const char *format, ...)
{
    if (level < LOG_LEVEL)
        return;

    static char buffer[LOG_BUFFER_SIZE] = {0};

    // Get log level prefix
    const char *prefix = "";
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
}

void Logger::output(const char *message)
{
#if ENABLE_SERIAL_LOGGING
    Serial.println(message);
#endif

#if ENABLE_MQTT_LOGGING
    mqtt.sendMessage("logs/test", message);
#endif

#if ENABLE_TFT_LOGGING
    tft.printMessage(message, 0, 0, 128);
#endif
}

#endif