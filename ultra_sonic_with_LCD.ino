#include <LiquidCrystal.h>;

LiquidCrystal lcd(1,2,4,5,6,7);

const int trigPin=9;
const int echoPin=10;

int Led= 13;

long duration;
int distance; 


void setup() {
  lcd.begin (16,2);
  pinMode (Led, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin (9600);

}

void loop() 
{

  
  digitalWrite (trigPin,LOW);
  delayMicroseconds (2);

  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);

  duration = pulseIn (echoPin, HIGH);
  distance = duration/58   ;

  Serial.print ("Distance: ");
  Serial.print (distance);
  Serial.println (" cm");
  delay (120);

  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distance); // Prints the distance value from the sensor
  lcd.print("  cm");
  
 


 
  

}

