#include "network.h"
#include "globals.h"

#if ENABLE_NETWORK

#include <WiFi.h>

void Network::init()
{
// Connect to WiFi if not already connected
    if (!isConnected()) {
        debugI("Connecting to WiFi...");
        WiFi.begin(settings.getWifiSSID(), settings.getWifiPassword());
    }
}

void Network::update()
{
    if (timer.isSixtySecondsElapsed) {
        // Check WiFi connection status
        if (!isConnected()) {
            debugW("Network disconnected, attempting to reconnect...");
            init(); // Try to reconnect if not connected
        } else {
            debugD("Network is connected");
        }
    }
}

bool Network::isConnected()
{
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
        return true;
    } else {
        debugW("Network not connected");
        return false;
    }
}

#endif