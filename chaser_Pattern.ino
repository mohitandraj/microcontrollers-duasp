// Define the number of LEDs and starting pin
const int numLED = 5;
const int iPin = 2;
const int buttonPin = 3;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < numLED; i++){
    pinMode(iPin+i, OUTPUT);
    pinMode(buttonPin, INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
  for(int i=0; i<numLED; i++){
    digitalWrite(iPin+i, HIGH);
    delay(100);
    digitalWrite(iPin+i, LOW);
  }
  for(int i=numLED-1; i>=0; i--){
    digitalWrite(iPin+i, HIGH);
    delay(100);
    digitalWrite(iPin+i, LOW);
  }
  }
}
