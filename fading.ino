int led[] = {9, 10, 11, 3}; // LED pins: 9, 10, 11, and 3 (PWM-capable)

int brightness[] = {0, 0, 0, 0}; 
int fadeAmount = 5;  

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  
  for (int i = 0; i < 4; i++) {
    analogWrite(led[i], brightness[i]);

    brightness[i] = brightness[i] + fadeAmount;

    if (brightness[i] <= 0 || brightness[i] >= 255) {
      fadeAmount = -fadeAmount; 
    }
  }

  
  delay(10);  
}



// /////single led

// int led = 9;
// int brightness = 0;
// int fadeAmount = 5;

// void setup(){
//   pinMode(led, OUTPUT);
// }

// void loop(){
//   //put your main code here, to run repeatedly 
//   analogWrite(led, brightness); // set the initial brightness of led

//   brightness = brightness + fadeAmount;

//   delay(30);

//////okokoko



