#include "tft.h"
#include "globals.h"

#if ENABLE_TFT

#include <WiFi.h>

LGFX_LiLyGo_TDongleS3 Tft::lcd;

LGFX_LiLyGo_TDongleS3::LGFX_LiLyGo_TDongleS3()
{
    // SPI bus configuration
    auto cfg = _bus_instance.config();
    cfg.spi_host = SPI3_HOST;   // SPI3 for ESP32-S3
    cfg.spi_mode = 0;           // SPI mode 0
    cfg.freq_write = 27000000;  // Write frequency
    cfg.freq_read = 16000000;   // Read frequency
    cfg.spi_3wire = true;       // 3-wire SPI
    cfg.pin_sclk = TFT_SCL_PIN; // SCLK pin
    cfg.pin_mosi = TFT_SDA_PIN; // MOSI pin
    cfg.pin_dc = TFT_DC_PIN;    // DC pin
    cfg.pin_miso = -1;          // No MISO pin
    _bus_instance.config(cfg);
    _panel_instance.setBus(&_bus_instance);

    // Panel configuration
    auto panel_cfg = _panel_instance.config();
    panel_cfg.pin_cs = TFT_CS_PIN;   // CS pin
    panel_cfg.pin_rst = TFT_RES_PIN; // RST pin
    panel_cfg.panel_width = 80;      // Display width
    panel_cfg.panel_height = 160;    // Display height
    panel_cfg.offset_x = 26;         // X offset
    panel_cfg.offset_y = 1;          // Y offset
    panel_cfg.invert = true;         // Invert colors
    _panel_instance.config(panel_cfg);

    // Backlight configuration
    auto light_cfg = _light_instance.config();
    light_cfg.pin_bl = TFT_LEDA_PIN; // Backlight pin
    light_cfg.invert = true;         // Inverted brightness
    light_cfg.freq = 12000;          // PWM frequency
    light_cfg.pwm_channel = 7;       // PWM channel
    _light_instance.config(light_cfg);
    _panel_instance.setLight(&_light_instance);
    setPanel(&_panel_instance); // Attach the panel
}

void Tft::init()
{
    lcd.init();                             // Initialize the display
    lcd.setBrightness(128);                 // Set the backlight brightness
    lcd.setRotation(1);                     // Adjust rotation (modify as needed)
    lcd.fillScreen(TFT_BLACK);              // Clear the screen
    lcd.setTextColor(TFT_WHITE, TFT_BLACK); // White text on black background
    lcd.setTextSize(1.75);                     // Set the text size
}

void Tft::update()
{
    if (timer.isOneSecondElapsed()) // Check if 1 second has elapsed
    {
        const int lineHeight = 20;  // Height of each line
        const int x = 3;            // Fixed x-coordinate for all lines
        int y = x;                  // Start y-coordinate
        
        // Print heap
        lcd.fillRect(x, y, 200, lineHeight, TFT_BLACK);
        lcd.setCursor(x, y);
        lcd.printf("FH: %d", ESP.getFreeHeap());
        
        // Print uptime
        y += lineHeight;
        lcd.fillRect(x, y, 200, lineHeight, TFT_BLACK);
        lcd.setCursor(x, y);
        lcd.printf("UT: %d", timer.getUptimeSeconds());
        
        // Print time
        y += lineHeight;
        lcd.fillRect(x, y, 200, lineHeight, TFT_BLACK);
        lcd.setCursor(x, y);

        if(ENABLE_NTP)
        {
            // If NTP is enabled, get the time from NTP
            struct tm timeInfo;
            if (getLocalTime(&timeInfo, 1000)) // Wait up to 1 second
            {
                char timeString[26];
                strftime(timeString, sizeof(timeString), "%H:%M:%S", &timeInfo);
                lcd.printf("TM: %s", timeString);
            }
            else
            {
                debugE("Failed to get NTP time.");
                lcd.print("TM: ??");
            }
        }
        else
        {
            lcd.print("TM: Off");
        }

        // Print IP address
        y += lineHeight;
        lcd.fillRect(x, y, 200, lineHeight, TFT_BLACK);
        lcd.setCursor(x, y);
        if (WiFi.status() == WL_CONNECTED)
        {
            IPAddress ip = WiFi.localIP();
            lcd.printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
        }
        else
        {
            lcd.printf("??");
        }
    }
}

void Tft::printMessage(const char* message, int x, int y, int maxLength)
{
    // Clear the area where the message will be displayed
    lcd.fillRect(x, y, maxLength * 6, 16, TFT_BLACK); // Assuming 6 pixels per character width and 16 pixels height
    lcd.setCursor(x, y);
    lcd.print(message);
}

#endif