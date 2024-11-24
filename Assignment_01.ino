#include <DHT.h>

int DHTPIN = 2;
int LEDPin = 13;       
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println("Enter Humidity Threshold: ");
  while(Serial.available()==0){

  }
  float humthr = Serial.parseFloat();
  Serial.println(humthr);
  
  Serial.println("Enter Temperature Threshold: ");
  while(Serial.available()==0){

  }
  float tempthr = Serial.parseFloat();
  Serial.println(tempthr);

  if(humidity > humthr && temperature > tempthr){
    digitalWrite(LEDPin, HIGH);
    Serial.println("High Temperature and Humidity");
    delay(10000);
    digitalWrite(LEDPin, LOW);
  }
  else if(temperature>tempthr){
    digitalWrite(LEDPin, HIGH);
    Serial.println("High Temperature");
    delay(5000);
    digitalWrite(LEDPin, LOW);
  }
  else if(humidity>humthr){
    digitalWrite(LEDPin, HIGH);
    Serial.println("High Humidity");
    delay(8000);
    digitalWrite(LEDPin, LOW);
  }

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(2000);
}