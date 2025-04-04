#pragma once

#include <Arduino.h>

// Configuration
#define LOG_BUFFER_SIZE 128  // Max size for log messages (adjust based on needs)
#define LOG_LEVEL_VERBOSE 0  // Log levels
#define LOG_LEVEL_DEBUG   1
#define LOG_LEVEL_INFO    2
#define LOG_LEVEL_WARNING 3
#define LOG_LEVEL_ERROR   4

// Default log level (can be overridden in platformio.ini)
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_INFO
#endif

// Centralized logging control (defined in platformio.ini)
#ifndef ENABLE_LOGGING
#define ENABLE_LOGGING 1  // Default to enabled
#endif

// Logging macros
#if ENABLE_LOGGING
    #define logV(...) Logger::log(LOG_LEVEL_VERBOSE, __VA_ARGS__)
    #define logD(...) Logger::log(LOG_LEVEL_DEBUG, __VA_ARGS__)
    #define logI(...) Logger::log(LOG_LEVEL_INFO, __VA_ARGS__)
    #define logW(...) Logger::log(LOG_LEVEL_WARNING, __VA_ARGS__)
    #define logE(...) Logger::log(LOG_LEVEL_ERROR, __VA_ARGS__)
#else
    // Empty macros when logging is disabled (zero runtime cost)
    #define logV(...) do {} while (0)
    #define logD(...) do {} while (0)
    #define logI(...) do {} while (0)
    #define logW(...) do {} while (0)
    #define logE(...) do {} while (0)
#endif

class Logger {
public:
    static void init();
    static void log(uint8_t level, const char* format, ...);

private:
    static void output(const char* message);
};