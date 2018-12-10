// test function to test all features 
void Testfunction() {
   delay(500);
   BlinkAll();
   BlinkAllSeries();
   BlinkAndBuzzAllSeries();
 //testSoundWithLight();
   delay(500);
}
//blinks a specific pad
void blink(gamePadType i) {
   digitalWrite(i.PinNrLed, HIGH);
   delay(500);
   digitalWrite(i.PinNrLed, LOW);
   delay(500);
}
// blinks all leds
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
//blinks all pads one by one 
void BlinkAllSeries() {
   for(int i=0;i<numberOfColours;i++)
   blink(GamePad[i]);
   delay(500);
 }
//blinks and buzzes all pads one by one 
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
//Only works one at a time 
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



//When this function is active it checks for inputs and lights up the coresponding led
// buttons with lights can be tested simultaniously 
void testLightSimultanious(){
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
    TurnLighOn(Green);
  }
  else{
    TurnLighOff(Green);
  }

  if (0 == digitalRead(Red.PinNrButton))
  {
    TurnLighOn(Red);
  }
  
  else{
    TurnLighOff(Red);
  }
  if (0 == digitalRead(Blue.PinNrButton))
  {
    TurnLighOn(Blue);
  }
  
  else{
    TurnLighOff(Blue);
  }

  if(y==1){
    TurnLighOn(Yellow);
  }
  if(y==0){
    TurnLighOff(Yellow);
  }
  if(g==1){
    TurnLighOn(Green);
  }
  if(g==0){
    TurnLighOff(Green);
  }
  if(r==1){
    TurnLighOn(Red);
  }
  if(r==0){
    TurnLighOff(Red);
  }
  if(b==1){
    TurnLighOn(Blue);
  }
 if(b==0){
    TurnLighOff(Blue);
  }
}


