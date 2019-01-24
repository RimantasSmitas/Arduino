
int lumi1, lumi2, lumi3;
int uv, photo1,photo2;
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

int phArray [10];
int phArray2 [10];
int uvArray [10];

void setup() {

  Serial.begin(9600);
  Serial.println("Setup");
  
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

  attachInterrupt(btn1, saveValue1, RISING);
  attachInterrupt(btn2, saveValue2, RISING);
  attachInterrupt(btn3, saveValue3, RISING);

  pinMode(photoCel1, INPUT);
  pinMode(photoCel2, INPUT);
  pinMode(uvSensor, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  initArrays();
  Serial.println("Arrays initialized ");
}

void initArrays (){
  int i; 
  for (i = 0; i <= 9; i++){
  Serial.println(i);
  phArray[i] = analogRead(photoCel1);
  phArray2[i] =analogRead(photoCel2);
  uvArray[i] = analogRead(uvSensor);
}
}

void updateArrayData(){
 int i;
 phArray[9] = 0;
 phArray2[9] = 0;
 uvArray[9] = 0;
  for (i = 9;i >= 1; i--){
    phArray[i] = phArray[i-1];
    phArray2[i] = phArray2[i-1];
    uvArray[i] = uvArray[i-1];
  }
  phArray[0] = analogRead(photoCel1);
  phArray2[0] = analogRead(photoCel2);
  uvArray[0] = analogRead(uvSensor);
}
int getArrayAverage(){
  photo1 = 0;
  photo2 = 0;
  uv = 0;
  int i ;
  for (i = 0;i <= 9;i++){
  photo1 += phArray[i];
  photo2 += phArray2[i];
  uv += uvArray[i];
  }
  photo1 = photo1/10;
  photo2 = photo2/10;
  uv = uv/10;
}

int LightReading(){
  int lightReading;
/*  uv = analogRead(uvSensor);
  photo1 = analogRead(photoCel1);
  photo2 = analogRead(photoCel2);
  lightReading = (photo1 + photo2)/2+uv;
  return(lightReading); 
*/
  updateArrayData();
  getArrayAverage();
  lightReading=(photo1+photo2)/2+uv;
  return(lightReading);
}

void saveValue1(){
  Serial.println("button 1 pressed");
  lumi1 = LightReading();
  }

void saveValue2(){
  Serial.println("button 2 pressed");
  lumi2 = LightReading();
  }
void saveValue3(){
  Serial.println("button 3 pressed");
  lumi3 = LightReading();
  }

void loop() 
{/*
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
  */
 Serial.print("UV");
 Serial.println(uv); 
 
 Serial.print("photoCell 1 ");
 Serial.println(photo1); 
 
 Serial.print("photoCell 2 ");
 Serial.println(photo2); 
 
 levelCheck();
 delay(1000); 
  // put your main code here, to run repeatedly:

}


void levelCheck(){
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
  }




