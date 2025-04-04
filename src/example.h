// example.h
#pragma once

#ifndef ENABLE_EXAMPLE
#define ENABLE_EXAMPLE 1
#endif

#if ENABLE_EXAMPLE

class Example
{
public:
    static void setup();
    static void loop();

private:
    static void printInfo();
};

#else

class Example
{
public:
    static void setup() {}
    static void loop() {}
};

#endif

// Global reference
extern Example& example;