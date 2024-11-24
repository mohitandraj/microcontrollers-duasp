int buttonPin = 2;
volatile int FLAG = 0;
int led = 13;
void ButtonISR();


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), ButtonISR, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(FLAG == 1){
    digitalWrite(led, HIGH);
    FLAG = 0;
  }
}
void ButtonISR(){
  FLAG = 1;
}
