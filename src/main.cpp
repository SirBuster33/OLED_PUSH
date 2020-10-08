
#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //M0/ESP32/ESP8266/mega2560/Uno/Leonardo

void setup(void) {
  u8g2.begin();                  //init
  u8g2.enableUTF8Print();        // Enable UTF8 support for Arduino print（）function.
}

void loop(void) 
{
  uint8_t draw_state = 0;

  u8g2.setFont(u8g2_font_maniac_tf);
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFont(u8g2_font_halftone_tr);
// u8g2.setFont(u8g2_font_sticker_mel_t);     // Code problem
// u8g2.setFont(u8g2_font_timB24_tn);         // Doesn't work
  u8g2.setFontDirection(0);  
  u8g2.firstPage();
  do {
    u8g2.drawStr( 10 + draw_state*2, 20, "GraphicsTest");
    // u8g2.setCursor(/* x=*/0, /* y=*/30);    // Define the cursor of print function, any output of the print function will start at this position.
    // u8g2.print("Hello World!")
  } while ( u8g2.nextPage() );

  draw_state++;
  if ( draw_state >= 14*8 )
    draw_state = 0;
  delay(150);
  
}