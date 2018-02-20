

const int ledPin= 11; 
int i = 0;         
void setup(
)
{ 
pinMode(ledPin, OUTPUT); 
} 
void loop()
{ 
for (i = 0; i < 255; i++)
{ 
analogWrite(ledPin, i);      
delay(10); 
}
for (i = 255; i > 0; i
--
) 
{
analogWrite(ledPin, i); 
delay(10);       
}
}
