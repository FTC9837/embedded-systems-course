const int forward = 8; 
const int backward = 9; 
int button = 12;


void setup() 
{
  pinMode(forward , OUTPUT);
  pinMode(backward , OUTPUT);
  
    pinMode(button,INPUT_PULLUP);
}

void loop(){
    if (digitalRead(button)==LOW){
        digitalWrite(forward , HIGH);
        digitalWrite(backward , LOW);

  }
  else{
    digitalWrite(forward , LOW);
    digitalWrite(backward , LOW);
  }    
}
