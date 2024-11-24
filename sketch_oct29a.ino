int led1 = 2;
int led2 = 8;
int led3 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Chase pattern
  for (int i = 0; i < 3; i++) {
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(50);

    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(50);

    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    delay(50);
  }

  // Random flash
  for (int i = 0; i < 5; i++) {
    int ledToLight = random(led1, led3 + 1);
    digitalWrite(ledToLight, HIGH);
    delay(200);
    digitalWrite(ledToLight, LOW);
    delay(random(100, 300));
  }

  // All LEDs flash together
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(200);
}
