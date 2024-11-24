const int numLED = 5;
const int iPin = 2;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < numLED; i++){
    pinMode(iPin+i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0,j=1; i<numLED; i++,j++){
    digitalWrite(iPin+i, HIGH);
    digitalWrite(j, HIGH);
    delay(1000);
    digitalWrite(iPin+i, LOW);
    digitalWrite(j, LOW);
  }
  // for(int i=numLED-1, j=numLED; i>=0; i--){
  //   digitalWrite(iPin+i, HIGH);
  //   digitalWrite(j, HIGH);
  //   delay(1000);
  //   digitalWrite(iPin+i, LOW);
  //   digitalWrite(j, LOW);
  // }

}