const int LEDPin = 7;
const int buttonPin = 6;

bool ledState = LOW;
bool lastButtonState = HIGH;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH){
    ledState = !ledState;
    digitalWrite(LEDPin, ledState);
  }

  lastButtonState = buttonState;
}








