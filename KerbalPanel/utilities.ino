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
  lcd.print(VData.TAp);
  lcd.setCursor(0,1);
  lcd.print(VData.MissionTime);
  
  ledDisplay(2,VData.RAlt);
//  digitalWrite(RCSLED,ControlStatus(AGRCS));
  ledDisplay(1,VData.Alt);
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

void ReadButtonsAndChangeState(){
  dataReceive = pcf8575_read(); //read the pcf8575 pins
  dataReceive = ~dataReceive;
      switch(dataReceive){
    case 65534:
//     NavballSASMode;    //55  Combined byte for navball target mode and SAS mode
                                    // First four bits indicate AutoPilot mode:
                                    // 0 SAS is off  //1 = Regular Stability Assist //2 = Prograde
                                    // 3 = RetroGrade //4 = Normal //5 = Antinormal //6 = Radial In
                                    // 7 = Radial Out //8 = Target //9 = Anti-Target //10 = Maneuver node
       setSASMode(SMSAS);
      break;
    case 65533:{
      setSASMode(SMPrograde);
       break;}
    case 65531:{
      setSASMode(SMRetroGrade);
      break;}
    case 65527:{
      setSASMode(SMNormal);
       break;}
    case 65519:{
      setSASMode(SMAntinormal);
       break;}
    case 65503:{
      setSASMode(SMRadialIn);
    break;}
    case 65471:{
      setSASMode(SMRadialOut);
    break;}
    case 65407:{
      setSASMode(SMTarget);
     break;}
    case 65279:{
      setSASMode(SMAntiTarget);
    break;}
    case 65023:{
      setSASMode(SMManeuverNode);
        break;}
    case 64511:{
    //  Serial.println("speed");
      break;}
    case 61439:
    {
   // Serial.println("time");
    } break;
    case 63487:{
  //  Serial.println("3d");
 // CPacket.Mode=0
    
    //MainControls(MODE, 0);
    ;
    break;
      } 
      case 57343:
    {
   // MainControls(MODE, 2);
 //      CPacket.Mode=2;
 // Serial.println("map");
      break;
    }case 49151:
    {
  //  Serial.println("dock");
  // CPacket.Mode=1;
  
   // MainControls(MODE, 1);
    break;}
      }

}


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
  Wire.beginTransmission(addres);
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
  Wire.beginTransmission(addres);
  error = Wire.endTransmission();
  if(error == ku8TWISuccess){ //okay!
    Wire.requestFrom(addres,2); 
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
