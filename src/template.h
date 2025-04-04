// template.h
#pragma once

#if TEMPLATE_H

class TemplateClass
{
public:
    static void Begin();

private:
    static void ExampleFunction();
};

#else

class TemplateClass
{
public:
    Begin();

private:
    static void ExampleFunction();
};

#endif