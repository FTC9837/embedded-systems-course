//www.elegoo.com
//2020.3.12

#include "IRremote.h"
#include "IR.h"

IRrecv irrecv(RECEIVER);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop()
{
  int tmpValue;
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    for (int i = 0; i < 23; i++)
    {
      if ((keyValue[i] == results.value) && (i<KEY_NUM))
      {
        Serial.println(keyBuf[i]);
        tmpValue = results.value;
      }
      else if(REPEAT==i)
      {
        results.value = tmpValue;
      }
    }
    irrecv.resume(); // receive the next value
  }
}
