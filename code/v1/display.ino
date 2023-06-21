/*

  PrintHelloWorld.ino
  
  Use the (Arduino compatible) u8g2 function "print"  to draw a text.
  Also use the Arduino F() macro to place the text into PROGMEM area.

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/



#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// End of constructor list

void oled_setup(void) {

  u8g2.begin();
}

void display_loop(){
  
//  u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.setFont(u8g2_font_micro_tr);

//  u8g2_font_micro_tr
  u8g2.firstPage();
  do {

    u8g2.drawHLine(0, 49, 117);
    
    u8g2.setFontDirection(0);
    u8g2.setCursor(0, 56);
    u8g2.print("INPUT:");
    u8g2.print(INPUT_IO);

    u8g2.setCursor(0, 63);
    u8g2.print("CLOSED_SP:");
    u8g2.print(CLOSED_SP);

    u8g2.setCursor(64, 63);
    u8g2.print("OPEN_SP:");
    u8g2.print(OPEN_SP);

    int x0,y0,x1,y1;

    x0 = vMap(CLOSED_SP);
    y0 = 49;
    u8g2.drawCircle(x0, y0, 2);

    x1 = vMap(OPEN_SP);
    y1 = 0;
    u8g2.drawCircle(x1, y1, 2);

    u8g2.drawLine( x0,  y0,  x1,  y1);

    //map(value, fromLow, fromHigh, toLow, toHigh)

    int line_v = vMap(INPUT_IO);
    u8g2.drawVLine(line_v, 0, 50);
    //int line_h = 25;
    
    int line_h = hMap(OUTPUT_IO);
    u8g2.drawHLine(0, line_h, 117);

    Serial.println(line_h);

    u8g2.drawVLine(117, 0, 50);
    
    u8g2.setFontDirection(3);
    u8g2.setCursor(125, 50);
    u8g2.print("OUTPUT:");
    u8g2.print(OUTPUT_IO);
    
  } while ( u8g2.nextPage() );
  
}

int vMap(int Value){

  
  return map(Value,0,1700,0,117);
  
  
  }

  int hMap(int Value){
    
    return map(Value,0,255,50,0);}
