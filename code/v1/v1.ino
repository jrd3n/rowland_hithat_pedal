

void setup(){
  pot_setup();
  input_setup();
  seg_setup();
    
  digitalPotWrite(128);
}

void loop(){

  int reading = input_read();

  int mapped = map(reading,2700,3200,0,159);

  mapped = max(0,mapped);
  mapped = min(159,mapped);
  
  display_int(mapped);
  
  //map(value, fromLow, fromHigh, toLow, toHigh)
  digitalPotWrite(mapped);
}
