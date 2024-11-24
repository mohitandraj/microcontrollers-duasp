// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   // check if data is available
//   // if data available the below line returns value greater than 0
//   if (Serial.available()>0){
//     char receivedData = Serial.read();//store the recieved data

//     //wait for some time
//     delay(2000);
//     //transmit the recieved data
//     Serial.print("Data received is=");
//     Serial.println(receivedData);
//   }


///////////////////////////



const int led1Pin = 9;
const int led2Pin = 11;


bool led1State = false;
bool led2State = false;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter 1 to toggle LED1, 2 to toggle LED2.");
}

void loop() {
  if (Serial.available() > 0) {
    char receivedData = Serial.read();
    
    delay(50);

    Serial.print("Data received is: ");
    Serial.println(receivedData);

    
    switch (receivedData) {
      case '1':
        led1State = !led1State; 
        digitalWrite(led1Pin, led1State ? HIGH : LOW);
        Serial.print("LED1 ");
        Serial.println(led1State ? "ON" : "OFF");
        break;

      case '2':
        led2State = !led2State;  
        digitalWrite(led2Pin, led2State ? HIGH : LOW);
        Serial.print("LED2 ");
        Serial.println(led2State ? "ON" : "OFF");
        break;

      default:
       
        Serial.println("Invalid input! Enter 1 or 2.");
        break;
    }
  }
}

