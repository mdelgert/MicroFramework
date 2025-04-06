#pragma once

#include "globals.h"

// Max size for log messages
constexpr size_t LOG_BUFFER_SIZE = 128;

// Log level definitions
enum LogLevel : uint8_t {
    LOG_LEVEL_VERBOSE = 0,
    LOG_LEVEL_DEBUG   = 1,
    LOG_LEVEL_INFO    = 2,
    LOG_LEVEL_WARNING = 3,
    LOG_LEVEL_ERROR   = 4
};

// Default log level (overridable via build flags)
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_INFO
#endif

// Logging enable flag (can be overridden in platformio.ini)
#ifndef ENABLE_LOGGING
#define ENABLE_LOGGING 1
#endif

#if ENABLE_LOGGING
    #define logV(...) Logger::log(LOG_LEVEL_VERBOSE, __VA_ARGS__)
    #define logD(...) Logger::log(LOG_LEVEL_DEBUG,   __VA_ARGS__)
    #define logI(...) Logger::log(LOG_LEVEL_INFO,    __VA_ARGS__)
    #define logW(...) Logger::log(LOG_LEVEL_WARNING, __VA_ARGS__)
    #define logE(...) Logger::log(LOG_LEVEL_ERROR,   __VA_ARGS__)

    // Remote Debug aliases
    #define debugV logV
    #define debugD logD
    #define debugI logI
    #define debugW logW
    #define debugE logE
#else
    // No-ops to eliminate runtime overhead
    #define logV(...) do {} while (0)
    #define logD(...) do {} while (0)
    #define logI(...) do {} while (0)
    #define logW(...) do {} while (0)
    #define logE(...) do {} while (0)

    #define debugV(...) do {} while (0)
    #define debugD(...) do {} while (0)
    #define debugI(...) do {} while (0)
    #define debugW(...) do {} while (0)
    #define debugE(...) do {} while (0)
#endif

class Logger {
public:
    static void init();
    static void log(LogLevel level, const char* format, ...);

private:
    static void output(const char* message);
};

// Global reference
extern Logger& logger;