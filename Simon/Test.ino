void Testfunction() {
  delay(500);
  BlinkAll();
  BlinkAllSeries();
  BlinkAndBuzzAllSeries();
  
 // testSoundWithLight();
  delay(500);
}

void blink(gamePadType i) {
  digitalWrite(i.PinNrLed, HIGH);
  delay(500);
  digitalWrite(i.PinNrLed, LOW);
  delay(500);
}

void BlinkAll() {
  delay(500);
  AllOn();
  delay(500);
  AllOff();
  delay(500);
  AllOn();
  delay(500);
  AllOff();
  delay(500);
}

void BlinkAllSeries() {
  for(int i=0;i<numberOfColours;i++)
  blink(GamePad[i]);
  delay(500);
  /*
  blink(Yellow);
  delay(500);
  blink(Green);
  delay(500);
  blink(Red);
  delay(500);
  blink(Blue);
*/
}

void BlinkAndBuzzAllSeries() {
  for(int i=0;i<numberOfColours;i++)
  BlinkAndBuzz(GamePad[i]);
  delay(500);
}

//  Plays the whole frequency range
void TestSpeaker(){
      for (int i = 0; i < 5500; i++)
    {
      tone(SPEAKER, i);
      delay(20);
    }
  noTone(SPEAKER);
}

//When the button is pushed a coresponding light with tune is played.
void testSoundWithLight()
{
   while (0 == digitalRead(Yellow.PinNrButton))
  {
    PlaySoundOn(Yellow);
    TurnLighOn(Yellow);
  }

  while (0 == digitalRead(Green.PinNrButton))
  {
    PlaySoundOn(Green);
    TurnLighOn(Green);
  }
  while (0 == digitalRead(Red.PinNrButton))
  {
    PlaySoundOn(Red);
    TurnLighOn(Red);
  }
  while (0 == digitalRead(Blue.PinNrButton))
  {
    PlaySoundOn(Blue);
    TurnLighOn(Blue);
  }
  AllOff();


}
void testLightWithSoundSimultanious(){
    int y,g,r,b;
  if (1 == digitalRead(Yellow.PinNrButton))
  {
   y = 0; 
   delay(25);
     }
  if (0 == digitalRead(Yellow.PinNrButton))
  {
   y = 1; 
   delay(25);
     }
   if (1 == digitalRead(Green.PinNrButton))
  {
   g = 0; 
   delay(25);
     }
  if (0 == digitalRead(Green.PinNrButton))
  {
   g = 1; 
   delay(25);
     }
   if (1 == digitalRead(Red.PinNrButton))
  {
   r = 0; 
   delay(25);
  }
  if (0 == digitalRead(Red.PinNrButton))
  {
   r = 1; 
   delay(25);
  }
  if (1 == digitalRead(Blue.PinNrButton))
  {
   b = 0; 
   delay(25);
  }
  if (0 == digitalRead(Blue.PinNrButton))
  {
   b = 1; 
    delay(25);
  }

  if (0 == digitalRead(Green.PinNrButton))
  {
    PlaySoundOn(Green);
    TurnLighOn(Green);
  }
  else{
    PlaySoundOff(Green);
    TurnLighOff(Green);
  }

  if (0 == digitalRead(Red.PinNrButton))
  {
    PlaySoundOn(Red);
    TurnLighOn(Red);
  }
  
  else{
    PlaySoundOff(Red);
    TurnLighOff(Red);
  }
  if (0 == digitalRead(Blue.PinNrButton))
  {
    PlaySoundOn(Blue);
    TurnLighOn(Blue);
  }
  
  else{
    PlaySoundOff(Blue);
    TurnLighOff(Blue);
  }

if(y==1){
  PlaySoundOn(Yellow);
  TurnLighOn(Yellow);
  }
 if(y==0){
    PlaySoundOff(Yellow);
    TurnLighOff(Yellow);
  }
if(g==1){
  PlaySoundOn(Green);
  TurnLighOn(Green);
  }
 if(g==0){
    PlaySoundOff(Green);
    TurnLighOff(Green);
  }
if(r==1){
  PlaySoundOn(Red);
  TurnLighOn(Red);
  }
 if(r==0){
    PlaySoundOff(Red);
    TurnLighOff(Red);
  }
  if(b==1){
  PlaySoundOn(Blue);
  TurnLighOn(Blue);
  }
 if(b==0){
    PlaySoundOff(Blue);
    TurnLighOff(Blue);
  }
}
