#define YELLOW 0
#define GREEN 1
#define RED 2
#define BLUE 3

#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10
#define SPEAKER 9

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int nrOfLightsOn = 0;

struct gamePadType{
  int PinNrLed;
  int Frequency;
  int PinNrButton;
  };
 
gamePadType Yellow={0,440,10};
gamePadType Green={1,392,11};
gamePadType Red={2,349,12};
gamePadType Blue={3,330,13};
gamePadType GamePad[]={Yellow,Green,Red,Blue};

void playSondOn(gamePadType i){
  tone(SPEAKER, i.Frequency);
  } 

void PlaySoundOff(gamePadType i){
  noTone(SPEAKER);
  }

void TurnLighOn(gamePadType i){
  digitalWrite(i.PinNrLed,HIGH);
   } 

void TurnLighOff(gamePadType i){
   digitalWrite(i.PinNrLed,LOW);
   } 

void BlinkAndBuzz(gamePadType i){
   delay(500);
   tone(SPEAKER, i.Frequency);
   digitalWrite(i.PinNrLed,HIGH);
   delay(500);
   noTone(SPEAKER);
   digitalWrite(i.PinNrLed,LOW);  
  }

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

//Play the whole frequency
/*    for (int i = 0; i < 20000; i++)
  {
    tone(SPEAKER, i);
    delay(25);
  }*/
  noTone(SPEAKER);

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
//When the button is pushed a coresponding light with tune is played.
void testSoundWithLight()
{
  while (0==digitalRead(Yellow.PinNrButton))
{
  PlaySoundOn(Yellow);
  TurnLighOn(Yellow);
  }

while (0==digitalRead(Green.PinNrButton))
{
  PlaySoundOn(Green);
  TurnLighOn(Green);
  }
while (0==digitalRead(Red.PinNrButton))
{
  PlaySoundOn(Red);
  TurnLighOn(Red);
  }
while (0==digitalRead(Blue.PinNrButton))
{
  PlaySoundOn(Blue);
  TurnLighOn(Blue);
  }

  PlaySoundOff(Yellow);
  TurnLighOff(Yellow);
  PlaySoundOff(Green);
  TurnLighOff(Green);
  PlaySoundOff(Red);
  TurnLighOff(Red);
  PlaySoundOff(Blue);
  TurnLighOff(Blue);

  }
  

void loop() {

 // BlinkAndBuzz(GamePad[random(0,4)]);



testSoundWithLight();
/*while (1==digitalRead(Yellow.PinNrButton))
{
  
  }
*/
/* delay(1000);
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
  delay(500);
nrOfLightsOn=4;
  digitalWrite(YELLOW,HIGH);
  digitalWrite(GREEN,HIGH);
  digitalWrite(RED,HIGH);
  digitalWrite(BLUE,HIGH);
  */
  
}
