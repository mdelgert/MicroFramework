#pragma once

#ifndef ENABLE_EMPTY
#define ENABLE_EMPTY 0
#endif

#if ENABLE_EMPTY

class Empty
{
public:
    static void init();
    static void update();

private:

};

#else

class Empty
{
public:
    static void init() {}
    static void update() {}
};

#endif

// Global reference
extern Empty& empty;