/****************************************************************
ProximityTest.ino
APDS-9960 RGB and Gesture Sensor
Shawn Hymel @ SparkFun Electronics
October 28, 2014
https://github.com/sparkfun/APDS-9960_RGB_and_Gesture_Sensor

Tests the proximity sensing abilities of the APDS-9960.
Configures the APDS-9960 over I2C and polls for the distance to
the object nearest the sensor.

Hardware Connections:

IMPORTANT: The APDS-9960 can only accept 3.3V!
 
 Arduino Pin  APDS-9960 Board  Function
 
 3.3V         VCC              Power
 GND          GND              Ground
 A4           SDA              I2C Data
 A5           SCL              I2C Clock

Resources:
Include Wire.h and SparkFun_APDS-9960.h

Development environment specifics:
Written in Arduino 1.0.5
Tested with SparkFun Arduino Pro Mini 3.3V

This code is beerware; if you see me (or any other SparkFun 
employee) at the local, and you've found our code helpful, please
buy us a round!

Distributed as-is; no warranty is given.
****************************************************************/

#include <Wire.h>
#include <SparkFun_APDS9960.h>

#define MOTOR_STEPS 200
#define RPM1 5

#define DIR 4
#define STEP 5


#define SLEEP 13 // optional (just delete SLEEP from everywhere if not used)

 #include "DRV8825.h"
 #define MODE0 22
 #define MODE1 23
 #define MODE2 24
 DRV8825 MMercury(MOTOR_STEPS, DIR, STEP,SLEEP, MODE0, MODE1, MODE2);
int MercurySteps;

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximity_data = 0;

void setup() {
      MMercury.begin(RPM1);
        MMercury.setMicrostep(32);  // Set microstep mode to 1:1
  
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println(F("------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - ProximitySensor"));
  Serial.println(F("------------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_1X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }
 // 
}


void UpdateProximity(){
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);} 
  }
  
void calibrate(){
  MercurySteps= 0;
  Serial.print("Calibration started");
  UpdateProximity();
  Serial.print("Calibration started");
  
  while(proximity_data!=255)
   {
    MMercury.move(10);
   delay(10); 
    Serial.print("moving to position");
    Serial.println(proximity_data);
    UpdateProximity();  
   }
   while(proximity_data==255)
   {MMercury.move(1);
   delay(25);
   Serial.println("moving to position2");
   UpdateProximity();  }
   
     while(proximity_data!=255)
   { MMercury.move(10);
   delay(50);
   MercurySteps=MercurySteps+10;
   Serial.print("starting counting");
    Serial.println(proximity_data);
 
    Serial.print("steps made");
    Serial.println(MercurySteps);
    UpdateProximity();  
    
    
   }
     while(proximity_data==255)
   { MMercury.move(1);
   delay(10);
   MercurySteps++;
   UpdateProximity();  
  
    Serial.print("steps made");
    Serial.println(MercurySteps++);
   }

  Serial.print("Calibration done");
  Serial.println( MercurySteps);
  

    
}
void loop() {


  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
  }
  calibrate();
  
  // Wait 250 ms before next reading
  delay(250);
}
