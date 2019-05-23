
#include <Arduino.h>

#include <MultiStepper.h>

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM1 1
#define RPM2 5
#define RPM3 5
#define RPM4 5

#define DIR 4
#define STEP 5
#define DIR1 6/*
#define STEP1 7
#define DIR2 8
#define STEP2 9
#define DIR3 10
#define STEP3 11
*//*
#define Mercury 1
#define Venus 2
#define Earth 4
#define Mars 7
#define Jupiter 49 
#define Saturn 122
#define Uranus 348
#define Neptune 684

#define NrOfPlanets 8

boolean ILikeToMoveMercury[Neptune];
boolean ILikeToMoveVenus[Neptune];
boolean ILikeToMoveEarth[Neptune];
boolean ILikeToMoveMars[Neptune];
boolean ILikeToMoveJupiter[Neptune];
boolean ILikeToMoveSaturn[Neptune];
boolean ILikeToMoveUranus[Neptune];
boolean ILikeToMoveNeptune[Neptune];

//int Planets[NrOfPlanets]={Mercury,Venus,Earth,Mars,Jupiter,Saturn,Uranus,Neptune};


*/

#define SLEEP 13 // optional (just delete SLEEP from everywhere if not used)

 #include "DRV8825.h"
 #define MODE0 22
 #define MODE1 23
 #define MODE2 24
 DRV8825 MMercury(MOTOR_STEPS, DIR, STEP,SLEEP, MODE0, MODE1, MODE2);
// DRV8825 MVenus(MOTOR_STEPS, DIR1, STEP1,SLEEP, MODE0, MODE1, MODE2);
// DRV8825 MEarth(MOTOR_STEPS, DIR2, STEP2,SLEEP, MODE0, MODE1, MODE2);
 //DRV8825 MMars(MOTOR_STEPS, DIR3, STEP3,SLEEP, MODE0, MODE1, MODE2);
//MultiStepper steppers;

void setup() {

Serial.begin(9600);
/*
int x = Mercury;
while(x<=Neptune)
      {ILikeToMoveMercury[x]=1;
      x=x+Mercury;}
Serial.println("Mercury");
*//*
int x = Venus;
while(x<=Neptune){
       ILikeToMoveVenus[x]=true;
       x=x+Venus;
       Serial.println("Venus");}

x = Earth;
while(x<=Neptune)
      {
      ILikeToMoveEarth[x]=true;
      x=x+Earth;
Serial.println("Earth");}

x = Mars;
while(x<=Neptune)
      {
      ILikeToMoveMars[x]=true;
      x=x+Mars;
      Serial.println("Mars");}

x = Jupiter;
while(x<=Neptune)
      {ILikeToMoveJupiter[x]=true;
      x=x+Jupiter;
      Serial.println("Jupiter");
       }

x = Saturn;
while(x<=Neptune)
      {ILikeToMoveSaturn[x]=true;
      x=x+Saturn;
      Serial.println("Saturn");}

x = Uranus;
while(x<=Neptune)
      {x=x+Uranus;
       ILikeToMoveUranus[x]=true;
      }

x = Neptune;      
while(x<=Neptune)
      {ILikeToMoveNeptune[x]=true;
        x=x+Neptune;
      }

Serial.println("Neptune");
*/

  
    //int PlanetArray[Neptune][NrOfPlanets];
    //int Planet_Array[Neptune];
  /*  
    for (int i = 10; i = Neptune; i++) {
      for(int x =1; x= NrOfPlanets;x++){
       // int Freq = Planets[x];
        if(i%Planets[x]==0)
        ILikeToMoveIt[i][x]= 1;
        
      }
   


  }
*/

    MMercury.begin(RPM1);
   // MVenus.begin(RPM2);
   // MEarth.begin(RPM3);
   // MMars.begin(RPM4);
    
    
    // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
    // stepper.setEnableActiveState(LOW);
   // stepper.enable();
   // stepper1.enable();
   // stepper2.enable();
   // stepper3.enable();
    
    
    MMercury.setMicrostep(32);  // Set microstep mode to 1:1
   // MVenus.setMicrostep(32);  // Set microstep mode to 1:1
    //MEarth.setMicrostep(32);  // Set microstep mode to 1:1
   // MMars.setMicrostep(32);  // Set microstep mode to 1:1
//    steppers.addStepper(stepper1);

}
void MoveThePlanets(int Planet)
{
  Serial.println(Planet);
  }


void loop() {
/*
  int i = 1;
  for(i;i = Neptune; i++){      
      Serial.print(i);
      if(ILikeToMoveVenus[i]= true){
        MoveThePlanets(2);}
      if(ILikeToMoveEarth[i]= true){
        MoveThePlanets(3);}
      if(ILikeToMoveMars[i]= true){
        MoveThePlanets(4);}
      if(ILikeToMoveJupiter[i]= true){
        MoveThePlanets(5);}
      if(ILikeToMoveSaturn[i]= true){
        MoveThePlanets(6);}
      if(ILikeToMoveUranus[i]= true){
        MoveThePlanets(7);}
        if(ILikeToMoveNeptune[i]= true){
        MoveThePlanets(8);}      
        }
    }
  
*/



/*
  /*  
    stepper.enable();
    delay(500);
    stepper.disable();
    */
    
   // delay(1000);
    
    /*
     * Moving motor in full step mode is simple:
     */
   // Serial.println("1 step");
   // stepper.setMicrostep(1);  // Set microstep mode to 1:1
  //  stepper.setRPM(15);  // Set microstep mode to 1:1

    // One complete revolution is 360°
   // Serial.println("Rotate");
    //stepper.rotate(360);     // forward revolution
    //stepper1.rotate(360);     // forward revolution
   // stepper2.rotate(360);     // forward revolution
    //stepper3.rotate(360);     // forward revolution
   MMercury.move(1);
   ///MVenus.move(1);
    //MEarth.move(1);
//    MVenus.move(1);
 //   MMars.move(1);
    //stepper.move(1);
   
 //   MEarth.move(1);
   // MMercury.move(1);
    
   
  
}
/*    */
    /*stepper.enable();
    delay(500);
    stepper.disable();
      */  
   // stepper.rotate(360);    // reverse revolution
/*
    // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(MOTOR_STEPS);    // forward revolution
    stepper.move(-MOTOR_STEPS);   // reverse revolution
    delay(1000);*/
//////////////////////////////////////////////////////////////////////////////////////////////////
    
  /*  Serial.println("half step");
    stepper.setMicrostep(2);  // Set microstep mode to 1:1

    // One complete revolution is 360°
    Serial.println("Rotate");
    stepper.rotate(360);     // forward revolution
/*
    stepper.enable();
    delay(500);
    stepper.disable();
  */  
   // stepper.rotate(-360);    // reverse revolution

  /*  // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(2*MOTOR_STEPS);    // forward revolution
    stepper.move(-2*MOTOR_STEPS);   // reverse revolution
    delay(1000);
*/
//////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Serial.println("4 micro step");
    stepper.setMicrostep(4);  // Set microstep mode to 1:1
     stepper.setRPM(3);
    
    // One complete revolution is 360°
    Serial.println("Rotate");
    stepper.rotate(360);     // forward revolution
    stepper.rotate(-360);    // reverse revolution

    // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(4*MOTOR_STEPS);    // forward revolution
    stepper.move(-4*MOTOR_STEPS);   // reverse revolution
    delay(1000);
    /*
     * Microstepping mode: 1, 2, 4, 8, 16 or 32 (where supported by driver)
     * Mode 1 is full speed.
     * Mode 32 is 32 microsteps per step.
     * The motor should rotate just as fast (at the set RPM),
     * but movement precision is increased, which may become visually apparent at lower RPMs.
     */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /* delay(100);
    Serial.println("8 microsteps");
    stepper.setMicrostep(8);   // Set microstep mode to 1:8
    stepper.setRPM(3);
    
    stepper.enable();
    delay(100);
    stepper.disable();
    
    // One complete revolution is still 360° regardless of microstepping mode
    // rotate() is easier to use than move() when no need to land on precise microstep position
    Serial.println("Rotate");
    stepper.rotate(360);
    stepper.stop();
    stepper.enable();
    delay(500);
    stepper.disable();
        
    stepper.rotate(-360);
    
    stepper.enable();
    delay(500);
    stepper.disable();
    
    // In 1:8 microstepping mode, one revolution takes 8 times as many microsteps
    Serial.println("Move");
    stepper.move(8 * MOTOR_STEPS);    // forward revolution
    stepper.enable();
    delay(500);
    stepper.disable();
    
    stepper.move(-8 * MOTOR_STEPS);   // reverse revolution
    Serial.println("Move");
    
    delay(1000);
//////////////////////////////////////////////////////////////////////////////////////////////////
    Serial.println("16 micro step");
    stepper.setMicrostep(16);  // Set microstep mode to 1:16
    stepper.setRPM(2);
    // One complete revolution is 360°
    Serial.println("Rotate");
    stepper.rotate(360);     // forward revolution
    stepper.rotate(-360);    // reverse revolution
     
    // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(80 * MOTOR_STEPS);    // forward revolution
    stepper.move(-80 * MOTOR_STEPS);   // reverse revolution
    delay(1000);

//////////////////////////////////////////////////////////////////////////////////////////////////
    Serial.println("32 micro step");
    stepper.setMicrostep(32);  // Set microstep mode to 1:1
    stepper.setRPM(2);
    // One complete revolution is 360°
    Serial.println("Rotate");
    stepper.rotate(360);     // forward revolution
    stepper.rotate(-360);    // reverse revolution

    // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(32 * MOTOR_STEPS);    // forward revolution
    stepper.move(-32 * MOTOR_STEPS);   // reverse revolution
    delay(1000);

//////////////////////////////////////////////////////////////////////////////////////////////////
    Serial.println("64 micro step");
    stepper.setMicrostep(64);  // Set microstep mode to 1:1

    // One complete revolution is 360°
    Serial.println("Rotate");
    stepper.rotate(360);     // forward revolution
    stepper.rotate(-360);    // reverse revolution

    // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(64 * MOTOR_STEPS);    // forward revolution
    stepper.move(-64 * MOTOR_STEPS);   // reverse revolution
    delay(1000);

//////////////////////////////////////////////////////////////////////////////////////////////////
   Serial.println("128 micro step");
    stepper.setMicrostep(128);  // Set microstep mode to 1:1

    // One complete revolution is 360°
    Serial.println("Rotate");
    stepper.rotate(360);     // forward revolution
    stepper.rotate(-360);    // reverse revolution

    // One complete revolution is also MOTOR_STEPS steps in full step mode
    Serial.println("Move");
    stepper.move(128 * MOTOR_STEPS);    // forward revolution
    stepper.move(-128 * MOTOR_STEPS);   // reverse revolution
    delay(1000);

//////////////////////////////////////////////////////////////////////////////////////////////////
   
 
 
    
    
}
*/
