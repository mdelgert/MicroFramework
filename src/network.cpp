#include "network.h"
#include "globals.h"

#if ENABLE_NETWORK

#include <WiFi.h>

void Network::init()
{
    // Initialize WiFi
    debugI("Initializing Network...");
    WiFi.mode(WIFI_STA);
    WiFi.begin(settings.getWifiSSID(), settings.getWifiPassword());
}

void Network::update()
{
    
}

#endif