#include "lfs.h"
#include "globals.h"

#if ENABLE_LFS

#include <LittleFS.h>

void Lfs::init()
{
    if (!LittleFS.begin(true))
    {
        debugE("Failed to mount LittleFS");
        return;
    }
}

#endif