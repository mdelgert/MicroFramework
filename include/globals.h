#pragma once

#include <Arduino.h>

// Define default secrets
#ifndef ENABLE_DEFAULT_SECRETS
#define ENABLE_DEFAULT_SECRETS 0
#endif

#if ENABLE_DEFAULT_SECRETS
#include "secrets.h"
#else
#include "secrets.default.h"
#endif

// Global configuration - https://the-sz.com/products/usbid/index.php
#define CUSTOM_PRODUCT_NAME "KMD"
#define CUSTOM_MANUFACTURER "Unifying Receiver"
#define CUSTOM_SERIAL_NUMBER "KMD01-2025-04-00001"

// Global classes
#include "pins.h"
#include "button.h"
#include "kmd.h"
#include "led.h"
#include "lfs.h"
#include "logger.h"
#include "mqtt.h"
#include "network.h"
#include "ntp.h"
#include "ota.h"
#include "settings.h"
#include "tft.h"
#include "timer.h"
#include "web.h"