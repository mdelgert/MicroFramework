#pragma once

#ifndef ENABLE_LFS
#define ENABLE_LFS 1
#endif

#ifndef LOG_FILE
#define LOG_FILE "/debug.log"
#endif

#if ENABLE_LFS

class Lfs
{
public:
    static void init();
    static void deleteFile(const char *filename);
    static void logToFile(const char *message);
};

#else

class Lfs
{
public:
    static void init() {}
    static void deleteFile(const char *filename) {}
    static void logToFile(const char *message) {}
};

#endif

// Global reference
extern Lfs& lfs;