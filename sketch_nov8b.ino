// #include <DHT.h>

// int DHTPIN = 2;
// int LEDPin1 = 9;
// int LEDPin2 = 11;       
// #define DHTTYPE DHT22

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   pinMode(LEDPin1, OUTPUT);
//   pinMode(LEDPin2, OUTPUT);
//   Serial.begin(9600);
//   dht.begin();
// }

// void loop() {

//   float humidity = dht.readHumidity();
//   float temperature = dht.readTemperature();

//   if(humidity > 60 && temperature > 30){
//     digitalWrite(LEDPin2, LOW);
//     digitalWrite(LEDPin1, HIGH);
//     Serial.println("High Temperature and Humidity");
//     delay(10000);
//     digitalWrite(LEDPin1, LOW);
//   }
//   if(humidity < 60 && temperature < 30){
//     digitalWrite(LEDPin2, HIGH);
//   }
 

//   if (isnan(humidity) || isnan(temperature)) {
//     Serial.println("Failed to read from DHT sensor!");
//     delay(2000);
//     return;
//   }

//   Serial.print("Humidity: ");
//   Serial.print(humidity);
//   Serial.print(" %\t");
  
//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.println(" °C");

//   delay(2000);
// }





#include <DHT.h>

int DHTPIN = 2;         // Pin where the DHT sensor is connected
int LEDPin1 = 9;        // LED Pin 1
int LEDPin2 = 11;       // LED Pin 2
#define DHTTYPE DHT22   // Define the sensor type
	
#define BUZZER 5

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LEDPin1, OUTPUT);  // Initialize LED1 as output
  pinMode(LEDPin2, OUTPUT);  // Initialize LED2 as output
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);         // Initialize serial communication
  dht.begin();                // Initialize the DHT sensor
}

void loop() {
  // Read humidity and temperature from the sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if the reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);  // Delay for 2 seconds before trying again
    return;
  }

  // Print humidity and temperature data to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Condition 1: If both temperature > 30 and humidity > 60
  if (humidity > 60 && temperature > 30) {
    digitalWrite(LEDPin2, LOW);        // Turn off LED 2
    digitalWrite(LEDPin1, HIGH);       // Turn on LED 1
    tone(BUZZER, 85); //Set the voltage to high and makes a noise
    delay(1000);//Waits for 1000 milliseconds
    noTone(BUZZER);//Sets the voltage to low and makes no noise
    delay(1000);
    Serial.println("High Temperature and Humidity");
    delay(10000);                      // Keep the buzzer and LED on for 10 seconds
    digitalWrite(LEDPin1, LOW);        // Turn off LED 1
    
  }
  
  // Condition 2: If both temperature < 30 and humidity < 60
  if (humidity < 60 && temperature < 30) {
    digitalWrite(LEDPin2, HIGH);       // Turn on LED 2
  }

  delay(2000);  // Wait for 2 seconds before the next loop iteration
}

