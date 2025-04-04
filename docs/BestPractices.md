### Key Points
- Research suggests avoiding global variables like `extern Example& example;` in C++ embedded systems for better modularity and testability.
- It seems likely that using dependency injection, such as passing instances through function calls, is a better approach for ESP32 MicroFramework features.
- The evidence leans toward managing feature instances locally in `main.cpp` and using a `FeatureManager` class, avoiding global state for clarity and safety.

---

### Direct Answer

#### Introduction
When cleaning up your ESP32 C++ codebase, focus on best practices to ensure it’s efficient, safe, and easy to maintain. Here’s how to implement these practices, including avoiding global variables and using dependency injection, as well as other recommendations for a robust system.

#### Avoiding Global Variables and Using Dependency Injection
Instead of using global variables like `extern Example& example;`, which can make code hard to test and maintain, pass dependencies explicitly. For example, create a `FeatureManager` class in `main.cpp` to manage feature instances locally, like a `Blink` feature, and pass it where needed. This reduces coupling and improves testability, making it easier to swap implementations, such as using mocks for testing.

#### Implementing Best Practices
- **Modularity and Encapsulation**: Use classes for features, like `Blink`, to keep code self-contained and reusable. Follow object-oriented programming (OOP) principles to ensure each feature is independent.
- **Performance Optimization**: Avoid dynamic allocation (e.g., `new`, `malloc`) to save memory, using static allocation instead. Optimize for speed and size, crucial for ESP32’s limited resources.
- **Safety and Security**: Follow secure coding practices, safely handle interrupts, and consider MISRA-C guidelines if your system is safety-critical. Implement encryption and authentication for secure communication, and ensure no resource leaks using RAII (Resource Acquisition Is Initialization).
- **Testing and Debugging**: Add unit tests for features, use simulation or emulation for testing, and master debugging techniques like using breakpoints and logs. Frequent commits with Git help track changes.
- **Real-Time and Hardware Handling**: Ensure predictability for real-time tasks, manage hard and soft real-time constraints, and prevent downtime. Abstract hardware interactions, handle Direct Memory Access (DMA), interrupts, and communication protocols like I2C or SPI.
- **Maintainability**: Use clear, descriptive names (e.g., `init` for initialization, `update` for runtime), add comprehensive comments, and follow C++ Core Guidelines for safety and performance, like making move operations `noexcept` and avoiding virtual functions for efficiency.
- **ESP32-Specific Practices**: Structure code into FreeRTOS tasks for concurrency, use OOP for large projects, focus on debugging, and follow FreeRTOS best practices, such as not modifying `FreeRTOSConfig.h` directly, using `app_main` as the entry point, and managing heap with ESP-IDF APIs.

#### Additional Recommendations
Document your code thoroughly, use `#pragma once` for header guards to avoid multiple inclusions, and consider Over-The-Air (OTA) updates and firmware security for robustness, especially for IoT applications. These steps ensure your codebase is professional, scalable, and reliable.

An unexpected detail is how using a `FeatureManager` not only avoids globals but also centralizes feature management, making it easier to add new features later without changing `main.cpp` extensively, enhancing scalability.

---

### Survey Note: Detailed Analysis and Implementation

This section provides a comprehensive exploration of cleaning up an ESP32 C++ codebase with best practices, implementing everything discussed, and offering additional recommendations. It builds on the direct answer, offering deeper insights and technical details for a professional audience, mimicking a long survey note.

#### Background and Context
The user’s query is about cleaning up their ESP32 C++ codebase, likely related to a MicroFramework with features like `Blink`, focusing on avoiding global variables and using dependency injection, as discussed previously. Given the context, the codebase is for embedded systems, and we’ll assume it’s C++ with Arduino-style programming, common for ESP32. The goal is to refactor for efficiency, safety, and maintainability, incorporating all best practices and recommendations.

To ensure completeness, we gathered information from various sources, including general embedded C++ best practices and ESP32-specific guidelines. Research from [Modern C++ in embedded systems – Part 1: Myth and Reality](https://www.embedded.com/modern-c-in-embedded-systems-part-1-myth-and-reality/) emphasizes evaluating C++ code for speed and size, suggesting avoiding dynamic allocation. [C++ for Embedded: Advantages, Disadvantages, and Myths](https://www.qt.io/blog/c-for-embedded-advantages-disadvantages-and-myths) highlights efficient coding techniques, while a Reddit thread on r/embedded ([Good and bad practices on embedded programming](https://www.reddit.com/r/embedded/comments/t23pcs/good_and_bad_practices_on_embedded_programming/)) mentions MISRA-C for safety-critical systems. [Tips and Best Practices for Embedded C Programming](https://www.linkedin.com/pulse/tips-best-practices-embedded-c-programming) recommends frequent commits and debugging, and [C++ Tutorial: Embedded Systems Programming - 2020](https://www.bogotobogo.com/cplusplus/embeddedSystemsProgramming.php) stresses real-time constraints and predictability.

For ESP32, a Reddit post on r/esp32 ([Code Structure Best Practices](https://www.reddit.com/r/esp32/comments/takbh6/code_structure_best_practices/)) suggests OOP for large projects, an ESP32 forum post ([Are there any best practices / decision rules how to structure the code into different tasks?](https://www.esp32.com/viewtopic.php?t=14594)) discusses FreeRTOS tasks, and [A Beginner’s Guide To ESP32 Programming](https://www.makerguides.com/a-beginners-guide-to-esp32-programming/) mentions debugging. FreeRTOS best practices from ESP-IDF ([FreeRTOS Best Practices in ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html)) include not modifying `FreeRTOSConfig.h`, using `app_main`, and managing heap with ESP-IDF APIs. The C++ Core Guidelines ([C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)) provide rules like making move operations `noexcept` and avoiding virtual functions, relevant for embedded systems.

#### Why Avoid Global Variables and Use Dependency Injection?
Global variables, especially `extern Example& example;`, introduce tight coupling, making testing difficult and creating hidden dependencies, as noted in [The Problems with Global Variables Embedded Artistry]([invalid url, do not cite]). For ESP32, where memory is limited, globals can lead to bugs hard to trace, per r/embedded ([Is it also discouraged to use global variables in embedded software programming ?]([invalid url, do not cite])). Instead, dependency injection, passing instances through function calls, is recommended, as per [Dependency Injection mbedded.ninja]([invalid url, do not cite]), improving modularity and testability. Our earlier discussion suggested managing instances locally in `main.cpp` with a `FeatureManager` class, reducing scope and enhancing clarity, as seen in [Getting Rid of Global Variables Better Embedded System SW]([invalid url, do not cite]).

#### Best Practices Implementation
To refactor the codebase, follow these steps:

1. **Avoid Global Variables and Use Dependency Injection**:
   - Replace `extern Example& example;` with local instances, managed by a `FeatureManager` class. For example, in `main.cpp`, create `Blink blink(2);` and pass it to `FeatureManager manager(&blink);`, calling methods through the manager. This aligns with [How to avoid globals in this case (embedded C) Stack Overflow]([invalid url, do not cite]), reducing coupling.

2. **Modularity and Encapsulation**:
   - Use classes for features, like `Blink`, ensuring self-contained code. Follow OOP principles, as suggested by r/esp32 ([Code Structure Best Practices](https://www.reddit.com/r/esp32/comments/takbh6/code_structure_best_practices/)), with private members and public interfaces. For example, `Blink` should have `init()` and `update()`, encapsulating LED toggling logic.

3. **Performance Optimization**:
   - Avoid dynamic allocation (e.g., `new`, `malloc`), using static allocation for efficiency, per [C++ for Efficient Embedded Systems | Medium](https://medium.com/@AlexanderObregon/c-for-embedded-systems-3de381c9d4bf). Optimize for speed and size, crucial for ESP32, by minimizing function calls and using inline where appropriate, as per [The Science Behind Embedded C++: Best Practices For High Performance - Code With C](https://www.codewithc.com/the-science-behind-embedded-c-best-practices-for-high-performance/).

4. **Safety and Security**:
   - Follow secure coding practices, handle interrupts safely, and consider MISRA-C guidelines for safety-critical systems, as mentioned in r/embedded ([Good and bad practices on embedded programming](https://www.reddit.com/r/embedded/comments/t23pcs/good_and_bad_practices_on_embedded_programming/)). Implement encryption and authentication for secure communication, and use RAII for resource management, per C++ Core Guidelines ([C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)), rule P.8, to prevent leaks.

5. **Testing and Debugging**:
   - Add unit tests for features, use simulation or emulation for testing, and master debugging techniques like using breakpoints and logs, as recommended by [Tips and Best Practices for Embedded C Programming](https://www.linkedin.com/pulse/tips-best-practices-embedded-c-programming). Frequent commits with Git help track changes, ensuring version control, per the same source.

6. **Real-Time and Hardware Handling**:
   - Ensure predictability for real-time tasks, manage hard and soft real-time constraints, and prevent downtime, per [C++ Tutorial: Embedded Systems Programming - 2020](https://www.bogotobogo.com/cplusplus/embeddedSystemsProgramming.php). Abstract hardware interactions, manage DMA and interrupts, and handle communication protocols like I2C or SPI, as per [The Science Behind Embedded C++: Best Practices For High Performance - Code With C](https://www.codewithc.com/the-science-behind-embedded-c-best-practices-for-high-performance/).

7. **Maintainability**:
   - Use clear naming conventions, like `init` for initialization and `update` for runtime, add comprehensive comments, and follow C++ Core Guidelines for safety, portability, and performance. For example, make move operations `noexcept` (rule C.66), avoid virtual functions for performance (rule C.132), and use RAII for resource management (rule P.8), all from [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). Frequent commits with Git ensure version control, per LinkedIn.

8. **ESP32-Specific Practices**:
   - Structure code into FreeRTOS tasks for concurrency, use OOP for large projects, focus on debugging, and follow FreeRTOS best practices, such as not modifying `FreeRTOSConfig.h` directly, using `app_main` as the entry point, managing heap with ESP-IDF APIs, and avoiding experimental SMP features, per [FreeRTOS Best Practices in ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html). This aligns with the ESP32 forum post on tasks ([Are there any best practices / decision rules how to structure the code into different tasks?](https://www.esp32.com/viewtopic.php?t=14594)).

#### Additional Recommendations
- Document the code thoroughly, including function purposes and design decisions, to aid maintenance, per [For Beginners - Embedded Artistry](https://embeddedartistry.com/beginners/). Use `#pragma once` for header guards to avoid multiple inclusions, improving compile times, as per C++ best practices.
- Consider implementing Over-The-Air (OTA) updates and firmware security for robustness, especially for IoT applications, per [The Science Behind Embedded C++: Best Practices For High Performance - Code With C](https://www.codewithc.com/the-science-behind-embedded-c-best-practices-for-high-performance/), enhancing deployability and security.

#### Unexpected Detail: Manager Class Benefits
An unexpected benefit of using a `FeatureManager` class is that it not only avoids globals but also centralizes feature management, making it easier to add new features later without changing `main.cpp` extensively, enhancing scalability, as seen in our earlier example.

#### Comparison Table: Global vs. DI Approach

| Aspect                  | Global (`extern Blink* blink`) | DI (`FeatureManager` with Local Instance) |
|-------------------------|--------------------------------|------------------------------------------|
| Modularity              | Low, tight coupling            | High, loose coupling                     |
| Testability             | Poor, hard to mock             | Good, easy to inject mocks               |
| Memory Usage            | Minimal, but dummy object if disabled | Minimal, no dummy needed, `nullptr` check |
| Flexibility             | Limited, global state affects all | High, can swap implementations easily    |
| Maintenance             | Harder, hidden dependencies    | Easier, explicit dependencies            |

This table, from our earlier reasoning, highlights why dependency injection is preferred, reinforcing the refactor approach.

#### Conclusion
Refactoring your ESP32 C++ codebase with these best practices ensures efficiency, safety, and maintainability, leveraging dependency injection, modularity, and ESP32-specific optimizations. The `FeatureManager` approach, thorough documentation, and OTA considerations enhance robustness, making your code professional and scalable.

---

### Key Citations
- [Modern C++ in embedded systems – Part 1: Myth and Reality](https://www.embedded.com/modern-c-in-embedded-systems-part-1-myth-and-reality/)
- [C++ for Embedded: Advantages, Disadvantages, and Myths](https://www.qt.io/blog/c-for-embedded-advantages-disadvantages-and-myths)
- [r/embedded on Reddit: Good and bad practices on embedded programming](https://www.reddit.com/r/embedded/comments/t23pcs/good_and_bad_practices_on_embedded_programming/)
- [Tips and Best Practices for Embedded C Programming](https://www.linkedin.com/pulse/tips-best-practices-embedded-c-programming)
- [C++ Tutorial: Embedded Systems Programming - 2020](https://www.bogotobogo.com/cplusplus/embeddedSystemsProgramming.php)
- [C++ for Efficient Embedded Systems | Medium](https://medium.com/@AlexanderObregon/c-for-embedded-systems-3de381c9d4bf)
- [For Beginners - Embedded Artistry](https://embeddedartistry.com/beginners/)
- [The Science Behind Embedded C++: Best Practices For High Performance - Code With C](https://www.codewithc.com/the-science-behind-embedded-c-best-practices-for-high-performance/)
- [r/esp32 on Reddit: Code Structure Best Practices](https://www.reddit.com/r/esp32/comments/takbh6/code_structure_best_practices/)
- [A Beginner’s Guide To ESP32 Programming](https://www.makerguides.com/a-beginners-guide-to-esp32-programming/)
- [Are there any best practices / decision rules how to structure the code into different tasks? - ESP32 Forum](https://www.esp32.com/viewtopic.php?t=14594)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [FreeRTOS Best Practices in ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html)