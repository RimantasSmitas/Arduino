#include <Wire.h> 

//fuzzywobble.com 2012
//this code turns every PCF8575 pin into an input (without interrupt)
//datasheet - http://www.ti.com/general/docs/lit/getliterature.tsp?genericPartNumber=pcf8575&fileType=pdf
//i2c code adapted from i2c_dio_pcf8575c.cpp - Arduino class library for TI PCF8575C 16-bit I2C I/O expander

//address is |0100|A0|A1|A2|
int address = 0x20; //0100000 (7bit)  
uint16_t dataReceive; //16bit data received
uint16_t dataSend;  //16bit data sent

void setup(){ 
  Wire.begin(); 
  Serial.begin(9600);
  //turn pins to input in setup
  //if bit = 0, pin functions as input or an output that is off
  //if bit = 1, pin functions as an output that is on
  dataSend = word(B00000000,B00000000); //turn every pin to input
 pcf8575_write(dataSend); //turn the pcf8575 pins to input
} 

void loop(){ 
  ReadButtonsAndChangeState();
 delay(500);
 // dataReceive = pcf8575_read(); //read the pcf8575 pins
  
 // Serial.print("Read, ");
 // Serial.println(~dataReceive,BIN); //~ inverses the results, this removes the ambiguity of leading zero 
  /*
  Read, 1111111111111101 - p1 pressed
  Read, 1111111111111011 - p2 pressed
  Read, 1111111111110111 - p3 pressed
  */
  //Serial.println("----------------------");
 // delay(300);
} 

void ReadButtonsAndChangeState(){
  dataReceive = pcf8575_read(); //read the pcf8575 pins
  dataReceive = ~dataReceive;
 /* //int counter = 0;
  //uint16_t button = 1;
  //int temp;
  //Serial.print("data");
  Serial.println(dataReceive);
 // int bitcounter = 15;
 // button = dataReceive;
 // for(button;button>1;){
   
  //  temp = button << bitcounter ;
  //  temp = unsigned(temp)>> 15;
  //  Serial.println(temp);
   // Serial.println("TEMP");
    //delay(100);
   // Serial.println(button,BIN);
   // if(temp==0){*/
      switch(dataReceive){
    case 65534:
      Serial.println("sas 0");
      break;
    case 65533:{
      Serial.println("sas 1");
       break;}
    case 65531:{
    Serial.println("sas 2");  
    
      break;}
    case 65527:{
     Serial.println("sas 3");
       break;}
    case 65519:{
     Serial.println("sas 4");
       break;}
    case 65503:{
    Serial.println("sas 5");
    break;}
    case 65471:{
    Serial.println("sas 6");
    break;}
    case 65407:
    {Serial.println("sas 7");
     break;}
    case 65279:{
    Serial.println("sas 8");
    break;}
    case 65023:{
    Serial.println("sas 9");
        break;}
    case 64511:{
      Serial.println("speed");
      break;}
    case 61439:
    {
    Serial.println("time");
    } break;
    case 63487:{
    Serial.println("3d");
    break;
      } 
      case 57343:
    {
    Serial.println("map");
      break;
    }case 49151:
    {
    Serial.println("dock");
    break;}
      }
  //  }
 //   counter++;
 // bitcounter=bitcounter-1 ;
// button = unsigned(button)>> 1;
    
  
  //}

}
//custom functions -----------------------------

//I2C/TWI success (transaction was successful).
static const uint8_t ku8TWISuccess                   = 0;
//I2C/TWI device not present (address sent, NACK received).
static const uint8_t ku8TWIDeviceNACK                = 2;
//I2C/TWI data not received (data sent, NACK received).
static const uint8_t ku8TWIDataNACK                  = 3;
//I2C/TWI other error.
static const uint8_t ku8TWIError                     = 4;

uint8_t error;
void pcf8575_write(uint16_t dt){
  Wire.beginTransmission(address);
  Wire.write(lowByte(dt));
  Wire.write(highByte(dt));
  error = Wire.endTransmission();
  if(error == ku8TWISuccess){ //okay!
  
  }
  else{ //we have an error
    //do something here if you like
  }
}
uint8_t hi,lo;
uint16_t pcf8575_read(){
  Wire.beginTransmission(address);
  error = Wire.endTransmission();
  if(error == ku8TWISuccess){ //okay!
    Wire.requestFrom(address,2); 
    if(Wire.available()){
      lo = Wire.read();
      hi = Wire.read();
      return(word(hi,lo)); //joing bytes 
    }
    else{//error
      //do something here if you like  
    }
  }
  else{ //error
    //do something here if you like  
  }
}





