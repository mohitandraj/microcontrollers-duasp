int led1 = 2;
int led2 = 8;
int led3 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Alarm pattern: all LEDs flash rapidly
  for (int i = 0; i < 5; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(100);
  }

  // Delay before next phase
  delay(500);

  // Strobe effect
  for (int i = 0; i < 5; i++) {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led1, LOW);
    delay(50);
  }

  // Random flashing
  for (int i = 0; i < 5; i++) {
    int ledToLight = random(led1, led3 + 1);
    digitalWrite(ledToLight, HIGH);
    delay(100);
    digitalWrite(ledToLight, LOW);
    delay(100);
  }

  // All LEDs flash slowly for a final alert
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(300);
}

