// int LED=13;
// int state=0;

// void setup(){
//   pinMode(LED,OUTPUT);
//   Serial.begin(9600);
//   //1.disable all the interrupts
//   // no interrupts should occur during the setup
//   cli();// clear and disable all interrupts

//   //2. timer settings
//   //disable the PWM on TIMER
//   TCCR1A=0;
//   TCCR1B=0;
//   // SET THE PRESCALER TO 256
//   //Check page no. 142 and 143
//   TCCR1B=0b00000100;

//   //enable the timer overflow interupt
//   // check page no. 144, 145
//   TIMSK1 = 0b00000001;

//   //enable all interrupts for arduino
//   sei();
// }
// void loop(){
//   unsigned int count = TCNT1;
//   Serial.print("Count = ");
//   Serial.println(count);
  
  
// }

// ISR(TIMER1_OVF_vect)
// {
//   state = !state;
//   digitalWrite(LED, state);

// }

///////////////////////////////////////////// 
//// now with 31250 done::::::::::::)

int LED = 13;            // Pin for LED
int state = 0;           // LED state (on/off)

void setup() {
  pinMode(LED, OUTPUT);   // Set the LED pin as output
  Serial.begin(9600);     // Start serial communication

  // 1. Disable all interrupts during setup
  cli();  // Clear and disable all interrupts

  // 2. Timer settings
  // Set the Timer1 to CTC (Clear Timer on Compare Match) mode
  TCCR1A = 0;             // Normal mode, no PWM
  TCCR1B = 0;    // CTC mode (WGM12 = 1)

  TCCR1B = 0b00000100; 
  
  TIMSK1 = 0b00000010;
  
  OCR1A = 31250;
  
 

  // 4. Enable global interrupts
  sei();  // Enable interrupts globally
}

void loop() {
  // Main loop can be empty or can perform other tasks.
  // The LED toggling will be handled by the ISR.
  unsigned int count = TCNT1;
  Serial.print("Raj ka body count = ");
  Serial.println(count);
}

// Timer1 Output Compare A Interrupt Service Routine (ISR)
ISR(TIMER1_COMPA_vect) {
  // This function is called every time Timer1 reaches OCR1A (500 microseconds)
  TCNT1 = 0;
  state = !state;            // Toggle the LED state
  digitalWrite(LED, state);  // Write the new state to the LED
}





