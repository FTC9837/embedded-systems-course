int ledpins[5] = {2,3,4,5,6};

void setup() {
  // put your setup code here, to run once:
pinMode(A1, INPUT);
for(int i = 0; i < 5; i++){
  pinMode(ledpins[i], OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 0; j < 5; j++){
    if(analogRead(A1) >= (190 * (j+1))){
      digitalWrite(ledpins[j], HIGH);
    }
    else{
      digitalWrite(ledpins[j], LOW);
    }
}
}
