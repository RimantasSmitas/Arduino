////
//Includes are defined first
//  pins are defined 
/// objeces created
/// Global variables 
//#include "FastLED.h"
#include <FastLED.h>
#include "BluetoothSerial.h"
#include "DHT.h"


//Checks to see weather bluetooth is enabled 
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//Checks if fastled library is newest version
#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DHTPIN 4
#define DHTTYPE DHT11

#define sound 22

#define LEDstrip 23
#define NUM_LEDS 10
#define FRAMES_PER_SECOND  120
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
//CRGB leds[NUM_LEDS];

DHT dht(DHTPIN, DHTTYPE);
CRGBArray<NUM_LEDS> leds;
BluetoothSerial SerialBT;

#define FASTLED_SHOW_CORE 0

// -- Task handles for use in the notifications
static TaskHandle_t FastLEDshowTaskHandle = 0;
static TaskHandle_t userTaskHandle = 0;

enum ShoeStates{Music,Temp,UI,Home};
ShoeStates state = Home;

int Brightness = 60;
int x,a;
int newTemp;
int Green = 127;
int Blue = 127;
int Red= 127;
String temp;
char terminator=('n'); 

void setup() {
   delay(3000); // 3 second delay for recovery
  
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  FastLED.addLeds<LED_TYPE, LEDstrip, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(Brightness);
  pinMode(sound,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital sound
  dht.begin();

}

//This fucnction displays a Single color on an LED strip based on the threee color input  
void showColors(int R,int G,int B){
  int i = 0;
  for(i=0;i<=NUM_LEDS;i++){
   leds[i]=CRGB(R,G,B);
    FastLED.show();}
  }

void MusicState(){
  static uint8_t hue;
  boolean soundstate = digitalRead(sound);
  if (soundstate != 1) {
    Serial.println("sound");
    for(int i = 0; i < NUM_LEDS/2; i++) {
    // fade everything out
    leds.fadeToBlackBy(40);
    // let's set an led value
    leds[i] = CHSV(hue++,255,255);

    // now, let's first 20 leds to the top 20 leds, 
    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    FastLED.delay(5);
    }
    }  
}

void TempState(){
  int y;
  y = Read_temp();
  Fade_snake(y);
}

void Fade_snake(int y){
  for(int z = 0; z < 18; z++){
  for(int i = 0; i < NUM_LEDS; i++) { 
    leds[i] = CHSV(y, 255, 255);
    FastLED.show(); 
    fadeall();
    delay(100);
    if(a = SerialBT.read() > 0){state = Home; break;}
  }
    if(x < 255)x=x+15;
    else x=0;
    if(state == Home) break;
  }
}

void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++){ leds[i].nscale8(x);} }
  
int Read_temp(){
  
  float t = dht.readTemperature();
  int temp1 = map(t, 0, 50, 6, 0);
  int color = temp1 * 32;
  return(color);
  }


void UIState(){
  while(state == UI){
    showColors(Red,Green,Blue); 
    delay(50);
    if (SerialBT.available()) {
      delay(10);
      temp = SerialBT.readStringUntil(terminator);
      newTemp = temp.toInt();
      if((newTemp>=0)&(newTemp<=100)){
        Red = newTemp*2.55;  
        Serial.println(Red);}
  
      if((newTemp>=101)&(newTemp<=202)){
        Green = (newTemp-102)*2.55;  
        Serial.println(Green);}
  
      if((newTemp>=203)&(newTemp<=303)){
        Blue = (newTemp-203)*2.55;  
        Serial.println(Blue);}
  
      if((newTemp>=304)&(newTemp<=404)){
        Brightness=newTemp-304;
        Serial.println(Brightness);
        FastLED.setBrightness(Brightness);}
  
      if(newTemp>404){
        state = Home;
        Serial.println("fuck you");}
        
      showColors(Red,Green,Blue); 
    }
  }
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
  

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void HomeState(){
  while(state == Home){

  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
 // FastLEDshowESP32();
    FastLED.show();
  // FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS( 10 ) { nextPattern(); } // change patterns periodically
  CheckState();
  }
}

void States()  
{
  if (state == Music)
  {
  MusicState();  
  }
  
  if (state == Temp)
  {
    TempState();
  }
  
  if (state == UI)
  {
    UIState();    
  }
  if(state == Home)
  {
    HomeState();
   }
    
}

void CheckState(){
if (SerialBT.available()) {
  Serial.println("ble data recieved");
  delay(10);
  char RecieveData = SerialBT.read();
  Serial.println(RecieveData);
  switch(RecieveData){
    
    case 'A':
    state=Music;
    Serial.println("music");
    break;
   
    case 'B':
    state=Temp;
    Serial.println("temp");
    break;
    
    case 'C':
    state=UI;
    Serial.println("ui");
    break;    
    
    case'H':
    state=Home;
    Serial.println("home");
    break;    
    }   
  }   
}

void loop() {
  CheckState();
  States();    
  }

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
