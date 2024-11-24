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

  if(humidity > 60 && temperature > 30){
    digitalWrite(LEDPin, HIGH);
    Serial.println("High Temperature and Humidity");
    delay(10000);
    digitalWrite(LEDPin, LOW);
  }
  else if(temperature>30){
    digitalWrite(LEDPin, HIGH);
    Serial.println("High Temperature");
    delay(5000);
    digitalWrite(LEDPin, LOW);
  }
  // else if(humidity>60){
  //   digitalWrite(LEDPin, HIGH);
  //   Serial.println("High Humidity");
  //   delay(8000);
  //   digitalWrite(LEDPin, LOW);
  // }

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