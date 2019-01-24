#define YELLOW 0
#define GREEN 1
#define RED 2
#define BLUE 3

#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10

int nrOfLightsOn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);

  pinMode(BUTTON1,INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON2,INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON3,INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON4,INPUT_PULLUP); // button is connected to ground

  Testfunction();
}

void blink(int i){
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
   delay(500);
   digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
}

void BilnkAllSeries(){
  blink(YELLOW);
  delay(500);
  blink(GREEN);
  delay(500);
  blink(RED);
  delay(500);
  blink(BLUE);
 }
void BilnkAll(){
delay(500);
LightsOn();
delay(500);
LightsOff();
delay(500);
LightsOn();
delay(500);
LightsOff();
delay(500);

}
 
void LightsOn(){
  digitalWrite(YELLOW,HIGH);
  digitalWrite(GREEN,HIGH);
  digitalWrite(RED,HIGH);
  digitalWrite(BLUE,HIGH);
  }
void LightsOff(){
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(RED,LOW);
  digitalWrite(BLUE,LOW);
  }
  
void Testfunction(){
  delay(500);
  BilnkAll();
  BilnkAllSeries();
  delay(500);
  
  delay(500);
int i = 0;

 /* while(i<4){
  if (0 == digitalRead(BUTTON1))
  {
    digitalWrite(BLUE,LOW);
    i++;
  }else{}
   if (0 == digitalRead(BUTTON2))
  {    
    digitalWrite(RED,LOW);
    i++;
  }else{} 
  if (0 == digitalRead(BUTTON3))
  {
    digitalWrite(GREEN,LOW);
    i++;
  }else{}
  if (0 == digitalRead(BUTTON4))
  {
   digitalWrite(YELLOW,LOW);
   i++;
  }else{}
  }
  */
}

  

void loop() {
  delay(1000);
  // put your main code here, to run repeatedly:
 if (0 == digitalRead(BUTTON1))
  {
    digitalWrite(BLUE,LOW);
    nrOfLightsOn--;
  }else{}
   if (0 == digitalRead(BUTTON2))
  {    
    digitalWrite(RED,LOW);
    nrOfLightsOn--;
  }else{} 
  if (0 == digitalRead(BUTTON3))
  {
    digitalWrite(GREEN,LOW);
    nrOfLightsOn--;
  }else{}
  if (0 == digitalRead(BUTTON4))
  {
   digitalWrite(YELLOW,LOW);
   nrOfLightsOn--;
  }
if (nrOfLightsOn<1)
{
nrOfLightsOn=4;
  digitalWrite(YELLOW,HIGH);
  digitalWrite(GREEN,HIGH);
  digitalWrite(RED,HIGH);
  digitalWrite(BLUE,HIGH);
  
}
}
