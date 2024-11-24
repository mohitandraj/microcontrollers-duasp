void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("number daalo: ");
  int input = Serial.parseInt();
  while(!Serial.available()){

  }
  Serial.println(input);
  delay(1590);
}
