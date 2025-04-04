//template.h

#pragma once

#ifdef ENABLE_TEMPLATE_HANDLER

class Template
{
public:
    static void init();
    static void loop();
private:
    static void example();
};

#else

class Template { 
public:
    static void init() {}
    static void loop() {}
};

#endif