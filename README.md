# MicroFramework

A clean, modular, and reusable codebase for ESP32 microcontrollers using PlatformIO, designed to streamline development with feature flags, centralized logging, and secure secret management.

## Overview

This project is a flexible framework for ESP32-based applications. My goal was to create a codebase that’s easy to maintain, extend, and reuse—potentially as a library—while following best practices for memory efficiency and modularity. It’s built from my experience with PlatformIO, addressing the manual inefficiencies I faced after a year of development.

### Key Features
- **Modular Design**: Toggle features like LED, TFT, WiFi, MQTT, Bluetooth, and more using feature flags (`#ifdef`) in `platformio.ini`.
- **Centralized Logging**: Configurable logging with verbosity levels (verbose, debug, info, warning, error) via a lightweight `Logger` class, avoiding heap usage with static buffers.
- **Global Settings**: Access device name, SSID, MQTT credentials, and more through fixed-size arrays and the `Preferences` library, ensuring no heap fragmentation.
- **Secret Management**: Local secrets in `secrets.h` (ignored by Git) with automatic fallback to defaults for GitHub, simplifying development workflows.
- **Memory Efficiency**: Avoids `String` objects and other heap-intensive practices, optimized for ESP32’s limited resources.

## Goals
- Build a codebase that’s modular and reusable for various ESP32 projects.
- Enable feature isolation to test and monitor heap usage effectively.
- Centralize logging and preferences for global accessibility.
- Streamline local development and GitHub deployment with secure secret handling.
- Follow best practices for naming, structure, and maintainability.

## Project Structure

├── src/
│   ├── main.cpp          # Entry point
│   ├── logger.h          # Centralized logger
│   ├── settings.h        # Global settings header
│   ├── settings.cpp      # Settings implementation
│   └── secrets.h         # Local secrets (ignored by Git)
│   └── features/         # Modular feature files (e.g., led.h, led.cpp)
├── platformio.ini        # PlatformIO configuration
