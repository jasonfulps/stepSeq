void rs2(){

  // ROTARY SWITCH ONE

  /******* BEGIN: ROTARY SWITCH TURN******/
  int rs2_btnState = digitalRead(RS2_SW);  
  if (rs2_btnState == LOW) {
    if (millis() - rs2_BtnLastPress > 50) {
      rs2_OnBtnPress();
    }    
    rs2_BtnLastPress = millis();
  }

  /** Step Value Trimming **/
  if(millis() - rs2_LastChange > 1) {
    rs2_ClkState = digitalRead(RS2_CLK);
    if (rs2_ClkState != rs2_ClkLastState  && rs2_ClkState == 1){        
      if (digitalRead(RS2_DT) != rs2_ClkState) {           
        rs2_OnUp();        
      } else {        
        rs2_OnDown();
      }        
    }
  
    rs2_ClkLastState = rs2_ClkState;
    rs2_LastChange = millis();
  }    

  /******* BEGIN: ROTARY SWITCH BUTTON ******/  

  rs2_TrimValue();
}

void rs2_OnUp(){  
  float currentStepVal = stepValues[stepValueIdx];
  float val = stepValueIncrements[stepValueIncrementIdx];       
  stepValues[stepValueIdx] = currentStepVal + val;
}

void rs2_OnDown(){      
  float currentStepVal = stepValues[stepValueIdx];
  float val = stepValueIncrements[stepValueIncrementIdx];      
  stepValues[stepValueIdx] = currentStepVal - val;
}

void rs2_OnBtnPress(){
  stepValueIncrementIdx = stepValueIncrementIdx == STEP_VALUE_INREMENT_MAX ? 0 : stepValueIncrementIdx + 1;
  Serial.println("Rotary Button 2 pressed!");
}

void rs2_TrimValue(){
  float currentStepVal = stepValues[stepValueIdx];
  if(currentStepVal > STEP_VALUE_MAX) {
    stepValues[stepValueIdx] = STEP_VALUE_MAX;
  } else 
  if (currentStepVal < 0) {
    stepValues[stepValueIdx] = 0;
  }    
}
