// include the EduIntro library
#include <EduIntro.h>

DHT11 dht11(D4);  // creating the object sensor on pin 'D7'

int temp;   // temperature C readings are integers
int relayPin = 7;

void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin,HIGH);
}

void loop()
{
  dht11.update();
  temp = dht11.readCelsius();     	
  
  Serial.println(temp);

  if (temp >= 22) {
    digitalWrite(relayPin, LOW);}
  if (temp <= 19) {digitalWrite(relayPin, HIGH);}

  delay(1000);          
}
