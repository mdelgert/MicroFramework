#pragma once

#ifndef ENABLE_WEB
#define ENABLE_WEB 1
#endif

#if ENABLE_WEB

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Web
{
private:
    static void notFound(AsyncWebServerRequest *request);

public:
    static void init();
};

#else

class Web
{
public:
    static void init() {}
};

#endif

// Global reference
extern Web& web;