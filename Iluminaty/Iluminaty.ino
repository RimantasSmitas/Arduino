
int lumi1, lumi2, lumi3;
int light;

int btn1 = 10; 
int btn2 = 9;
int btn3 = 8;

int uvSensor =A2;
int photoCel1 = A1;
int photoCel2 = A0;

int relay1 = 2;
int relay2 = 3;
int relay3 = 4;

void setup() {

Serial.begin(9600);

pinMode(btn1, INPUT);
pinMode(btn2, INPUT);
pinMode(btn3, INPUT);

//pinMode(ldr, INPUT);
pinMode(photoCel1, INPUT);
pinMode(photoCel2, INPUT);
pinMode(uvSensor, INPUT);

pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);

//pinMode(sensorEnable, OUTPUT);
}



int LightReading(){
  int uv, photo1,photo2, lightReading;
  uv = analogRead(uvSensor);
  photo1 = analogRead(photoCel1);
  photo2 = analogRead(photoCel2);
  lightReading = (photo1 + photo2)/2+uv;
  return(lightReading); 
}


void loop() 
{
  if(digitalRead(btn1)==HIGH){
  Serial.println("button 1 pressed");
  lumi1 = LightReading();
  }
  else{
  if(digitalRead(btn2)==HIGH){
  Serial.println("button 2 pressed");
  lumi2 = LightReading();
  
  }
  else{
  if(digitalRead(btn3)==HIGH){
  Serial.println("button 3 pressed");
  lumi3 = LightReading();
  }}}
  
 Serial.print("UV ");
 Serial.println(analogRead(uvSensor)); 
 
 Serial.print("photoCell 1 ");
 Serial.println(analogRead(photoCel1)); 
 
 Serial.print("photoCell 2 ");
 Serial.println(analogRead(photoCel2)); 
 
 light = LightReading();
 if (light<lumi1){
  //relay 1 is on
  Serial.println("led1");
  digitalWrite(relay1, HIGH);
   }
  else {
     digitalWrite(relay1, LOW);
    //relay one is off
    }
    if (light<lumi2){
   // relay 2 is on
   
  Serial.println("led2");
  digitalWrite(relay2, HIGH);}
   else {
//    relay 2 is off  
     digitalWrite(relay2, LOW);}
    if (light<lumi3){
     // relay3 is on 
     
  Serial.println("led3");
   digitalWrite(relay3, HIGH);
     }
     else{
      //relay is off
     digitalWrite(relay1, LOW);}
     
 
 
 Serial.println(light); 
 delay(1000); 
  // put your main code here, to run repeatedly:

}


double levelCheck(int ilumination){
  Serial.println(ilumination);
  if(ilumination<lumi1);
  {
   //relay
   digitalWrite(relay1, HIGH);
   digitalWrite(relay2, LOW);
   digitalWrite(relay3, LOW);
  } 
  if(ilumination<lumi2&ilumination>lumi1)
  {
   digitalWrite(relay1, LOW);
   digitalWrite(relay2, HIGH);
   digitalWrite(relay3, LOW);
  }
  if(ilumination<lumi3&ilumination>lumi2)
   digitalWrite(relay1, LOW);
   digitalWrite(relay2, LOW);
   digitalWrite(relay3, HIGH);   
  }




