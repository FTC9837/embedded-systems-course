/**************************************/
const int lowestPin = 2;//the lowest pin your LEDs have been attached to
const int highestPin = 7;//the highest pin your LEDs have been attached to
/**************************************/

void setup()
{
  //set pins 2 through 7 as output
  for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
  {
    pinMode(thisPin,OUTPUT); //initialize thisPin as an output
  }
}

void loop()
{
  //iterate over the pins
  //turn the led on from lowest to the highest
  for(int x = 2; x <= 3;x++){
    digitalWrite(x, HIGH);
    digitalWrite(x+2, HIGH);
    digitalWrite(x+4, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    digitalWrite(x+2, LOW);
    digitalWrite(x+4, LOW);
  }
}
