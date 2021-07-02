const int forward = 8; 
const int backward = 9; 
int buttons[2] = {12,13};
int spd = 0;

void setup() 
{
  pinMode(forward , OUTPUT);
  pinMode(backward , OUTPUT);
  for(int i = 0;i<2; i++){
    pinMode(buttons[i],INPUT_PULLUP);
  }
}

void loop(){
    if ((digitalRead(buttons[0])==LOW) && (spd < 255)){
      spd += 1;
      delay(10);
    }
    if ((digitalRead(buttons[1])==LOW) && (spd > -255)){
      spd -= 1;
      delay(10);
}   
  writeSpeed(spd);
}

void writeSpeed(int sped){
  if(spd > 0){
    analogWrite(forward, abs(sped));
    analogWrite(backward, 0);
  }
  else if(spd < 0){
    analogWrite(forward, 0);
    analogWrite(backward, abs(sped));
  }
  else{
    analogWrite(forward, 0);
    analogWrite(backward, 0);
  }
}
