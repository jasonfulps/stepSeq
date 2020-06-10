void rs1(){

  // ROTARY SWITCH ONE

  /******* BEGIN: ROTARY SWITCH TURN******/
  if(millis() - rs1_LastChange > 1) {
    rs1_ClkState = digitalRead(RS1_CLK);
    if (rs1_ClkState != rs1_ClkLastState  && rs1_ClkState == 1){        
      if (digitalRead(RS1_DT) != rs1_ClkState) {           
        rs1_OnUp();        
      } else {        
        rs1_OnDown();
      }        
    }
  
    rs1_ClkLastState = rs1_ClkState;
    rs1_LastChange = millis();
  }    

  /******* BEGIN: ROTARY SWITCH BUTTON ******/  
  int rs1_btnState = digitalRead(RS1_SW);
  
  if (rs1_btnState == LOW) {
    if (millis() - rs1_BtnLastPress > 50) {
      rs1_OnBtnPress();
    }    
    rs1_BtnLastPress = millis();
  }
}

void rs1_OnUp(){  
  stepValueIdx = stepValueIdx == SEQ_LEN_MAX ? 0: stepValueIdx +1;
}

void rs1_OnDown(){  
  stepValueIdx = stepValueIdx == 0 ? SEQ_LEN_MAX : stepValueIdx -1;
}

void rs1_OnBtnPress(){
  Serial.println("Rotary 1 Button pressed!");
}
