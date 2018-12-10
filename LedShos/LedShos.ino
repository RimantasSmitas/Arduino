////
//Includes are defined first
//  pins are defined 
/// objeces created
/// Global variables 

#include <FastLED.h>
#include "BluetoothSerial.h"
//Checks to see weather bluetooth is enabled 
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define LEDstrip 23
#define NUM_LEDS 49
#define sound 22
CRGBArray<NUM_LEDS> leds;
BluetoothSerial SerialBT;

enum ShoeStates{Music,Temp,UI,Home};
ShoeStates state = Home;

int newTemp;
int Green;
int Blue;
int Red;
String temp;
char terminator=('n'); 

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  FastLED.addLeds<WS2811, LEDstrip, GRB>(leds, NUM_LEDS);
  pinMode(sound,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
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
    }else{
}  
}

void TempState(){
  //read temperature 
  // map temperature to color spectrum 
  // show color
}

void UIState(){
  while(state == UI){
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
  Serial.println(Green);
  }
  if((newTemp>=203)&(newTemp<=303)){
  Blue = (newTemp-203)*2.55;  
  Serial.println(Blue);
   }
  if(newTemp>303){
  state = Home;
  Serial.println("fuck you");
  }
  showColors(Red,Green,Blue); 
  }
}
}
void HomeState(){
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
  {HomeState();
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
