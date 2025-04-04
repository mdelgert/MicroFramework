//globals.h
#pragma once

#include <Arduino.h>

// Define default secrets
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
#include "settings.h"