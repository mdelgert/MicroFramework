#include "mqtt.h"
#include "globals.h"

#if ENABLE_MQTT

#include <PubSubClient.h>
#include <WiFiClientSecure.h>

// WiFi and MQTT client initialization
WiFiClientSecure esp_client;
PubSubClient mqtt_client(esp_client);

void Mqtt::init()
{
    // Initialize MQTT client here
    // For example, set up connection parameters, callbacks, etc.
}

void Mqtt::update()
{
    // Update MQTT client here
    // For example, handle incoming messages, maintain connection, etc.
    // This function should be called periodically to keep the MQTT connection alive
}

#endif

//https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker
//https://github.com/emqx/MQTT-Client-Examples/blob/master/mqtt-client-ESP32/esp32_connect_mqtt_via_tls.ino