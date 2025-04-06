#pragma once

#ifndef ENABLE_EXAMPLE
#define ENABLE_EXAMPLE 1
#endif

#if ENABLE_EXAMPLE

class Example
{
public:
    static void init();
    static void update();

private:
    static void printInfo();
    static void printLoglevel();
};

#else

class Example
{
public:
    static void init() {}
    static void update() {}
};

#endif

// Global reference
extern Example& example;