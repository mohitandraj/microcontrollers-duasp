int sensorPin = 2;
int ledpin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int motionDetected = digitalRead(sensorPin);

  if(motionDetected == HIGH){
    Serial.println("Motion Detected");
    digitalWrite(ledpin, HIGH);
  }
  else{
    Serial.println("Motion Not Detected");
    digitalWrite(ledpin, LOW);
  }

  delay(500);

}
