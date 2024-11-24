#include <SoftwareSerial.h>

// Initialize SoftwareSerial with RX pin 3 and TX pin 2
SoftwareSerial mySerial(3, 2); // RX, TX

unsigned int HighByte = 0;
unsigned int LowByte = 0;
unsigned int Len = 0;

void setup() {
  // Start the built-in serial communication to output distance to Serial Monitor
  Serial.begin(9600);
  // Start SoftwareSerial communication with the US-100 at 9600 baud rate
  mySerial.begin(9600);
}

void loop() {
  // Clear any leftover data from previous loop
  mySerial.flush();

  // Send the trigger byte (0x55) to start distance measurement
  mySerial.write(0x55);

  // Wait a bit to allow the sensor to process the command
  delay(500);

  // Check if we have received two bytes from the sensor
  if (mySerial.available() >= 2) {
    // Read the two bytes
    HighByte = mySerial.read();
    LowByte = mySerial.read();

    // Calculate the distance in millimeters
    Len = HighByte * 256 + LowByte;

    // Check if the distance value is within a reasonable range
    if (Len > 1 && Len < 10000) {
      // Convert the distance to centimeters
      float distanceInCm = Len / 10.0; // Convert mm to cm

      // Print the distance to the Serial Monitor in centimeters
      Serial.print("Distance: ");
      Serial.print(distanceInCm, 2); // Print distance with 2 decimal places
      Serial.println(" cm");
    }
  }

  // Wait for a moment before taking the next reading
  delay(300); 
}






