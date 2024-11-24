// // const int trigPin= 5;
// // const int echoPin= 6;

// // long duration;

// // void setup(){
// //   pinMode(trigPin,OUTPUT);
// //   pinMode(echoPin,INPUT);
// //   digitalWrite(trigPin, LOW);
// //   Serial.begin(9600);
// // }

// // void loop() {
// //   digitalWrite(trigPin, HIGH);
// //   delayMicroseconds(10);
// //   digitalWrite(trigPin, LOW);
// //   duration= pulseIn(echoPin, HIGH);
// //   Serial.print(duration/29/2);
// //   Serial.println("cm");
// //   delay(300);
// // }


// // ////////////////////////ultrasonic buzzer

// // #define PIEZO_PIN 9

// // const int trigger = 6;
// // const int echo = 7;
// // float distance;
// // float dist_inches;

// // void setup() {
// //   Serial.begin(9600);
// //   // settings for ultrasonic sensor
// //   pinMode(trigger, OUTPUT);
// //   pinMode(echo, INPUT);

// //   pinMode(PIEZO_PIN, OUTPUT);
// // }

// // void loop() {
// //   // Trigger the sensor to start measurement
// //   // Set up trigger
// //   digitalWrite(trigger, LOW);
// //   delayMicroseconds(5);

// //   // Start Measurement
// //   digitalWrite(trigger, HIGH);
// //   delayMicroseconds(10);
// //   digitalWrite(trigger, LOW);

// //   // Acquire and convert to inches
// //   distance = pulseIn(echo, HIGH);
// //   distance = distance * 0.0001657;
// //   dist_inches = distance * 39.37;

// //   if (dist_inches < 5) {
// //     tone(PIEZO_PIN, 500);
// //     delay(200);
// //     noTone(PIEZO_PIN);
// //   }
// //   if (dist_inches < 10 && dist_inches > 5) {
// //     tone(PIEZO_PIN, 1500);
// //     delay(200);
// //     noTone(PIEZO_PIN);
// //   }

// //   Serial.print("Distance: ");
// //   Serial.print(dist_inches);
// //   Serial.println(" in");
// // }


// /////////////////fox studio



// #define PIEZO_PIN 9

// const int trigger = 6;
// const int echo = 7;
// float distance;
// float dist_inches;

// // Define the notes for the Star Wars theme (Imperial March)
// int melody[] = {
//   392, 392, 392, 349, 392, 523, 523, 392, 349, 392, 523, 523, 392, 392, 392, 349, 
//   392, 523, 523, 392, 349, 392, 349, 392, 392, 392, 349, 392, 523, 523, 392, 349
// };

// int noteDurations[] = {
//   500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
//   500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500
// };

// void setup() {
//   Serial.begin(9600);
//   // Settings for ultrasonic sensor
//   pinMode(trigger, OUTPUT);
//   pinMode(echo, INPUT);

//   pinMode(PIEZO_PIN, OUTPUT);
// }

// void loop() {
//   // Trigger the sensor to start measurement
//   // Set up trigger
//   digitalWrite(trigger, LOW);
//   delayMicroseconds(5);

//   // Start Measurement
//   digitalWrite(trigger, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigger, LOW);

//   // Acquire and convert to inches
//   distance = pulseIn(echo, HIGH);
//   distance = distance * 0.0001657;
//   dist_inches = distance * 39.37;

//   // Play sound based on distance range
//   if (dist_inches < 5) {
//     tone(PIEZO_PIN, 500);  // Play tone at 500 Hz for close range
//     delay(200);
//     noTone(PIEZO_PIN);
//   }
//   if (dist_inches < 10 && dist_inches > 5) {
//     tone(PIEZO_PIN, 1500);  // Play tone at 1500 Hz for medium range
//     delay(200);
//     noTone(PIEZO_PIN);
//   }

//   // Play Star Wars theme if the distance is greater than 10 inches
//   if (dist_inches > 10) {
//     playStarWarsTheme();
//   }

//   // Print the distance for debugging
//   Serial.print("Distance: ");
//   Serial.print(dist_inches);
//   Serial.println(" in");

//   // Add a delay between measurements
//   delay(2000); // Wait for 2 seconds before taking another reading
// }

// // Function to play Star Wars theme (Imperial March) on the buzzer
// void playStarWarsTheme() {
//   for (int i = 0; i < 32; i++) { // There are 32 notes in this simplified melody
//     int noteDuration = noteDurations[i];
//     tone(PIEZO_PIN, melody[i], noteDuration);  // Play the note
//     delay(noteDuration * 1.30);  // Add some delay to let the note finish
//     noTone(PIEZO_PIN); // Stop the tone after the note duration
//   }
// }

////////////////////multi led
#define TRIG_PIN 5        // Trigger pin for ultrasonic sensor
#define ECHO_PIN 6        // Echo pin for ultrasonic sensor
#define PIEZO_PIN 9       // Buzzer connected to Pin 9

#define RED_LED_PIN 13    // Red LED pin (less than 5 cm)
#define YELLOW_LED_PIN 12 // Yellow LED pin (5 - 10 cm)
#define GREEN_LED_PIN 11  // Green LED pin (greater than 10 cm)

long duration;           // Variable to store pulse duration
float distance;           // Variable to store the distance in cm

void setup() {
  Serial.begin(9600);     // Start serial communication for debugging
  
  // Set up ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Set up the buzzer
  pinMode(PIEZO_PIN, OUTPUT);
  
  // Set up the LEDs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor to start measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);     // Wait for 5 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);    // Send a pulse for 10 microseconds
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the duration of the pulse from the Echo pin
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance (in centimeters)
  distance = (duration / 2) * 0.0344;  // Distance in cm
  
  // Logic for LED and buzzer control based on distance
  if (distance < 5) {
    // Turn on Red LED, turn off others
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    
    // Emit a tone (500 Hz) on the buzzer
    tone(PIEZO_PIN, 500);
  } 
  else if (distance >= 5 && distance < 10) {
    // Turn on Yellow LED, turn off others
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    
    // Emit a tone (1000 Hz) on the buzzer
    tone(PIEZO_PIN, 1000);
  }
  else {
    // Turn on Green LED, turn off others
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    
    // Emit a tone (1500 Hz) on the buzzer
    tone(PIEZO_PIN, 1500);
  }

  // Output the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);  // Print distance in cm
  Serial.println(" cm");

  // Short delay before the next reading
  delay(200);
  
  // Stop the buzzer after a short delay
  noTone(PIEZO_PIN);
}





