#include "HT16K33.h"

HT16K33 seg(0x70);

void seg_setup()
{
//  Serial.begin(115200);
//  Serial.println(__FILE__);

  seg.begin();
  Wire.setClock(100000);
  seg.displayOn();
  seg.brightness(16);
  seg.displayClear();
  seg.blink(0);
  seg.setDigits(0);
}

unsigned long Next_time = 0;
const unsigned long Interval = 50; // Update interval in milliseconds

void display_int(int input_value) {
  unsigned long current_time = millis(); // Get the current time

  if (current_time - Next_time >= Interval) { // Check if the interval has elapsed
    seg.displayInt(input_value);
    Next_time = current_time; // Update Next_time to the current time
  }
}
