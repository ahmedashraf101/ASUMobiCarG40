case 't'://angle
   while(1){if(Serial.available()){
   
  
  command=Serial.read();
  str=String(command);
  if (isDigit(command)==0)break;
 Serial.println(str);
 fullno=fullno+str;
 Serial.println(fullno);
}
 }number=fullno.toInt();
 Serial.println(number);fullno="";
 while(1){int i=1;
  while(1)
  {left(13,255,255);
  breakRobot(250);
  i++;Serial.println(i);
  if(i>number/2) break;
  }number=0;break;}
 

 breakRobot(1);
 coast(0);
 
    break;
   
    case 's'://distance
    
while(1){if(Serial.available()){
   
  
  command=Serial.read();
  str=String(command);
  if (isDigit(command)==0)break;
 Serial.println(str);
 fullno=fullno+str;
 Serial.println(fullno);
}
 }number=fullno.toInt();
 Serial.println(number);fullno="";
 while(1){forward(22*number,100);number=0;break;}
 

 breakRobot(10);
    break;
