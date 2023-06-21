
// Global Vars
int INPUT_IO;
int OUTPUT_IO;
int CLOSED_SP;
int OPEN_SP;

bool SELECTION;

void setup(){

  EPROM_setup();
  Serial.begin(115200);
  ads1115_setup();
  encoder_setup();
  oled_setup();
  
  pot_setup();
//  ADS1115_setup();
//  digitalPotWrite(128);


//  CLOSED_SP = 100;
//  OPEN_SP = 300;
  
}

void loop(){

//  int reading = input_read();
  ads1115_loop();
  encoder_loop();
  display_loop();
  
//  
  OUTPUT_IO = map(INPUT_IO,CLOSED_SP,OPEN_SP,0,255);

  OUTPUT_IO = max(OUTPUT_IO,0);
  OUTPUT_IO = min(OUTPUT_IO,255);

  digitalPotWrite(OUTPUT_IO);

}
