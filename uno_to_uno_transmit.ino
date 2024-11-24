  int buttonPin = 2;
  int ledpin = 12;

  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
    pinMode(ledpin, OUTPUT);

  }

  void loop() {
    // put your main code here, to run repeatedly:
    if(digitalRead(buttonPin == HIGH)){
      digitalWrite(ledpin, HIGH);
      Serial.write("Button pressed from arduino 1");
      delay(500);
    }else {
      digitalWrite(ledpin, LOW);
    }

}



//////////////////////////////


// int buttonPin = 2;   // Pin where the button is connected
// int ledPin = 12;     // Pin where the LED is connected (on the sender Arduino, if you want feedback)

// void setup() {
//   Serial.begin(9600);   // Start serial communication
//   pinMode(buttonPin, INPUT);  // Set button pin as input
//   pinMode(ledPin, OUTPUT);    // Set LED pin as output
// }

// void loop() {
//   // Check if the button is pressed
//   if (digitalRead(buttonPin) == HIGH) {
//     // Turn on LED on the sender (optional)
//     digitalWrite(ledPin, HIGH);
    
//     // Send the message to the receiver Arduino
//     Serial.println("Button pressed from Arduino 1");
    
//     // Delay for debouncing and to avoid sending multiple messages
//     delay(500);
//   } else {
//     // Turn off LED on the sender
//     digitalWrite(ledPin, LOW);
//   }
// }







// -------------------------------------- for receiver

// int ledPin = 12;

// void setup(){
//   Serial.begin(9600);
//   pinMode(ledPin, OUTPUT);
// }

// void loop(){
//   if(Serial.available()>0){
//     String receivedData = Serial.readStringUntil('\n');
//     if(receivedData == 'Button pressed from arduino 1'){
//       digitalWrite(ledPin, HIGH);
//       delay(500);
//     } else {
//       digitalWrite(ledPin, LOW);
//     }
//   }
// }








