//Example 3 2 push bottons 

const int LED = 13;
const int ON=2;
const int OFF=3; 
 void setup ()
 {
  pinMode(LED ,OUTPUT);
  pinMode(ON , INPUT);
  pinMode(OFF , INPUT);
  
 }
void loop ()
{
  if (digitalRead (ON)==HIGH)
  {
  digitalWrite (LED,LOW);
  }
  else if (digitalRead (OFF)==HIGH)
  {
  digitalWrite (LED,HIGH);
  }
}

