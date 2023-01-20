#include <SoftwareSerial.h>

// Create a software serial object for the Bluetooth module
SoftwareSerial BTserial(2,3); // RX, TX

#define mpin00 8
#define mpin01 9
#define mpin10 10
#define mpin11 11

// LED pin 
const int ledPin = 13;

void setup() {
  Serial.begin(9600); // start the serial communication for debugging
  BTserial.begin(9600); // start the serial communication for the Bluetooth module
  pinMode(ledPin, OUTPUT); // set the LED pin as an output
}

void loop() {
  if (BTserial.available()) {
    String receivedData = "";
    while(BTserial.available()){
      receivedData += (char)BTserial.read();
      delay(2);
    }
    // check if the received data is "turnOn"
    if (receivedData == "FF") {
      //the car goes forwards
      digitalWrite(ledPin, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      Serial.println(receivedData);
    }
    // check if the received data is "turnOff"
    if (receivedData == "BB") {
      //the car goes backwards
      digitalWrite(ledPin, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    }

    if (receivedData == "LL") {
      //the car goes left
      digitalWrite(ledPin, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }

    if (receivedData == "RR") {
      //the car goes left
      digitalWrite(ledPin, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    }

    if(receivedData == "SS"){
      //the car stops
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }
    Serial.println(receivedData); // print the received data to the serial monitor for debugging
  }
}