# MicroFramework

A modular and reusable framework for ESP32 microcontrollers using PlatformIO, designed to simplify development with feature flags, centralized logging, and secure secret management.

## Overview

MicroFramework is a flexible framework for ESP32-based applications, built to prioritize maintainability, extensibility, and reusability. It incorporates best practices for memory efficiency and modularity, addressing common inefficiencies in ESP32 development.

### Key Features
- **Modular Design**: Enable or disable features like LED, TFT, WiFi, MQTT, and Bluetooth using feature flags in `platformio.ini`.
- **Centralized Logging**: Lightweight `Logger` class with configurable verbosity levels (verbose, debug, info, warning, error) and static buffers to avoid heap usage.
- **Global Settings**: Manage device configurations (e.g., SSID, MQTT credentials) using fixed-size arrays and the `Preferences` library to prevent heap fragmentation.
- **Secure Secret Management**: Store sensitive data in `secrets.h` (Git-ignored) with fallback defaults for seamless local and GitHub workflows.
- **Memory Optimization**: Avoids heap-intensive practices like `String` objects, ensuring efficient use of ESP32’s resources.

## Goals
- Provide a modular and reusable codebase for diverse ESP32 projects.
- Isolate features for better testing and heap usage monitoring.
- Centralize logging and configuration for easier management.
- Simplify development and deployment with secure secret handling.
- Adhere to best practices for code structure and maintainability.

## Project Structure

```
├── src/
│   ├── main.cpp          # Application entry point
│   ├── logger.h          # Centralized logging utility
│   ├── settings.h        # Global settings header
│   ├── settings.cpp      # Settings implementation
│   ├── secrets.h         # Local secrets (Git-ignored)
│   └── feature/          # Modular feature files (e.g., led.h, led.cpp)
├── platformio.ini        # PlatformIO configuration
```

## Getting Started

1. Clone the repository and open it in PlatformIO.
2. Configure your `platformio.ini` file to enable or disable features.
3. Add your local secrets to `secrets.h` (ignored by Git).
4. Build and upload the firmware to your ESP32 device.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or new features.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
