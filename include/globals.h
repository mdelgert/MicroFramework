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

// Global classes
#include "pins.h"
#include "button.h"
#include "led.h"
#include "logger.h"
#include "mqtt.h"
#include "network.h"
#include "ntp.h"
#include "ota.h"
#include "settings.h"
#include "tft.h"
#include "timer.h"