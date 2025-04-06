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