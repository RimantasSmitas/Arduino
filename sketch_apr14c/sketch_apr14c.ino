int btn1 = 9; 
int btn2 = 5;
int btn3 = 7;
int brightness = 0;

void setup()
{
pinMode(btn1, INPUT);
pinMode(btn2, INPUT);
pinMode(btn3, INPUT);

  Serial.begin(9600);
}

void loop()
{
  
  delay(500);
if(digitalRead(btn1)==1){
  if (brightness == 100 )
  {brightness = 0;}
  else{
  brightness +=10;
  }
  Serial.println("Brightness");
  
  delay(100);
  }
  
  if(digitalRead(btn2)==1){
   Serial.println("nextcolor");
   
  delay(100);
  }
  if(digitalRead(btn3)==1)
  {
  Serial.println("next prog");
  
  delay(100);
  }

}
