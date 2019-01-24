#include <LedControl.h>

// inputs: DIN pin, CLK pin, LOAD pin. number of chips
LedControl mydisplay = LedControl(12, 13, 10, 1);

void setup() {
  Serial.begin(9600);
  mydisplay.shutdown(0, false);  // turns on display
  mydisplay.setIntensity(0, 15); // 15 = brightest
  mydisplay.setDigit(0, 0, 0, false);
  mydisplay.setDigit(0, 1, 0, false);
  mydisplay.setDigit(0, 2, 0, false);
  mydisplay.setDigit(0, 3, 0, false);
  mydisplay.setDigit(0, 4, 0, false);
  mydisplay.setDigit(0, 5, 0, false);
  mydisplay.setDigit(0, 6, 0, false);
  mydisplay.setDigit(0, 7, 0, false);
  delay(5000);
}


void printNumber(float fuel ) {
   
   Serial.print("in ");
   Serial.println(fuel);
    int onetenth;
    int oneth;
    int ones;
    int tens;
    int hundreds;
    int thousands;
    int tenthtousands;
    int hundreththousands;
    int digit;
    
    int i = 0;
    int f = int(fuel);
    Serial.println(fuel);
    while (f > 10){
    digit = f%10;
    mydisplay.setDigit(0, i,digit, false);
    Serial.print("digit ");
    Serial.println(digit);
   
    
    i++;
    f = f / 10;
    Serial.print("remainder");
    Serial.println(f);
  }
  mydisplay.setDigit(0, (i),f, false);
  Serial.print("digit ");
  Serial.println(f);
    /*
    onetenth=f%10;
    f=f/10;
    oneth=f%10;
    f=f/10;
    ones=f%10;
    f=f/10;
    tens=f%10;
    f=f/10;
    hundreds=f%10;     
    f=f/10;
    thousands=f%10;     
    f=f/10;
    tenthtousands=f%10;     
    f=f/10;
    hundreththousands=f%10;     
    
   
    //Now print the number digit by digit
  mydisplay.setDigit(0, 7,hundreththousands, false);
  mydisplay.setDigit(0, 6,tenthtousands, false);
  mydisplay.setDigit(0, 5,thousands, false);
  mydisplay.setDigit(0, 4,hundreds, false);
  mydisplay.setDigit(0, 3,tens, false);
  mydisplay.setDigit(0, 2,ones, true);
  mydisplay.setDigit(0, 1,oneth, false);
  mydisplay.setDigit(0, 0,onetenth, false);*/
}


void loop() {
float x = 0;
while(1){
  printNumber(x); 
  x=x+1;
  delay(200);
  }
}
