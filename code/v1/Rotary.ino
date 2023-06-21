// пример с прерываниями pinChangeInterrupt (прерывания на любом пине)
// только для ATmega328 (UNO, Nano, Pro Mini)

#define CLOSED_CLK 4
#define CLOSED_DT 5
#define CLOSED_SW 6

#include <EncButton.h>
EncButton<EB_TICK, CLOSED_CLK, CLOSED_DT, CLOSED_SW> closed_enc;

void encoder_setup() {
//  Serial.begin(9600);

  attachPCINT(CLOSED_CLK);
  attachPCINT(CLOSED_DT);

  if (SELECTION){
      closed_enc.counter = CLOSED_SP;
    }
  else {
      closed_enc.counter = OPEN_SP;
    }

  
  
}

void encoder_loop() {
  // оставляем тут для работы "временных" функций и антидребезга
  closed_enc.tick();

  if (closed_enc.turn()) {
    
    // любой поворот
    if (SELECTION){
      CLOSED_SP = closed_enc.counter;
      store_CLOSED_SP();
    }
    else {
      OPEN_SP = closed_enc.counter;
      store_OPEN_SP();
    }
  }

  if (closed_enc.click()){
    
    SELECTION = ! SELECTION;

    if (SELECTION){
      closed_enc.counter = CLOSED_SP;
    }
    else {
      closed_enc.counter = OPEN_SP;
    }
    
  }

}

// функция для настройки PCINT для ATmega328 (UNO, Nano, Pro Mini)
uint8_t attachPCINT(uint8_t pin) {
  if (pin < 8) {              // D0-D7 - PCINT2
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << pin);
    return 2;
  }
  else if (pin > 13) {        // A0-A5 - PCINT1
    PCICR |= (1 << PCIE1);
    PCMSK1 |= (1 << pin - 14);
    return 1;
  }
  else {                      // D8-D13 - PCINT0
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << pin - 8);
    return 0;
  }
}

// Векторы PCINT, нужно кинуть сюда tickISR
// пины 0-7: PCINT2
// пины 8-13: PCINT0
// пины A0-A5: PCINT1
ISR(PCINT0_vect) {

}
ISR(PCINT1_vect) {

}
ISR(PCINT2_vect) {
  closed_enc.tickISR();
}
