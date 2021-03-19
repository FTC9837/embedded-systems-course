int ledPin = 5; // single LED pin
int buttonAPin = 9; // the left button
int buttonBPin = 8; // the right button

void setup() {
  // set buttons to be used as an input
  pinMode(ledPin, OUTPUT);
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonAPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonBPin) == LOW) {
    digitalWrite(ledPin, LOW);
  }

}
