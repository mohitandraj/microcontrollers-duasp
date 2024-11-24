int led1 = 2;

int led2 = 8;

int led3 = 12;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);

  pinMode(led2, OUTPUT);

  pinMode(led3, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
///Y,G,R
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW);  
  delay(1000); 

  digitalWrite(led1, LOW);   
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(1000);   
  

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(1000);  
//----------------------------------

  digitalWrite(led3, 0);
  delay(500);
//RGY REVERSE
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW); 
  digitalWrite(led3, HIGH);  
  delay(1000); 

  digitalWrite(led1, LOW);   
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(1000);   
  

  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(1000);

//---------------------------
//LOW KARNA HAI
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(1000);

//---------------------------------
//ALL LIGHT BURNNNNNNN
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(1000);

  //LOW KARNA HAI
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(1000);
//----------------
//hard blink
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(200);

   //LOW KARNA HAI
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(200);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(200);

   //LOW KARNA HAI
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(200);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(200);

   //LOW KARNA HAI
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(200);
  
  //LOW KARNA HAI
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(1000);

}


