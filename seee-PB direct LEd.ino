//Example 2 : PUSH BOTTON TURN ON LED

 const int LED = 11;
 const int PB = 3;
 int on;
 
 void setup()
 {
  
  pinMode (LED,OUTPUT);
  pinMode (PB,INPUT);
  
 }

 void loop()
 {
  on = digitalRead(PB);
  if (on == HIGH)
  {
    digitalWrite (LED, HIGH);
  delay (2000);

  digitalWrite (LED, LOW);
  delay (1500);  
  }
  else
  {
    digitalWrite (LED, LOW);
  }
 }
  