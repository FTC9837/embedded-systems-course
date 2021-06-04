#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup(){
  myservo.attach(4);  // attaches the servo on pin 4 to the servo object
}

void loop(){
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);
    delay(1000);
}
