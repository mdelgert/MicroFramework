You are an expert in embedded C++ programming for ESP32 microcontrollers using PlatformIO and the Arduino framework. I need you to create or refactor a sample ESP32 C++ codebase for my MicroFramework, ensuring it follows best practices for embedded systems while implementing specific patterns I’m targeting. The framework should be modular, efficient, safe, and maintainable, with features like a `Blink` LED toggle, a centralized `Logger` class, and a `Settings` class for configuration. Below are the exact requirements and patterns to implement, inspired by my existing code and discussions:

1. **Core Patterns to Implement**:
   - **No Global Variables**: Avoid all global variables (e.g., `extern Logger& logger`, `extern Blink* blink`) to reduce coupling and improve testability. Manage instances locally in `main.cpp` and pass them where needed.
   - **Dependency Injection**: Use dependency injection to pass dependencies (e.g., `Logger`, `Settings`) to features like `Blink` and a `FeatureManager` class. For example, `Blink` should receive a `Logger` pointer during initialization.
   - **Feature Flags**: Use compile-time feature flags (e.g., `#ifndef ENABLE_BLINK`) in `platformio.ini` to enable/disable features, providing no-op implementations when disabled for safety.
   - **Consistent Logging**: Implement a centralized `Logger` class with a macro-based interface (`logV`, `logD`, `logI`, `logW`, `logE`) as in my sample code. These macros should map to a single logging mechanism (e.g., `Logger::log()`), avoiding multiple logging styles. Logging should be disabled at compile time with `ENABLE_LOGGING=0`, resulting in zero-cost no-ops.

2. **Specific Requirements**:
   - **Logger Class**:
     - Use a static buffer (e.g., `LOG_BUFFER_SIZE=128`, configurable via `platformio.ini`) to avoid heap allocation.
     - Support log levels (VERBOSE=0, DEBUG=1, INFO=2, WARNING=3, ERROR=4) with a default level (e.g., INFO) set via `LOG_LEVEL` in `platformio.ini`.
     - Include timestamps (e.g., `millis()`) in log messages for context.
     - Initialize Serial non-blocking (e.g., wait up to 1s with `yield()`), checking availability before logging.
   - **Blink Feature**:
     - Toggle an LED on a configurable pin (default pin 2), initialized with `init(Logger*)` and updated with `update()`.
     - Log actions (e.g., initialization, toggles) using the macro interface (e.g., `logI`, `logV`).
   - **Settings Class**:
     - Simplified version with a method like `getDeviceName()` using `Preferences` for NVS storage, logging initialization via macros.
   - **FeatureManager**:
     - A class in `main.cpp` to manage `Logger`, `Settings`, and `Blink` instances, calling `init()` and `update()` methods via dependency injection.

3. **Best Practices to Follow**:
   - **Modularity**: Encapsulate features in classes with private members and public interfaces (`init()`, `update()`).
   - **Performance**: Avoid dynamic allocation, optimize for ESP32’s limited resources (e.g., static buffers, minimal function calls).
   - **Safety**: Handle Serial failures gracefully, use RAII principles for resources (e.g., Serial setup), and ensure no crashes when features are disabled.
   - **Maintainability**: Use clear names (e.g., `init`, `update`), add detailed comments explaining purpose and design, and use `#pragma once` for headers.
   - **ESP32-Specific**: Support FreeRTOS compatibility (e.g., `yield()` in loops), avoid blocking calls, and be ready for task integration if needed.

4. **Task**:
   - Provide a complete sample codebase including `logger.h`, `logger.cpp`, `settings.h`, `settings.cpp`, `blink.h`, `blink.cpp`, `main.cpp`, and `platformio.ini`.
   - Ensure the code compiles and runs on ESP32 with PlatformIO, with `Blink` toggling an LED when enabled and logging consistently via macros.
   - Explain how the code implements the requested patterns (no globals, DI, feature flags, consistent logging) and meets best practices.

5. **My Existing Code Context**:
   - My `Logger` uses macros (`logV`, `logI`, etc.) mapping to `Logger::log(uint8_t level, const char* format, ...)`, with a static buffer and `ENABLE_LOGGING` flag. Refactor this to fit the new structure but keep the macro-based approach.
   - Assume `Settings` exists with `init()` and `getDeviceName()`, using `Preferences`.
   - I want `Blink` as a feature example, toggling an LED, integrated with `Logger` and `Settings`.

6. **Output**:
   - Deliver clean, commented code files.
   - Include a short explanation of how the solution achieves my goals, avoiding confusion (e.g., no mixed logging styles) and matching my MicroFramework vision.

Please ensure the logging system is consistent (macros only, no direct method calls unless via macros), and the code avoids globals entirely, using dependency injection as the primary pattern for managing dependencies.