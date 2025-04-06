#include "tft.h"
#include "globals.h"

#if ENABLE_TFT

int Tft::counter = 0;
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
    lcd.setTextSize(2);                     // Set the text size
}

void Tft::update()
{
    if(timer.isOneSecondElapsed()) // Check if 1 second has elapsed
    {
        // lcd.fillRect(5, 5, 100, 20, TFT_BLACK); // Clear previous text area
        // lcd.setCursor(5, 5);                    // Set cursor position
        // lcd.printf("Counter: %d", counter++);   // Display the counter value
        // debugI("Tft::update() - Counter updated: %d", counter);
        printHeap(); // Call printHeap to display heap memory info
    }
}

void Tft::printHeap()
{
    // Print heap memory information
    size_t freeHeap = esp_get_free_heap_size();
    size_t minFreeHeap = esp_get_minimum_free_heap_size();
    debugI("Tft::printHeap() - Free Heap: %d bytes, Min Free Heap: %d bytes", freeHeap, minFreeHeap);
    lcd.setCursor(5, 30); // Set cursor position for heap info
    lcd.fillRect(5, 30, 200, 20, TFT_BLACK); // Clear previous heap info area
    lcd.printf("Free: %d", freeHeap);
}

void Tft::test()
{
    lcd.fillScreen(TFT_BLACK); // Clear the screen
    lcd.setCursor(5, 5);       // Position the cursor
    lcd.println("HELLO");      // Display the message
}

#endif