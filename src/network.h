#pragma once

#ifndef ENABLE_NETWORK
#define ENABLE_NETWORK 1
#endif

#if ENABLE_NETWORK

class Network
{
public:
    static void init();
    static void update();
    static bool isConnected();
private:
};

#else

class Network
{
public:
    static void init() {}
    static void update() {}
    static bool isConnected() { return false; }
};

#endif

// Global reference
extern Network& network;