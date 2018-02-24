const int sensorPin = A0;
const int led = 7;
int sensorValue;
void setup ()
{
 pinMode(led, OUTPUT);
}
void loop ()
{
 sensorValue = analogRead(sensorPin);
 digitalWrite(led, HIGH);
 delay(sensorValue);
 digitalWrite(led, LOW);
 delay(sensorValue);
 }
