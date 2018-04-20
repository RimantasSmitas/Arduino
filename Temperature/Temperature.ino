
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue;  // variable to store the value coming from the sensor
#include "LedControlMS.h"
#define NBR_MTX 2

void loop() {
  float convert;
  sensorValue = analogRead(sensorPin);
  convert = float(sensorValue*0.0977); 
  Serial.println(convert);
  delay(1000);
  printMessage(convert);
  }

/*  Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
  We have only a single MAX72XX.
*/
LedControl lc = LedControl(12, 11, 10, NBR_MTX);

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  Serial.begin (9600);
  Serial.println("Setup");

  for (int i = 0; i < NBR_MTX; i++) {
    lc.shutdown(i, false);
    /*  Set the brightness to a medium values */
    lc.setIntensity(i, 8);
    /* and clear the display */
    lc.clearDisplay(i);
  }
}


void printMessage(float temp) {  
  Serial.println(temp);
  String phrase ="C";
  phrase = temp + phrase;
  for(int i=0;i<phrase.length();i++)
     {
     lc.writeString(0, phrase.charAt(i));
     }
  delay(150);
}

/*
  void scrollLeft(char ch) {
  int pos = lc.getCharArrayPosition(ch);
  for (int scroll = 0; scroll < 6; scroll++) {
    for (int i = scroll; i < 6; i++) {
      lc.setRow(0, i - scroll, alphabetBitmap[pos][i]);
    }
    delay(300);
    lc.clearDisplay(0);
  }
  }
  void scrollRight(char ch) {
  int pos = lc.getCharArrayPosition(ch);
  for (int scroll = 0; scroll < 8; scroll++) {
    for (int i = 0; i < 6; i++) {
      if (scroll + i < 8) lc.setRow(0, scroll + i, alphabetBitmap[pos][i]);
    }
    delay(300);
    lc.clearDisplay(0);
  }
  }
*/
