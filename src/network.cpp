#include "network.h"
#include "globals.h"

#if ENABLE_NETWORK

#include <WiFi.h>

void Network::init()
{
// Connect to WiFi if not already connected
    if (!isConnected()) {
        debugI("Connecting to WiFi...");
        debugI("SSID: %s", settings.getWifiSSID());
        debugI("Password: %s", settings.getWifiPassword());
        // Attempt to connect to WiFi
        WiFi.mode(WIFI_STA); // Set WiFi mode to Station
        WiFi.disconnect(); // Clear any previous connection
        if(timer.isOneSecondElapsed)
        {
            WiFi.begin(settings.getWifiSSID(), settings.getWifiPassword());
        }
    }
}

void Network::update()
{
    // Check if WiFi is connected
    if(timer.isSixtySecondsElapsed)
    {
        if(!isConnected()) {
            debugW("WiFi not connected, trying to reconnect...");
            init();
        }
    }
}

bool Network::isConnected()
{
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
        debugI("Network is connected: %s", WiFi.localIP().toString().c_str());
        return true;
    } else {
        debugW("Network not connected");
        return false;
    }
}

#endif