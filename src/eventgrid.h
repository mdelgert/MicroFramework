#pragma once

#ifndef ENABLE_EVENTGRID
#define ENABLE_EVENTGRID 0
#endif

#if ENABLE_EVENTGRID

class EventGrid
{
public:
    static void init();
    static void update();

private:

};

#else

class EventGrid
{
public:
    static void init() {}
    static void update() {}
};

#endif

// Global reference
extern EventGrid& eg;