#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);
int buttons[2] = {12,13};


void setup() {
  for(int i = 0;i<2; i++){
    pinMode(buttons[i],INPUT_PULLUP);
  }
};

void loop() {
  if (digitalRead(buttons[0])==LOW){
      myStepper.step(1);
      delay(10);
    }
    if (digitalRead(buttons[1])==LOW){
      myStepper.step(-1);
      delay(10);
}
}
