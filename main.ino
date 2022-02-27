int temp;
int Time = 0;
int Day = 0;
int lightPin = 8;
int waterPin = 12;
int fanPin = 7;

#include <EduIntro.h>
DHT11 dht11(D4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(lightPin,OUTPUT);
  digitalWrite(lightPin, HIGH);

  pinMode(fanPin, OUTPUT);
  digitalWrite(fanPin,HIGH);
  
  pinMode(waterPin, OUTPUT);
  digitalWrite(waterPin, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((Time%2) == 0) {
    int sensorReading = analogRead(A0);
    
    if (sensorReading > 600) {
      digitalWrite(waterPin, HIGH); //on
      delay(4000);
      digitalWrite(waterPin, LOW);  
      }

    dht11.update();
    temp = dht11.readCelsius();
  
    if (temp >= 25) {digitalWrite(fanPin, LOW);}
    if (temp <= 22) {digitalWrite(fanPin, HIGH);}
    Serial.println(temp);
    
  } //1 hour

  Time = Time + 1;

  if (Time == 48) {
    Time = 0;
    Day = Day + 1;
  }

  if (Day >= 3) {
    //Light on
    Serial.println("Light on LOW");
    digitalWrite(8,LOW);
    }
  
  delay(1800000);
  //delay(1000);
}
