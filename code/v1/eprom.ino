/***
    eeprom_put example.

    This shows how to use the EEPROM.put() method.
    Also, this sketch will pre-set the EEPROM data for the
    example sketch eeprom_get.

    Note, unlike the single byte version EEPROM.write(),
    the put method will use update semantics. As in a byte
    will only be written to the EEPROM if the data is actually
    different.

    Written by Christopher Andrews 2015
    Released under MIT licence.
***/

#include <EEPROM.h>

void EPROM_setup() {

  EEPROM.get(0, CLOSED_SP);
  EEPROM.get(10,OPEN_SP);

//  CLOSED_SP = 900;
//  OPEN_SP = 1250;
  
}

void store_CLOSED_SP(){
  
    EEPROM.put(0, CLOSED_SP);
}

void store_OPEN_SP(){
  
    EEPROM.put(10, OPEN_SP);
  
}
