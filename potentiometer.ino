int pot = 0;
int ledpin = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  
}

void loop()
{
  
  pot = analogRead(A0);
  int val = map(pot, 0, 1023, 0, 255);
  analogWrite(ledpin, val);
  Serial.println(val);
  delay(100);

}