#include <SPI.h>



byte address = 0x00;
int CS= 10;
//
void pot_setup(){
pinMode (CS, OUTPUT);
SPI.begin();
digitalPotWrite(255);
}

void digitalPotWrite(int value){
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}
