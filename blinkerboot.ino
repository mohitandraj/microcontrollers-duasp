// Pin for LED
const int ledPin = 13;

// Timer settings
volatile bool timerFlag = false;

void setup() {
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);

  // Initialize Timer1
  // Set Timer1 to normal mode (no CTC or PWM), and overflow interrupts
  TCCR1A = 0;            // Set Timer1 to normal mode (no PWM)
  TCCR1B = (1 << CS12);  // Prescaler = 256, CS12 bit for prescaler setting

  // Enable Timer1 overflow interrupt
  TIMSK1 = (1 << TOIE1); // Enable overflow interrupt for Timer1

  // Enable global interrupts
  sei();
}

void loop() {
  // Main loop doesn't need to do anything, the ISR will handle the LED toggle
  if (timerFlag) {
    // Toggle the LED state
    digitalWrite(ledPin, !digitalRead(ledPin));

    // Reset the timer flag
    timerFlag = false;
  }
}

// Timer1 Overflow Interrupt Service Routine (ISR)
ISR(TIMER1_OVF_vect) {
  // This ISR is triggered whenever Timer1 overflows (about every 1 second with prescaler 256)
  
  // Set the flag when overflow occurs
  timerFlag = true;
}

