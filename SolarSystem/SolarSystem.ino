#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <math.h>
#include "DRV8825.h"

#define MOTOR_STEPS 200

#define RPM1 5
#define RPM2 5
#define RPM3 5
#define RPM4 5

#define DIR 4
#define STEP 5
#define DIR1 6
#define STEP1 7
#define DIR2 8
#define STEP2 9
#define DIR3 10
#define STEP3 11

#define Mercury 10
#define Venus 25
#define Earth 41
#define Mars 78
#define Jupiter 492 
#define Saturn 1223
#define Uranus 3488
#define Neptune 6842

#define NrOfPlanets 4 //Change to 8 when building the final model
#define SLEEP 13 // optional (just delete SLEEP from everywhere if not used)

#define MODE0 22
#define MODE1 23
#define MODE2 24
DRV8825 MMercury(MOTOR_STEPS, DIR, STEP,SLEEP, MODE0, MODE1, MODE2);
DRV8825 MVenus(MOTOR_STEPS, DIR1, STEP1,SLEEP, MODE0, MODE1, MODE2);
DRV8825 MEarth(MOTOR_STEPS, DIR2, STEP2,SLEEP, MODE0, MODE1, MODE2);
DRV8825 MMars(MOTOR_STEPS, DIR3, STEP3,SLEEP, MODE0, MODE1, MODE2);

char terminator=('n'); 
enum PlanetStates{Spin,Stop,Date,Calibrate};
PlanetStates state = Stop;

SparkFun_APDS9960 apds = SparkFun_APDS9960();


///Here are all the steps of all planets counted
int Steps[]={0,0,0,0,0,0,0,0};
///default speed //////////////////////////////////////
int Delay=1;
int Speed[]={1,1,1,1,1,1,1,1};
///////////////////////////////////////////////////////

byte ILikeToMoveIt[Neptune];
int Planets[NrOfPlanets]= {Mercury,Venus,Earth,Mars};//,Jupiter,Saturn,Uranus,Neptune};
byte bitt;

int PlanetHolders []= {90,180,70,50};

uint8_t proximity_data = 0;

char RecieveData;
int YearMonthDay;
void encode(){  
    Serial.println("Starting encoding");
    int i = 1;
    for (i; i <= Neptune; i++){
        for(int x = 0; x < NrOfPlanets;x++){
            if(i%Planets[x]==0){
              bitt = 1;  
              bitt<<=x;
              ILikeToMoveIt[i]=ILikeToMoveIt[i]|bitt;}
            else{}
        }  
    }
    Serial.println("Encoding done");
}



// Returns a Julian date number from current day given 
int JD(int y, int m, int d){
    int Y = y;
    int M = m;
    int D = d;

    if (M<3){
        Y = Y-1;
        M = M+12;
    }
    int A = Y/100;
    //Serial.println(A);
    int B = A/4;
    //Serial.println(B);
    int C = 2-A+B;
    //Serial.println(C);
    int E= 365.25*(Y+4716);
    //Serial.println(E);
    int F = 30.6001*(M+1);
    //Serial.println(F);
    int JD = C+D+E+F-1524;
    return(JD);
}
  


//The following functions uses the the julian date and produces keplerian elements for the inner planets 
// it later forwards the elements to a coordinate estimation calculator 
void keplerianSun(int d){
    double N = 0.0;
    double i = 0.0;
    double w = 282.9404 + 4.70935 *0.0001 * d;
    double a = 1.000000;
    double e = 0.016709 - 1.151 *0.00000001 * d;
    double M = 356.0470 + 0.9856002585 * d;

    keplerianCalculator(2,N,i,w,a,e,M);
}


void keplerianMerc(int d){
    double N =  48.3313 + 3.24587 *0.0001 *d;
    double i = 7.0047 + 5.00 *0.0000001 * d;
    double w =  29.1241 + 1.01444*0.0001 * d;
    double a = 0.387098;
    double e = 0.205635 + 5.59*0.000000001 * d;
    double M = 168.6562 + 4.0923344368 * d;
  
    keplerianCalculator(0,N,i,w,a,e,M);
}

void keplerianVen(int d){
    double N =   76.6799 + 2.46590*0.0001 *d;
    double i =  3.3946 + 2.75*0.0000001 * d;
    double w =  54.8910 + 1.38374*0.0001 * d;
    double a = 0.723330;
    double e = 0.006773 - 1.302*0.00000001 * d;
    double M =  48.0052 + 1.6021302244 * d;
  
    keplerianCalculator(1,N,i,w,a,e,M); 
}

void keplerianMars(int d){
    double N =  49.5574 + 2.11081*0.0001 *d;
    double i =  1.8497 - 1.78*0.0000001 * d;
    double w =  286.5016 + 2.92961*0.0001 * d;
    double a = 1.523688;
    double e = 0.093405 + 2.516*0.00000001 * d;
    double M =  18.6021 + 0.5240207766 * d;
  
    keplerianCalculator(3,N,i,w,a,e,M); 
}


void setup() {
    Serial.begin(9600);
    Serial.println("begin"); 
    encode();

/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Motor Init();//////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
    MMercury.begin(RPM1);
    MVenus.begin(RPM2);
    MEarth.begin(RPM3);
    MMars.begin(RPM4);
  
    MMercury.setMicrostep(32);  // Set microstep mode to 1:1
    MVenus.setMicrostep(32);  // Set microstep mode to 1:1
    MEarth.setMicrostep(32);  // Set microstep mode to 1:1
    MMars.setMicrostep(32);  // Set microstep mode to 1:1
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Initialize APDS-9960 (configure I2C and initial values)///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
    if ( apds.init() ) {
        Serial.println(F("APDS-9960 initialization complete"));
    } 
    else {
        Serial.println(F("Something went wrong during APDS-9960 init!"));
    }

////// Adjust the Proximity sensor gain///////////////////////////////////////////////////
    if ( !apds.setProximityGain(PGAIN_1X) ) {
        Serial.println(F("Something went wrong trying to set PGAIN"));
    }
  
///// Start running the APDS-9960 proximity sensor (no interrupts)////////////////////////
    if ( apds.enableProximitySensor(false) ) {
        Serial.println(F("Proximity sensor is now running"));
    } 
    else {
        Serial.println(F("Something went wrong during sensor init!"));
    }
///////////////////////////////////////////////////////////////////////////////////////////
//calibrate();
}


void UpdateProximity(){
    if ( !apds.readProximity(proximity_data) ) {
        Serial.println("Error reading proximity value");
    } 
    else {
        Serial.print("Proximity: ");
        Serial.println(proximity_data);
    } 
}

void ChangeStepCount(int PlanetIndex,int NewSpeed){
    Speed[PlanetIndex]=NewSpeed;
}


void decoder(int index){
    
    byte MercuryByte=1;
    byte VenusByte = 2;
    byte EarthByte = 4;
    byte MarsByte =  8;
    byte JupiterByte=16;
    byte SaturnByte =32;
    byte UranusByte =64;
    byte NeptuneByte=128;
    byte message = ILikeToMoveIt[index];
//////////////////////////////////////////////////////////////////////////////////////    
    if((message&MercuryByte)!=0)MovePlanet(0);
    if((message&VenusByte)!=0)MovePlanet(1);
    if((message&EarthByte)!=0)MovePlanet(2);
    if((message&MarsByte)!=0)MovePlanet(3);
///////Outer planets//////////////////////////////////////////////////////////////////

  //Not used in the proof of concept
    if((message&JupiterByte)!=0){
      MovePlanet(4);}
    if((message&SaturnByte)!=0){
      MovePlanet(5);}
    if((message&UranusByte)!=0){
      MovePlanet(6);}
    if((message&NeptuneByte)!=0){
      MovePlanet(7);}
}

void MoveToStartPosition(int i){
    ChangeStepCount(i,10);
    for (int x = 0; x<100;x++){
        MovePlanet(i);
        delay(10); 
   }
   ChangeStepCount(i,1);
}

void calibrate(){
    Serial.print("Calibration started");
    UpdateProximity();
    for (int i = 0; i<1;i++){    ///change back to NrOfPlanets
        ChangeStepCount(i,10);
    }
    delay(10); 
    UpdateProximity();
    while(proximity_data>20){
        MoveAllPlanets();
        delay(10);
        UpdateProximity();
    }

    for (int i = 0; i<1;i++){     ///change back to NrOfPlanets
        while(proximity_data<PlanetHolders[i]){  
            MovePlanet(i);
            delay(10); 
            UpdateProximity();  
        }
        ChangeStepCount(i,1);
        while(proximity_data>PlanetHolders[i]){   
            MovePlanet(i);
            delay(10); 
            UpdateProximity();  
        }
        Steps[i]=0;   
        ChangeStepCount(i,10);
        while(proximity_data<PlanetHolders[i]){
            MovePlanet(i);
            delay(10); 
            UpdateProximity();  
        }
        ChangeStepCount(i,1);
        while(proximity_data>PlanetHolders[i]){   
            MovePlanet(i);
            delay(10); 
            UpdateProximity();  
            Serial.println(Steps[i]);
        }
        Serial.println("Calibration for planet I is done");
        Serial.print("One rotation is");
        Serial.println(Steps[i]);
        MoveToStartPosition(i);
        if(abs(Steps[i]-15360)>154){
            Serial.println("The calibration function has discovored that there's more than 1% inaccuracy ");
            Serial.println("please check that nothing is blocking the planet movers and everything is thightened as it should be"); 
        }
        Steps[i]= 0;  
    }
}


void MoveAllPlanets(){
    for(int i = 0;i< NrOfPlanets;i++){
        delay(10);
        MoveToStartPosition(i);
    }
}


void MovePlanet(int index){   
  digitalWrite(SLEEP,HIGH);
  //Serial.println("mOVEPlanet");
  //  Serial.println(index);
    
    int i = index;
    switch(i){
        case 0:
            MMercury.move(Speed[i]);
            Steps[i]=Steps[i]+Speed[i];
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
           // Serial.println("Mercury");
          //  digitalWrite(SLEEP,LOW);
        break;
        case 1:
            MVenus.move(Speed[i]);
            Steps[i]=Steps[i]+Speed[i];
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            //  Serial.println("Venus");
           // digitalWrite(SLEEP,LOW);
        break;
        case 2:
            MEarth.move(Speed[i]); 
            Steps[i]=Steps[i]+Speed[i];
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            // Serial.println("Earth");
            //digitalWrite(SLEEP,LOW);
        break;
        case 3:
            MMars.move(Speed[i]);
            Steps[i]=Steps[i]+Speed[i];   
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            // Serial.println("Mars");
            //digitalWrite(SLEEP,LOW);
        break;
        case 4:
            /*
            MJupiter.move(Speed[i]); 
            Steps[i]=Steps[i]+stepcount;
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            digitalWrite(SLEEP,LOW);
            */
        break;
        case 5:
            /*
            MSaturn.move(Speed[i]);
            Steps[i]=Steps[i]+stepcount;
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            digitalWrite(SLEEP,LOW);
            */           
        break;
        case 6:
            /* 
            MUranus.move(Speed[i]);
            Steps[i]=Steps[i]+stepcount;
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            digitalWrite(SLEEP,LOW);
            */
        break;
        case 7:
            /*  
            MNeptune.move(Speed[i]);
            Steps[i]=Steps[i]+stepcount;
            if(Steps[i]>15360)Steps[i]=Steps[i]-15360;
            if(Steps[i]<-15360)Steps[i]=Steps[i]+15360;
            digitalWrite(SLEEP,LOW);
            */
        break;
        default:
            // nada
        break;
    }
}

void MovePlanetToADegree(int index, double ang){
   //Serial.println("move to a degree");
   Serial.print("Current angle ");
    int Stepcount = Steps[index];
    double currentangle = Stepcount * 0.0234375;
      if(currentangle<0){
      currentangle = currentangle +360;
    }
    Serial.println(currentangle);
    double newAngle; 
    double dif;
    ///If the angle is bigger than the current angle
    if (ang > currentangle){
        if (ang - currentangle > 180){
            dif = ang - currentangle;
            newAngle = 360-dif;
            newAngle =newAngle*(-1);
   
        }
        else {newAngle = ang- currentangle; }}
    //if the angle is smaller
    else {if(currentangle-ang>180){
            dif = currentangle-180 -ang;    
            newAngle = 360-currentangle+dif;
         }
          else {newAngle = ang-currentangle;}
         }   
    
            Serial.print("Need to move ");
            Serial.println(newAngle);
    Stepcount =newAngle/0.0234375;
    ChangeStepCount(index,Stepcount);  //Change the step count to whats needed for the planet
    MovePlanet(index);
    ChangeStepCount(index,1);     // Change it back to default 
    

    Serial.print("Steps needed to ");
    Serial.println(Stepcount);
    Serial.print("Current angle ");
    if((Steps[index]*0.0234375)<0){Serial.println((Steps[index]*0.0234375)+360);}
    else{
    Serial.println((Steps[index]*0.0234375));}
    state=Stop;
}


void keplerianCalculator(int index, double N, double i, double w, double a, double e, double M){
    double x,y;
    
    while (M < 0){
        M = M+360;
    }   
    while (M > 360){
        M = M-360;
    }   
    
    double E=M + e*(180/3.14159) * sin(M) * ( 1.0 + e * cos(M) );

    if (e>0.05){
      double difference=1;
      while (1){
          double En = E - ( E - e*(180/3.14159) * sin(E) - M ) / ( 1 - e * cos(E) );
          difference = (En-E);
    if (abs(difference)<0.001)break;
        E = En;
      }
    }

    double xv = a * ( cos(E) - e );
    double yv = a * ( sqrt(1.0 - e*e) * sin(E) );

    double v = atan2( yv, xv );
    double r = sqrt( xv*xv + yv*yv );
    
    

    //If calculating for earth the eaquasions are a bit different so we check for them first
    if(index==2){
    double lonsun= v+w;
    x = (r * cos(lonsun))*-1;
    y = (r * sin(lonsun))*-1;
    //Multiply the coordinates by -1 to get coordinates from the sun instead of the earh   
    }
    
    else {
    x = r * ( cos(N) * cos(v+w) - sin(N) * sin(v+w) * cos(i) );
    y = r * ( sin(N) * cos(v+w) + cos(N) * sin(v+w) * cos(i) );  
    }


    float angle = atan2(y,x);
    angle = angle *180/3.14159;

    if(angle<0){
      angle = angle +360;
    }
    
    Serial.println("index");
    Serial.println(index);
    Serial.print("x ");
    Serial.println(x);
    Serial.print("y ");
    Serial.println(y);
    Serial.print("New angle ");
    Serial.println(angle);

    MovePlanetToADegree(index, angle);
  
}

/*
void SerialEvent(){
   String SDelay;
     if (Serial.available()>0) {
        RecieveData = Serial.read();
        //Serial.println(RecieveData);
        switch(RecieveData){
              case 'G':
              state=Spin;
              Serial.println("Spin");
              SDelay = Serial.readStringUntil(terminator);
              Delay = SDelay.toInt();
              Serial.println(Delay);
              break;
   
              case 'S':
              state=Stop;
              Serial.println("Stop");
              break;
    
              case 'D':
              state=Date;
              Serial.println("d");
              SDate = Serial.readStringUntil(terminator);
              Date = SDate.toInt();
              Serial.println(Date);
              break;

              case 'C':
              state=Calibrate;
              Serial.println("c");
              break;        
        }    
    }
}
*/


void CheckState(){
     String SDelay,SDate;
     if (Serial.available()>0) {
        RecieveData = Serial.read();
        //Serial.println(RecieveData);
        switch(RecieveData){
    
              case 'G':
              state=Spin;
              Serial.println("Spin");
              SDelay = Serial.readStringUntil(terminator);
              Delay = SDelay.toInt();
              Serial.println(Delay);
              break;
   
              case 'S':
              state=Stop;
              Serial.println("Stop");
              break;
    
              case 'D':
              state=Date;
              Serial.println("Date");
              SDate = Serial.readStringUntil(terminator);
              YearMonthDay = SDate.toInt();
              Serial.println(YearMonthDay);
              break;

              case 'C':
              state=Calibrate;
              Serial.println("Calibration");
              break;        
        }    
    }   
}


void CalibrateState(){
    calibrate();
}


void SpinState(){
  
    digitalWrite(SLEEP,HIGH);
    for(int i = 0; i < Neptune+1; i++){    
        byte compare = ILikeToMoveIt[i];   
        if(compare!=0){
           decoder(i);
           delay(Delay/10);
        }
          CheckState();
    }
}
     
     
void DateState(){
  
    digitalWrite(SLEEP,HIGH);
         int Year; 
         int Month;
         int Day;
         Year = YearMonthDay/10000;
         Month = (YearMonthDay - (Year*10000))/100;
         Day = YearMonthDay - (Year*10000) - (Month*100);
         Serial.println(Year);
         Serial.println(Month);
         Serial.println(Day);
         int J =JD(Year,Month,Day);
         keplerianMerc(J); 
         keplerianVen(J);
         keplerianSun(J);
         keplerianMars(J);
         return; 
    
}

void StopState(){
 digitalWrite(SLEEP,LOW);
 return;
    //CheckState();
}

void States(){
    if (state == Date){
      DateState();  
    }
  
    if (state == Spin){
      SpinState();
    }

    if (state == Stop){
      StopState();
    }

    if (state == Calibrate){
    CalibrateState();
    }
}

void loop() {  
 // Serial.println("loop");
     CheckState();
     States();
}
