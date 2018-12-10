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
*/

//If one wants to add more colours he/she should add a line here with the following format 
//gamePadType Color = {PinNrLed, Frequency, PinNrButton};
//Once that is done you should add  the new pad to the array and incriment the number of colors counter
gamePadType Yellow = {0, 440, 10};
gamePadType Green = {1, 392, 11};
gamePadType Red = {2, 349, 12};
gamePadType Blue = {3, 330 , 13};

gamePadType GamePad[] = {Yellow, Green, Red, Blue};//All colours in array 

int numberOfColours=4;//Number of items in array 
int memoryArray[250];

void setup() {
  Serial.begin(9600);
  for(int i=0;i<numberOfColours;i++){//loops through the array of GamePad
  pinMode(GamePad[i].PinNrLed, OUTPUT);//Led Pin To OutPut 
  pinMode(GamePad[i].PinNrButton, INPUT_PULLUP); // button is connected to ground
  }
  level = 0;
  Testfunction();
}
//plays a specific sound 
void PlaySoundOn(gamePadType i) {
  tone(SPEAKER, i.Frequency);
}

//silences the speaker
void PlaySoundOff() {
  noTone(SPEAKER);
}

//turns on the specific pad led
void TurnLighOn(gamePadType i) {
  digitalWrite(i.PinNrLed, HIGH);
}
//turns off the specific pad led
void TurnLighOff(gamePadType i) {
  digitalWrite(i.PinNrLed, LOW);
}

//blinks and buzzez specific pad 
void BlinkAndBuzz(gamePadType i) {
  delay(500);
  tone(SPEAKER, i.Frequency);
  digitalWrite(i.PinNrLed, HIGH);
  delay(500);
  noTone(SPEAKER);
  digitalWrite(i.PinNrLed, LOW);
}

//turns on all leds 
void AllOn() {
  for(int i=0;i<numberOfColours;i++){//loops through the array of GamePad
    digitalWrite(GamePad[i].PinNrLed, HIGH);//Led Pin To OutPut 
  }
}

//turns off all leds 
void AllOff() {
  for(int i=0;i<numberOfColours;i++){//loops through the array of GamePad
     digitalWrite(GamePad[i].PinNrLed, LOW);//Led Pin To OutPut 
  }
  noTone(SPEAKER);
}

// plays  all the pads that are placed in to memory
void PlayMemory(){
  for(int i=0;i<level+1;i++){
    BlinkAndBuzz(GamePad[memoryArray[i]]);
    Serial.println(memoryArray[i]);
  }
}


//This function loops through the array of levels and the set pads
//Then waits for input for each level 
//if the input is incorrect it starts over the program. 

void WaitForInput(){
    int input;
    for(int x=0;x<level+1;){ 
      input=numberOfColours; 
      int comp = memoryArray[x];
      while(input == numberOfColours){
        for(int i=0; i<numberOfColours; i++){
          if(digitalRead(GamePad[i].PinNrButton)==0){
            while(digitalRead(GamePad[i].PinNrButton)==0){
              PlaySoundOn(GamePad[i]);
              TurnLighOn(GamePad[i]);
              input = i;}
            PlaySoundOff();
            TurnLighOff(GamePad[i]);            
            if(comp==input)
              {
              x++;             
              }
            else{
               YouLost();
               level = 0;
               return;              
              }  
          }
      }
     }
   }
    level++; 
    return;
}

void loop() { 
 // testSoundWithLight();
 // testLightSimultanious();
   int newrandom = random(0,numberOfColours);
   memoryArray[level] = newrandom;
   PlayMemory(); 
   WaitForInput(); 
}

//You lost funtion blinks all leds with a specific tone then clears the memory array.
void YouLost(){
  for (int i = 0; i<3;i++){
    delay(500);
    tone(SPEAKER, 261);
    AllOn();
    delay(500);
    noTone(SPEAKER);
    AllOff();
  }
  for(int i = 0; i<level;i++){
    memoryArray[i]=5;
  }
  }


