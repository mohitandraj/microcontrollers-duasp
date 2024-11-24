#include <DHT.h>

#define DHTPIN 2        // Pin connected to the DHT22 sensor
#define DHTTYPE DHT22   // DHT22 (AM2302) sensor

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);  // Delay 2 seconds for the next reading
  
  // Read humidity
  float humidity = dht.readHumidity();
  
  // Read temperature in Celsius
  float temperature = dht.readTemperature();
  
  // Check if the readings failed and print an error message
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return; // Stop if there was an error
  }

  // Print the temperature and humidity values to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}

