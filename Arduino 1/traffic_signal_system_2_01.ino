// Receiver
//
#include <SoftwareSerial.h>

#define rxPin 0
#define txPin A0
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);


int seconds = 0;
int signal_state = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}




void loop()
{	
  mySerial.listen();
  if(mySerial.available() > 0){
   signal_state = mySerial.read();
   Serial.print("From transmitter : ");
   Serial.println(signal_state);
  }
  if(signal_state == 5){
    turn_off_all();
    if(seconds < 18){
  
    digitalWrite(13,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(9,LOW);
   	digitalWrite(3,LOW);
    digitalWrite(11,LOW);
   	digitalWrite(5,LOW);
    
  }else if (seconds < 20){
    digitalWrite(13,LOW);
   	digitalWrite(7,LOW);
   	digitalWrite(12,HIGH);
   	digitalWrite(6,HIGH);
  }else if(seconds < 40){
    digitalWrite(12,LOW);
   	digitalWrite(6,LOW);   
   	digitalWrite(11,HIGH);
   	digitalWrite(5,HIGH);
   	digitalWrite(10,HIGH);
   	digitalWrite(4,HIGH);
    digitalWrite(8,LOW);
   	digitalWrite(2,LOW);  
  }else if(seconds < 42){
    digitalWrite(10,LOW);
   	digitalWrite(4,LOW);
    digitalWrite(9,HIGH);
   	digitalWrite(3,HIGH);
  }
    Serial.println("There's no cars");
  }else if(signal_state == 1 || signal_state == 4){
  	turn_off_all();
    digitalWrite(11,HIGH);
	digitalWrite(5,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(4,HIGH);
    Serial.println("1st signal");
  }else if(signal_state == 2 || signal_state == 3){
  	turn_off_all();
    digitalWrite(8,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(7,HIGH);
    Serial.println("2nd signal");
  }
  
 
  
  if(seconds <42){
    seconds = seconds + 1;

  }else{
    seconds = 0;
  }
  
delay(1000);
}

void turn_off_all(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);

}