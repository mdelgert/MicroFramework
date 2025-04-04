//globals.h
#pragma once

#include <Arduino.h>

// Define default secrets.default.h also feature flag to define your own secrets.h
#ifndef ENABLE_DEFAULT_SECRETS
#define ENABLE_DEFAULT_SECRETS 1
#endif

#if ENABLE_DEFAULT_SECRETS
#include "secrets.default.h"
#else
#include "secrets.h"
#endif

// Global classes
#include "logger.h"
