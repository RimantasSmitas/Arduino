#include "BluetoothSerial.h"
#include <FastLED.h>


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
int newTemp;
int Green = 50;
int Blue = 50;
int Red = 50;
//int PA1,PA2,PA3;
String temp;
char terminator=('n'); 

#define NUM_LEDS 61
#define DATA_PIN 23

CRGB leds[NUM_LEDS];
  
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void showColors(int R,int G,int B){
  int i = 0;
  for(i=0;i<=NUM_LEDS;i++){
   leds[i]=CRGB(R,G,B);
    FastLED.show();}
  }

void loop() {
   delay(50);
  //if (SerialBT.available()) {
  delay(10);
  temp = SerialBT.readStringUntil(terminator);
  newTemp = temp.toInt();
  if((newTemp>=0)&(newTemp<=100)){
  Red = newTemp;  
  Serial.println(Red);}
  if((newTemp>=101)&(newTemp<=202)){
  Green = newTemp-100;  
  Serial.println(Green);
  }
  if(newTemp>202){
  Blue = newTemp-200;  
  Serial.println(Blue);
   }
 showColors(Red,Green,Blue);
   
 }
 //}
