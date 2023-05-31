#define inPin A0

void input_setup(){
  
  pinMode (inPin, INPUT);
  
}

int input_read(){

  return analogRead(inPin);
  
}
