/*Light Control for the big speaker. 
Definisions of pins are first on top 
Then the setup function. 
The progtram works in the game loop way were after the setup sequence it goes through the same loop 
*/

#define BASE A0
#define BRIGHTNESS A1
#define SENSITIVITY A2
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define INCRIMENT 25
#define KILL 2

int r=0;
int g=0;
int b=255;
int x=0;
 
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(KILL,INPUT_PULLUP);
  pinMode(BASE,INPUT);
  pinMode(SENSITIVITY,INPUT);
}

void DisplayLights()
{
  int ry,by,gy;
  float y;
  
  y = BrightnessFormula();
  ry = r*y;
  gy = g*y;
  by = b*y;
    
  analogWrite(REDPIN,ry);
  analogWrite(GREENPIN,gy);
  analogWrite(BLUEPIN,by);
 } 

void LightChange(int x){
    if(x<10){
      DisplayLights();
      r=r+INCRIMENT;}
  
  if((10<=x)&(x<19)){ 
    DisplayLights();
    b=b-INCRIMENT;}
  
  if((20<=x)&(x<29)){
    DisplayLights();
    g=g+INCRIMENT;}
  
  if((30<=x)&(x<39)){
    DisplayLights();
    r=r-INCRIMENT;}
  
  if((40<=x)&(x<49)){
    DisplayLights();
    b=b+INCRIMENT;}
 
  if((x>=50)&(x<59)){
    DisplayLights(); 
    g=g-INCRIMENT;}  
 }

void PartyIsOver(){
   int br = ReadBrightness();
   int y = map(br,0,1023,0,255);
    analogWrite(REDPIN,y);
    analogWrite(GREENPIN,y);
    analogWrite(BLUEPIN,y);  
 }

float BrightnessFormula(){
  int br = ReadBrightness(); 
  int val = map(br,0,1023,0,100);
  float newVal= val/100.0;
  return newVal;
 }

int ReadBrightness(){
  int brightnessMultiplier = analogRead(BRIGHTNESS); 
  return brightnessMultiplier;
}

float SensitivityFormula(){
  int Sense = ReadSensitivity();
  int Sensy = map(Sense,0,1023,0,100);  
  return Sensy;
}

int ReadSensitivity(){
  int sensitivityMultiplier = analogRead(SENSITIVITY);
  return sensitivityMultiplier;
}

void loop() {
  if(analogRead(BASE)>SensitivityFormula()){
    LightChange(x);
    x++;
  }
  if(x>60){
    r=0;
    g=0;
    b=255;
    x=0;}

  while(digitalRead(KILL)==false){
    PartyIsOver();
   } 
}
