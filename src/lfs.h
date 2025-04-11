#pragma once

#ifndef ENABLE_LFS
#define ENABLE_LFS 1
#endif

#if ENABLE_LFS

class Lfs
{
public:
    static void init();

private:

};

#else

class Lfs
{
public:
    static void init() {}
};

#endif

// Global reference
extern Lfs& lfs;