// set pins for LEDs and buttons
int green_led_pin = 5;
int red_led_pin = 6;
int buttons[3] = {8,9,10};

// set hardcoded password
int passcode_arr[]= {0,1,2,0,0,0};
const int SIZE = sizeof(passcode_arr) / sizeof(int); // store size of password array
const int garbage = 999;

// store user inputs
int states[SIZE];
int index_state = 0;
bool passed = false;

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

void reset_arr(){
  // fill the array with garbage values
  for(int i = 0; i < SIZE; i++){
    states[i] = garbage;
  }
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


  // if the user gets to the last index state (correct length of password)
  if (index_state == SIZE ){
    // check if the password was input correctly - if not, turn on red LED. if so, turn on green LED.
    for ( int i = 0; i < SIZE; i++){
      if ( states[i] != passcode_arr[i] ){
        passed = false;
        digitalWrite(red_led_pin, HIGH);
        delay(1000);
        digitalWrite(red_led_pin, LOW);
        break;
      }
      passed = true;
    }  
    if ( passed ){
      digitalWrite(green_led_pin, HIGH);
      delay(1000);
      digitalWrite(green_led_pin, LOW);
    }

    // reset the state array
    index_state = 0;
    reset_arr();
    Serial.println("RESET");
  }
  
  
}
