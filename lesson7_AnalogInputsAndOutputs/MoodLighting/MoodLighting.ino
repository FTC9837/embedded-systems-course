int volts = 0;
int red= 0;
int green = 0;
int blue = 0;
int rgb[3] = {9,10,11};

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  for(int i = 0; i < 3; i++){
     pinMode(rgb[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  volts = (analogRead(A1) * 0.5);
  if(volts < 255){
    red = 255;
    green = 255;
    blue = volts;
  }
  if(volts >= 255){
    red = 255 - (volts - 255);
    green = 255 - (volts - 255);
    blue = 255;
  }
  
  analogWrite(rgb[0], red);
  analogWrite(rgb[1], green);
  analogWrite(rgb[2], blue);
  Serial.println(volts);
  
}
