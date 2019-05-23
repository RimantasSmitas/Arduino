#include <stdio.h>
#include <math.h>

void setup(){
  Serial.begin(9600);
  }
  

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


void keplerianMerc(int d){
double N =  48.3313 + 3.24587 *0.0001 *d;
double i = 7.0047 + 5.00*0.0000001 * d;
double w =  29.1241 + 1.01444*0.0001 * d;
double a = 0.387098  ;
double e = 0.205635 + 5.59*0.000000001 * d;
double M = 168.6562 + 4.0923344368 * d;
  
keplerianCalculator(N,i,w,a,e,M); 
}

void keplerianVen(int d){
double N =   76.6799 + 2.46590*0.0001 *d;
double i =  3.3946 + 2.75*0.0000001 * d;
double w =  54.8910 + 1.38374*0.0001 * d;
double a = 0.723330;
double e = 0.006773 - 1.302*0.00000001 * d;
double M =  48.0052 + 1.6021302244 * d;
  
keplerianCalculator(N,i,w,a,e,M); 
}

void keplerianMars(int d){
double N =  49.5574 + 2.11081*0.0001 *d;
double i =  1.8497 - 1.78*0.0000001 * d;
double w =  286.5016 + 2.92961*0.0001 * d;
double a = 1.523688;
double e = 0.093405 + 2.516*0.00000001 * d;
double M =  18.6021 + 0.5240207766 * d;
  
keplerianCalculator(N,i,w,a,e,M); 
}



void keplerianCalculator(double N, double i, double w, double a, double e, double M){
while (M < 0){
    M= M +360;
}   
while (M > 360){
    M= M -360;
}   

    
double E=M + e*(180/3.14159) * sin(M) * ( 1.0 + e * cos(M) );

if (e>0.05){
double difference=1;
while (1){
    double En = E - ( E - e*(180/3.14159) * sin(E) - M ) / ( 1 - e * cos(E) );

    difference = (En-E);
    if (abs(difference)<0.001)break;
    E= En;
   
   //Serial.println("BLA"); 
}}
double xv =a * ( cos(E) - e );
double yv =a * ( sqrt(1.0 - e*e) * sin(E) );

double v = atan2( yv, xv );
double r = sqrt( xv*xv + yv*yv );

    
double xh = r * ( cos(N) * cos(v+w) - sin(N) * sin(v+w) * cos(i) );
double yh = r * ( sin(N) * cos(v+w) + cos(N) * sin(v+w) * cos(i) );  


float angle = atan2(0-yh,0-xh);
angle = angle *180/3.14159;

Serial.println("xh");
Serial.println(xh);
Serial.println("yh");
Serial.println(yh);
Serial.println("angle");
Serial.println(angle);


}



void loop()
{
   Serial.println("Hello World");
   int b =JD(2005,1,1);
   Serial.println(b);
   Serial.println("2005");
   keplerianMerc(b); 
   b =JD(2001,1,1);
   Serial.println(b);
   Serial.println("2001");
   keplerianMerc(b);
   b =JD(2010,1,1);
   Serial.println(b);
   Serial.println("2010");
   keplerianMerc(b);
   b =JD(1990,1,1);
   Serial.println(b);
   Serial.println("1990");
   keplerianMerc(b);
     
 
}
