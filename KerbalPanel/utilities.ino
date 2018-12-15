void Indicators() {
  caution = 0;
  warning = 0;

  caution += VData.G > GCAUTION;
  warning += VData.G > GWARN;
  caution += VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELCAUTION;
  warning += VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELWARN;

  if (caution != 0)
    digitalWrite(YLED,HIGH);
  else
    digitalWrite(YLED,LOW);

  if (warning != 0)
    digitalWrite(RLED,HIGH);
  else
    digitalWrite(RLED,LOW);
    
  digitalWrite(SASLED,ControlStatus(AGSAS));
  //ledDisplay(1,VData.Alt);
  lcd.clear();//Clean the screen
  lcd.setCursor(0,0); 
  lcd.print(VData.LiquidFuelTot);
  lcd.setCursor(0,1);
  lcd.print(VData.LiquidFuel);

  
  ledDisplay(1,VData.RAlt);
//  digitalWrite(RCSLED,ControlStatus(AGRCS));
  ledDisplay(0,VData.Alt);
  //digitalWrite(CG1LED,ControlStatus(AGCustom01));
  displayAllServos();
}





void displayAllServos(){
//Fuel servo 
uint16_t pwm;
pwm = ServoMapper(0,VData.LiquidFuelTot,VData.LiquidFuel);
ServoMover(3,pwm);
//Oxidizer
pwm=ServoMapper(0,VData.OxidizerTot,VData.Oxidizer);
ServoMover(4,pwm);
//Solids
pwm=ServoMapper(0,VData.SolidFuelTot,VData.SolidFuel);
ServoMover(5,pwm);
//monoprop
pwm=ServoMapper(0,VData.MonoPropTot,VData.MonoProp);
ServoMover(6,pwm);
    
}

void ServoMover(int Servonumber,uint16_t position){
     pwm.setPWM(Servonumber, 0, position);
 
  }


//returns position the pwm signal required for the servo based on the minimal total and curent calue
int ServoMapper(int min, int max, int curr)
{
  int pwm=map(curr,min,max,SERVOMAX,SERVOMIN);
  return pwm;
  }
void initLEDS() {
  pinMode(GLED,OUTPUT);
  digitalWrite(GLED,HIGH);

  pinMode(YLED,OUTPUT);
  digitalWrite(YLED,HIGH);

  pinMode(RLED,OUTPUT);
  digitalWrite(RLED,HIGH);
  
  pinMode(SASLED,OUTPUT);
  digitalWrite(SASLED,HIGH);
  
//  pinMode(RCSLED,OUTPUT);
//  digitalWrite(RCSLED,HIGH);
  
 // pinMode(CG1LED,OUTPUT);
 // digitalWrite(CG1LED,HIGH);
}

void ledDisplay(int disp, float fuel){
    int onetenth;
    int oneth;
    int ones;
    int tens;
    int hundreds;
    int thousands;
    int tenthtousands;
    int hundreththousands;
    
  long int f = fuel * 100;
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
  mydisplay.setDigit(disp, 7,hundreththousands, false);
  mydisplay.setDigit(disp, 6,tenthtousands, false);
  mydisplay.setDigit(disp, 5,thousands, false);
  mydisplay.setDigit(disp, 4,hundreds, false);
  mydisplay.setDigit(disp, 3,tens, false);
  mydisplay.setDigit(disp, 2,ones, true);
  mydisplay.setDigit(disp, 1,oneth, false);
  mydisplay.setDigit(disp, 0,onetenth, false);
}

void LEDSAllOff() {
  digitalWrite(GLED,LOW);
  digitalWrite(YLED,LOW);
  digitalWrite(RLED,LOW);
  digitalWrite(SASLED,LOW);
//  digitalWrite(RCSLED,LOW);
//  digitalWrite(CG1LED,LOW);
}


void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 101;
}
