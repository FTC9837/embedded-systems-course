// set pins for LEDs and buttons
int green_led_pin = 5;
int red_led_pin = 6;
int buttons[3] = {8,9,10};

// set hardcoded password
int passcode_arr[]= {0,1,2,0,0,0};
const int SIZE = sizeof(passcode_arr) / sizeof(int); // store size of password array

// store user inputs
int states[SIZE];
int index_state = 0;

void setup() {
  // set leds as output and buttons as input
  pinMode(green_led_pin, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  for(int i = 0;i<3; i++){
    pinMode(buttons[i],INPUT_PULLUP);
  }
  Serial.begin(9600);
  Serial.println("Good to go!");
}

//Reset the array and fill it with garbage values
void reset_arr(){
  for(int i = 0; i < SIZE; i++){
    states[i] = 999;
  }
}
//Check the password. If ANY of the values in the states array do not match the ones in the passcode array, return "false". Otherwise, return "true".
bool checkpassword(){
  for ( int i = 0; i < SIZE; i++){
    if (states[i] != passcode_arr[i] ){
      return false;
    }
  }
  return true;
}

void loop() {
  // check if inputs are pushed -- if so, add to the states array
  if (digitalRead(buttons[0])==LOW){
    states[index_state] = 0;
    index_state++;
    Serial.println("0");
    delay(250);
  }
  if (digitalRead(buttons[1])==LOW){
    states[index_state] = 1;
    index_state+=1;
    Serial.println("1");
    delay(250);
  }
  if (digitalRead(buttons[2])==LOW){
    states[index_state] = 2;
    index_state+=1;
    Serial.println("2");
    delay(250);
  }

  // if the user gets to the last index state (correct length of password), check if the password matches.
  if (index_state == SIZE ){
    if (checkpassword2()){
      digitalWrite(green_led_pin, HIGH);
      delay(1500);
      digitalWrite(green_led_pin, LOW);
    }
    else{
      digitalWrite(red_led_pin, HIGH);
      delay(1500);
      digitalWrite(red_led_pin, LOW);
    }
    // reset the state array
    index_state = 0;
    reset_arr();
    Serial.println("RESET");
  }  
}  
