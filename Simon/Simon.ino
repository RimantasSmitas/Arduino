/*
//#define YELLOW 0
//#define GREEN 1
//#define RED 2
//#define BLUE 3
//int nrOfLightsOn = 0;
//#define BUTTON1 13
//#define BUTTON2 12
//#define BUTTON3 11
//#define BUTTON4 10
*/

#define SPEAKER 9
int level;

struct gamePadType {
  int PinNrLed;
  int Frequency;
  int PinNrButton;
};
/*
//Notes and their frequencies 
//261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//mid C  C#   D    D#   E    F    F#   G    G#   A
//gamePadType Color = {PinNrLed, Frequency, PinNrButton};
*/
gamePadType Yellow = {0, 440, 10};
gamePadType Green = {1, 392, 11};
gamePadType Red = {2, 349, 12};
gamePadType Blue = {3, 330 , 13};

gamePadType GamePad[] = {Yellow, Green, Red, Blue};//All colours in array 

int numberOfColours=4;//Number of items in array 
int memoryArray[250];

void setup() {
  for(int i=0;i<numberOfColours;i++){//loops through the array of GamePad
  pinMode(GamePad[i].PinNrLed, OUTPUT);//Led Pin To OutPut 
  pinMode(GamePad[i].PinNrButton, INPUT_PULLUP); // button is connected to ground
  }
  level = 0;
  Testfunction();
}

void PlaySoundOn(gamePadType i) {
  tone(SPEAKER, i.Frequency);
}

void PlaySoundOff(gamePadType i) {
  noTone(SPEAKER);
}

void TurnLighOn(gamePadType i) {
  digitalWrite(i.PinNrLed, HIGH);
}

void TurnLighOff(gamePadType i) {
  digitalWrite(i.PinNrLed, LOW);
}

void BlinkAndBuzz(gamePadType i) {
  delay(500);
  tone(SPEAKER, i.Frequency);
  digitalWrite(i.PinNrLed, HIGH);
  delay(500);
  noTone(SPEAKER);
  digitalWrite(i.PinNrLed, LOW);
}

void AllOn() {
  for(int i=0;i<numberOfColours;i++){//loops through the array of GamePad
  digitalWrite(GamePad[i].PinNrLed, HIGH);//Led Pin To OutPut 
  }
}
void AllOff() {
  for(int i=0;i<numberOfColours;i++){//loops through the array of GamePad
  digitalWrite(GamePad[i].PinNrLed, LOW);//Led Pin To OutPut 
  }
  noTone(SPEAKER);
}
void PlayMemory(){
  for(int i=0;i<level+1;i++){
  BlinkAndBuzz(GamePad[i]);
  }
}
//to be developed
void WaitForInput(){
  for(int i=0;i<level+1;i++){  
  }
  }

void loop() {
   testSoundWithLight();
  //testLightWithSoundSimultanious();
  /* int newrandom = random(0,numberOfColours);
   memoryArray[level] = newrandom;
   PlayMemory(); 
   WaitForInput(); 
  */
 /*   if (0 == digitalRead(BUTTON1))
    {
      digitalWrite(BLUE,LOW);
      nrOfLightsOn--;
    }else{}
     if (0 == digitalRead(BUTTON2))
    {
      digitalWrite(RED,LOW);
      nrOfLightsOn--;
    }else{}
    if (0 == digitalRead(BUTTON3))zzZzz                                                                                              
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
