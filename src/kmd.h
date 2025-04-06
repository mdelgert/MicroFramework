#pragma once

#ifndef ENABLE_KMD
#define ENABLE_KMD 1
#endif

#if ENABLE_KMD

class Kmd
{
public:
    static void init();
    static void keyboardTest();
    static void mouseTest();
    
private:

};

#else

class Kmd
{
public:
    static void init() {}
    static void keyboardTest() {}
    static void mouseTest() {}
};

#endif

// Global reference
extern Kmd& kmd;