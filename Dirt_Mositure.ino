int relayPin = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
 }

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(A0);

  Serial.println(sensorReading);

  if (sensorReading > 600) {
    digitalWrite(relayPin, HIGH); //on
    delay(4000);
    digitalWrite(relayPin, LOW);
  }
}
