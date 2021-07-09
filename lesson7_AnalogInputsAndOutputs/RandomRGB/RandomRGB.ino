int rgb[3] = {9,10,11};
int randint = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 3; i++){
     pinMode(rgb[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 0; j < 3; j++){
     randint = random(255);
     analogWrite(rgb[j], randint);
  }
  delay(1000);
}
