; TODO look into using the build cache
; [platformio]
; default_envs =  esp32-s3-devkitm-1
; build_cache_dir = .pio/build_cache

  //tft.printMessage("HELLO:", 5, 5, 20);
  //tft.printMessage("HELLO:", 5, 25, 20);


/*
void Tft::update()
{
    if(timer.isOneSecondElapsed()) // Check if 1 second has elapsed
    {
        // Print heap
        lcd.setCursor(0, 0);
        lcd.fillRect(0, 0, 200, 20, TFT_BLACK);
        lcd.printf("FH: %d", ESP.getFreeHeap());

        lcd.setCursor(0, 17);
        lcd.fillRect(0, 17, 200, 20, TFT_BLACK);
        lcd.printf("UT: %d", timer.getUptimeSeconds());
        
        // Print time
        lcd.fillRect(0, 34, 200, 20, TFT_BLACK);
        lcd.setCursor(0, 34);
        struct tm timeInfo;
        if (getLocalTime(&timeInfo, 1000)) // Wait up to 1 second
        {
            char timeString[26];
            strftime(timeString, sizeof(timeString), "%H:%M:%S", &timeInfo);
            lcd.printf("TM: %s", timeString);
        }
        else
        {
            debugE("Failed to get local time.");
            lcd.setCursor(0, 34);
            lcd.fillRect(0, 34, 200, 20, TFT_BLACK);
            lcd.printf("TM: ??");
        }

        // Print ip address
        lcd.fillRect(0, 51, 200, 20, TFT_BLACK);
        if (WiFi.status() == WL_CONNECTED) {
            IPAddress ip = WiFi.localIP();
            lcd.setCursor(0, 51);
            lcd.printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
            //lcd.printf("IP: %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
            //lcd.printf("IP: %d", ip[3]);
        } else {
            lcd.setCursor(0, 51);
            lcd.printf("IP: ??");
        }
    }
}
*/

    /*
    if(timer.isOneSecondElapsed())
    {
        // Print the current time every 1 second
        struct tm timeInfo;
        if (getLocalTime(&timeInfo))
        {
            char timeString[26];
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", &timeInfo);
            debugI("Current time: %s", timeString);
        }
        else
        {
            debugE("Failed to get local time.");
        }
    }
    */

        // Set the timezone to America/New_York (UTC-5 with DST adjustment)
    const long gmtOffsetSec = -5 * 3600; // GMT offset in seconds
    const int daylightOffsetSec = 3600;  // Daylight Saving Time offset in seconds
    const char *ntpServer1 = "time.google.com";
    const char *ntpServer2 = "time.cloudflare.com";
    const char *ntpServer3 = "pool.ntp.org"; //time.nist.gov

    configTime(gmtOffsetSec, daylightOffsetSec, ntpServer1, ntpServer2, ntpServer3);