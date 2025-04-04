You are an expert in embedded C++ programming for ESP32 microcontrollers using PlatformIO and the Arduino framework. I need you to refactor my existing ESP32 C++ codebase to follow best practices for embedded systems development, ensuring it is modular, efficient, safe, and maintainable. The codebase is part of a MicroFramework designed for ESP32, with features like Blink, centralized logging (Logger class), and global settings (Settings class). Here are the specific requirements and guidelines to follow:

1. **Avoid Global Variables and Use Dependency Injection**:
   - Eliminate all global variables (e.g., `extern Example& example` or `extern Example* example`) to reduce coupling and improve testability.
   - Use dependency injection by managing feature instances locally in `main.cpp` and passing them to a `FeatureManager` class or similar structure. For example, create a `Blink` instance in `main.cpp` and pass it to a manager for setup and updates.

2. **Modularity and Encapsulation**:
   - Structure features as self-contained classes (e.g., `Blink`) with private members and a public interface (`init()` for initialization, `update()` for runtime behavior).
   - Use feature flags (e.g., `#ifndef ENABLE_BLINK`) in `platformio.ini` to enable/disable features at compile time, providing no-op implementations when disabled.

3. **Performance Optimization**:
   - Avoid dynamic allocation (e.g., `new`, `malloc`) to prevent heap fragmentation; use static allocation instead.
   - Optimize for speed and memory usage, minimizing function calls and using inline methods where appropriate for ESP32’s limited resources.

4. **Safety and Security**:
   - Follow secure coding practices: safely handle interrupts, avoid resource leaks using RAII (Resource Acquisition Is Initialization), and consider MISRA-C guidelines if applicable.
   - Implement basic security (e.g., encryption, authentication) if the feature involves communication, ensuring no vulnerabilities.

5. **Testing and Debugging**:
   - Design features to be unit-testable (e.g., injectable dependencies for mocking).
   - Integrate with the existing `Logger` class for debugging, using appropriate log levels (e.g., `Logger::info()`, `Logger::warning()`) conditionally based on an `ENABLE_LOGGER` flag.

6. **Real-Time and Hardware Handling**:
   - Ensure predictability for real-time tasks, abstract hardware interactions (e.g., GPIO pins), and handle communication protocols (e.g., I2C, SPI) if needed.
   - Support interrupt handling and Direct Memory Access (DMA) if relevant to the feature.

7. **Maintainability**:
   - Use clear, descriptive naming (e.g., `init`, `update`) and add comprehensive comments explaining purpose, parameters, and design decisions.
   - Follow C++ Core Guidelines: make move operations `noexcept`, avoid virtual functions for performance, and use RAII for resource management.
   - Use `#pragma once` for header guards to prevent multiple inclusions.

8. **ESP32-Specific Practices**:
   - Structure code to support FreeRTOS tasks for concurrency, using `app_main` as the entry point if integrating ESP-IDF.
   - Leverage existing `Settings` class for configuration (e.g., `Settings::getDeviceName()`), avoiding direct modification of `FreeRTOSConfig.h`.
   - Manage heap usage with ESP-IDF APIs if needed, and avoid experimental SMP features.

9. **Additional Recommendations**:
   - Provide thorough documentation in comments or a separate README section for each feature.
   - Consider Over-The-Air (OTA) update support and firmware security (e.g., encrypted updates) for robustness, especially for IoT applications.

**Task**:
- Refactor my provided code (or create a sample if none is provided) into a clean, best-practice implementation.
- Use the `Blink` feature as an example, which toggles an LED on a specified pin (default pin 2), integrating with `Logger` and `Settings`.
- Ensure the code works with PlatformIO, compiles cleanly whether `ENABLE_BLINK` is defined or not, and includes a `FeatureManager` class in `main.cpp` to manage the feature without globals.
- Provide explanations of changes and why they align with best practices.

**Existing Code Context** (if applicable):
- Assume I have `logger.h` and `settings.h` already implemented, with methods like `Logger::info(const char*, ...)` and `Settings::getDeviceName()`.
- My current code might use globals (e.g., `extern Blink* blink`) and lack dependency injection; refactor it accordingly.

**Output**:
- Provide cleaned-up code for `blink.h`, `blink.cpp`, `main.cpp`, and any necessary updates to `platformio.ini`.
- Include a brief explanation of key changes and how they meet the requirements above.