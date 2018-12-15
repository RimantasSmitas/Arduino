
void output() {
  now = millis();
  controlTime = now - controlTimeOld;
  if (controlTime > CONTROLREFRESH) {
    controlTimeOld = now;
    controls();
  }
}

void controls() {
  if (Connected) {
    if (digitalRead(SASPIN)) { 
      MainControls(SAS, HIGH);
  ReadButtonsAndChangeState();   
    }
    else {
     MainControls(SAS, LOW);
    }

    if (digitalRead(RCSPIN)){
      MainControls(RCS, HIGH);}
    else{
      MainControls(RCS, LOW);
    }

    if (digitalRead(GEARPIN)){
      MainControls(GEAR, HIGH);}
    else{
      MainControls(GEAR, LOW);
    }
    
    if (digitalRead(LIGHTPIN)){
      MainControls(LIGHTS, HIGH);}
    else{
      MainControls(LIGHTS, LOW);
    }
    
    if (digitalRead(BRAKESPIN)){
      MainControls(BRAKES, HIGH);}
    else{
      MainControls(BRAKES, LOW);
    }
    
    CPacket.Throttle = constrain(map(analogRead(THROTTLEPIN),0,1024,-1000,1000),-1000, 1000);

    KSPBoardSendData(details(CPacket));
  }
}

void controlsInit() {
  pinMode(SASPIN, INPUT_PULLUP);
  pinMode(RCSPIN, INPUT_PULLUP);
  pinMode(SASPIN, INPUT_PULLUP);
  pinMode(GEARPIN, INPUT_PULLUP);
  pinMode(LIGHTPIN, INPUT_PULLUP);
  pinMode(BRAKESPIN, INPUT_PULLUP);
  pinMode(SCREENPIN1, INPUT_PULLUP);
  pinMode(SCREENPIN2, INPUT_PULLUP);
  pinMode(MAPPIN, INPUT_PULLUP);
  pinMode(STAGEVIEWPIN, INPUT_PULLUP);
  pinMode(DOCKPIN, INPUT_PULLUP);

  
//  pinMode(CG1PIN, INPUT_PULLUP);

}

byte getSASMode() {
  return VData.NavballSASMode & B00001111; // leaves alone the lower 4 bits of; all higher bits set to 0.
}

byte getNavballMode() {
  return VData.NavballSASMode >> 4; // leaves alone the higher 4 bits of; all lower bits set to 0.
}

void setSASMode(byte m) {
  CPacket.NavballSASMode &= B11110000;
  CPacket.NavballSASMode += m;
}

void setNavballMode(byte m) {
  CPacket.NavballSASMode &= B00001111;
  CPacket.NavballSASMode += m << 4;
}

void MainControls(byte n, boolean s) {
  if (s)
    CPacket.MainControls |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.MainControls &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}

void ControlGroups(byte n, boolean s) {
  if (s)
    CPacket.ControlGroup |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.ControlGroup &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}
