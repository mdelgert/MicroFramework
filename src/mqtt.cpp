#include "mqtt.h"

#if ENABLE_MQTT

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// WiFi and MQTT client initialization
WiFiClientSecure secure_wifi_client;
WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

void Mqtt::init()
{
    if (settings.getMqttSSL())
    {
        secure_wifi_client.setCACert(ca_cert);
        mqtt_client.setClient(secure_wifi_client); // Use secure client
    }
    else
    {
        debugI("MQTT SSL is disabled. Using non-secure connection.");
        mqtt_client.setClient(wifi_client); // Use non-secure client
    }

    mqtt_client.setServer(settings.getMqttServer(), settings.getMqttPort());
    mqtt_client.setKeepAlive(60);
    mqtt_client.setCallback(mqttCallback);
    connectToMQTT();
}

void Mqtt::update()
{
    if (mqtt_client.connected())
    {
        mqtt_client.loop();
    }
}

void Mqtt::connectToMQTT()
{
    while (!mqtt_client.connected())
    {
        // Check if WiFi is connected
        if (WiFi.status() == WL_CONNECTED)
        {
            // Attempt to connect to the MQTT broker
            debugI("Connecting to MQTT Broker as %s...\n", settings.getDeviceName());
            if (mqtt_client.connect(settings.getDeviceName(), settings.getMqttUsername(), settings.getMqttPassword()))
            {
                debugI("Connected to MQTT broker");
                mqtt_client.subscribe(settings.getMqttSubTopic());
                
                // Send initial message to indicate connection with the device name but don't use string
                char initialMessage[64];
                snprintf(initialMessage, sizeof(initialMessage), "Device %s connected", settings.getDeviceName());
                mqtt_client.publish(settings.getMqttPubTopic(), initialMessage);
            }
            else
            {
                if (timer.isFifteenSecondsElapsed())
                {
                    debugI("Failed to connect to MQTT broker, rc=%i ", mqtt_client.state());
                    debugI(" Retrying in 15 seconds.");
                }
            }
        }
    }
}

void Mqtt::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    debugI("Message received on topic: %s\n", topic);
    String message;
    for (unsigned int i = 0; i < length; i++)
    {
        message += (char)payload[i];
    }
    debugI("Message: %s\n", message.c_str());
}

void Mqtt::sendMessage(const char *topic, const char *message)
{
    // Do not write to debug log if mqtt logging is enabled or will cause infinite loop and crash application
    if (mqtt_client.connected())
    {
        mqtt_client.publish(topic, message);
    }
}

#endif

// References:
// https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker
// https://github.com/emqx/MQTT-Client-Examples/blob/master/mqtt-client-ESP32/esp32_connect_mqtt_via_tls.ino