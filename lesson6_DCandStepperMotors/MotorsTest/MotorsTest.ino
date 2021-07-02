const int forward = 8; 
const int backward = 9; 

void setup() 
{
  pinMode(forward , OUTPUT);
  pinMode(backward , OUTPUT);
}
void loop()
{
  digitalWrite(forward , HIGH);
  digitalWrite(backward , LOW);

}
