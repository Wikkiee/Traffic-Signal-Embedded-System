// Transmitter
//
#include <SoftwareSerial.h>

#define rxPin 1
#define txPin 2
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

const int trigPin = 12;
const int echoPin = 13;
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 7;
const int echoPin2 = 8;
const int trigPin3 = 5;
const int echoPin3 = 6;
int duration = 0;
int distanceCm = 0;
int duration1 = 0;
int distanceCm1 = 0;
int duration2 = 0;
int distanceCm2 = 0;
int duration3 = 0;
int distanceCm3 = 0;


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
}

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  distanceCm = distanceCm+3;

  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceCm1= duration1*0.034/2;
  distanceCm1 = distanceCm1+3;

  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distanceCm2=duration2*0.034/2;
  distanceCm2= distanceCm2+3;

  
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distanceCm3=duration3*0.034/2;
  distanceCm3= distanceCm3+3;

  
  
  if(distanceCm < 80){
    Serial.print("Distance Sensor 1 : ");
  	Serial.println(distanceCm);
    mySerial.write(1);
  }else if(distanceCm1< 80){
    Serial.print("Distance Sensor 2 : ");
  	Serial.println(distanceCm1);
    mySerial.write(2);
  }else if(distanceCm2< 80){
    Serial.print("Distance Sensor 3: ");
  	Serial.println(distanceCm2);
    mySerial.write(3);
  }else if(distanceCm3< 80){
    Serial.print("Distance Sensor 4: ");
  	Serial.println(distanceCm3);
    mySerial.write(4);
  }else{
     Serial.println("Distance Sensor : Nothing ");
	 mySerial.write(5);
  }
  delay(1000);
                
}