#include "mqtt.h"

#if ENABLE_MQTT

#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>

// WiFi and MQTT client initialization
WiFiClientSecure esp_client;
PubSubClient mqtt_client(esp_client);

void Mqtt::init()
{
    // Set Root CA certificate
    esp_client.setCACert(ca_cert);
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
        return;
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
                mqtt_client.publish(settings.getMqttPubTopic(), "Hello");
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

#endif

// https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker
// https://github.com/emqx/MQTT-Client-Examples/blob/master/mqtt-client-ESP32/esp32_connect_mqtt_via_tls.ino