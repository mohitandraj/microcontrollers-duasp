const int LEDPin = 7;
const int buttonPin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonstate = digitalRead(buttonPin);

  if(buttonstate == HIGH){
    delay(100);
    if(buttonstate == 1){
      // pinMode(LEDPin, INPUT);
      // int x = digitalRead(LEDPin);
      pinMode(LEDPin, OUTPUT);
      digitalWrite(LEDPin, HIGH);}
  }
  else{
      digitalWrite(LEDPin, LOW);
    }
  

}
