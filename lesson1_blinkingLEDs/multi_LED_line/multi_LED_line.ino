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
  //iterate over the pinss
  //turn the led on from lowest to the highest
  for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
  {
    digitalWrite(thisPin,HIGH);//turn this led on
    delay(100);//wait for 100 microseconds
    digitalWrite(thisPin, LOW);//turn this led off
  }

  //turn the led on from highest to lowest
  for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--)
  {
    digitalWrite(thisPin,HIGH);//turn this led on
    delay(100);//wait for 100 microseconds
    digitalWrite(thisPin,LOW);//turn this led off
  }
}
