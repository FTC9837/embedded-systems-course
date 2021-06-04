#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int buttons[2] = {5,6};

void setup(){
  myservo.attach(4);  // attaches the servo on pin 4 to the servo object
  myservo.write(90);
  delay(1000);
  for(int i = 0;i<2; i++){
    pinMode(buttons[i],INPUT_PULLUP);
  }
}

void loop(){
    if (digitalRead(buttons[0])==LOW){
      for(int i=0;i<3;i++){
        myservo.write(45);
        delay(750);
        myservo.write(135);
        delay(750);
      }
      myservo.write(90);
      delay(1000);
    }
    if (digitalRead(buttons[1])==LOW){
      for(int i=0;i<3;i++){
        myservo.write(0);
        delay(750);
        myservo.write(90);
        delay(750);
      }
      myservo.write(90);
      delay(1000);
  }

}
