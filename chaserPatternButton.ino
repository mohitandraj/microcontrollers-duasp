// // Define the number of LEDs and starting pin
const int numLED = 4;
const int iPin = 2;
const int buttonPin = 9;

// bool led_state = LOW;
// bool lastbuttonstate = HIGH;
 
// void setup() {
//   // put your setup code here, to run once:
//   for(int i = 0; i < numLED; i++){
//     pinMode(iPin+i, OUTPUT);
    pinMode(buttonPin, INPUT);
//   }

// }

// void loop() {
//   // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
//   if(buttonState == LOW && lastbuttonstate == HIGH){
//   for(int i=0; i<numLED; i++){
//     led_state = !led_state;
//     digitalWrite(iPin+i, led_state);
//     delay(100);
//     digitalWrite(iPin+i, !led_state);
//   }
//   // for(int i=numLED-1; i>=0; i--){
//   //   // led_state = !led_state;
//   //   digitalWrite(iPin+i, led_state);
//   //   delay(100);
//   //   digitalWrite(iPin+i, !led_state);
//   // }
//   }
//   lastbuttonstate = buttonState;
// }




const int LEDPins[] = {2, 3, 4, 5};  // Pin numbers for 4 LEDs
const int buttonPin = 6;             // Button pin

int buttonState = HIGH;              // Current button state
int lastButtonState = HIGH;          // Previous button state
bool chaserActive = false;           // Track whether the chaser is active
int direction = 1;                   // 1 for forward, -1 for reverse
int ledIndex = 0;                    // To track which LED to light up

void setup() {
  // Initialize LED pins as OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }
  
  pinMode(buttonPin, INPUT);          // Initialize button pin as INPUT
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the button state

  // Check if button is pressed and state has changed (debounced)
  if (buttonState == LOW && lastButtonState == HIGH) {
    chaserActive = !chaserActive;  // Toggle chaserActive when button is pressed
    delay(200);                    // Debounce delay
  }
  
  if (chaserActive) {
    // LED chasing effect based on the direction
    digitalWrite(LEDPins[ledIndex], LOW);  // Turn off the current LED

    // Update LED index depending on the direction
    ledIndex += direction;
    
    // Make sure the ledIndex is within bounds (0 to 3)
    if (ledIndex < 0) ledIndex = 0;
    if (ledIndex > 3) ledIndex = 3;
    
    digitalWrite(LEDPins[ledIndex], HIGH);  // Turn on the new LED
    delay(250);  // Delay to control the speed of the chaser
    
    // If we reach the end of the LEDs, reverse the direction
    if (ledIndex == 3 || ledIndex == 0) {
      direction = -direction;  // Reverse the direction
    }
  } else {
    // If the chaser is not active, make sure all LEDs are turned off
    for (int i = 0; i < 4; i++) {
      digitalWrite(LEDPins[i], LOW);
    }
  }

  lastButtonState = buttonState;  // Update the last button state
}




