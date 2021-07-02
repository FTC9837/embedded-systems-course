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
    if ((digitalRead(buttons[1])==LOW) && (spd > 0)){
      spd -= 1;
      delay(10);
}   
  analogWrite(forward, spd);
  analogWrite(backward, 0);
}
