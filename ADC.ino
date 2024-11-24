int sensorPin = A1;
int digitalValue = 0;
float analogVoltage =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalValue = analogRead(sensorPin);
  Serial.print("digital value = ");
  Serial.println(digitalValue);
  delay(2000);
  analogVoltage = (digitalValue*5)/1023.00;
  Serial.print("Analog Voltage = ");
  Serial.println(analogVoltage);
  delay(1000);
}
