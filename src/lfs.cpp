#include "lfs.h"
#include "globals.h"

#if ENABLE_LFS

#include <LittleFS.h>

void Lfs::init()
{
    if (!LittleFS.begin(true))
    {
        return;
    }

    // if (LittleFS.exists(LOG_FILE))
    // {
    //     LittleFS.remove(LOG_FILE);
    // }
}

void Lfs::logToFile(const char *message)
{
    // Do not send messages to logger or will go into infinite loop and crash
    //LittleFS.exists(LOG_FILE);
    File file = LittleFS.open(LOG_FILE, FILE_APPEND);
    if (!file)
    {
        return;
    }
    file.println(message);
    file.close();
}

#endif

/*
void Lfs::deleteFile(const char *filename)
{
    if (LittleFS.exists(filename))
    {
        if (LittleFS.remove(filename))
        {
            debugI("File %s deleted successfully.\n", filename);
        }
        else
        {
            debugE("Failed to delete file %s.\n", filename);
        }
    }
    else
    {
        debugI("File %s does not exist.\n", filename);
    }
}

void Lfs::logToFile(const char *filename, const char *message)
{
    if (!LittleFS.exists(filename))
    {
        debugI("File %s does not exist. Creating it.\n", filename);
    }

    File file = LittleFS.open(filename, FILE_APPEND);
    if (!file)
    {
        debugE("Failed to open file %s for writing.\n", filename);
        return;
    }

    if (file.println(message))
    {
        debugI("Message logged to file: %s\n", filename);
    }
    else
    {
        debugE("Failed to write message to file: %s\n", filename);
    }

    file.close();
}

void Lfs::init()
{
    if (!LittleFS.begin(true))
    {
        //debugE("Failed to mount LittleFS");
        return;
    }

    if (LittleFS.exists("/debug.log"))
    {
        LittleFS.remove("/debug.log");
    }
}

void Lfs::logToFile(const char *filename, const char *message)
{
    // Do not send messages to logger or will go into infinite loop and crash
    LittleFS.exists(filename);
    File file = LittleFS.open(filename, FILE_APPEND);
    if (!file)
    {
        return;
    }
    file.println(message);
    file.close();
}
*/