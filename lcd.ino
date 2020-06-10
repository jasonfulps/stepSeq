void stepSeqLcd(){

  if(millis() - lcdUpdated > DISPLAY_UPDATE_RATE) {
  
    if(lcdMode == 0){
      lcd.setCursor ( 0, 0 );            
      lcd.write(0);         
      lcd.setCursor ( 1, 0 );            
      lcd.write(1);         
      lcd.setCursor ( 2, 0 );            
      lcd.write(2);         

    }
  
    if(lcdMode == 1){      
        String stepValueIdxDisplay = "STEP " + String(stepValueIdx + 1 ) + " ";
        String stepValueDisplay = String(stepValues[stepValueIdx]) + "v ";
        String newLcdRow1 = stepValueIdxDisplay + stepValueDisplay;    
        String newRow2 = "CLK  " + String(stepIdx + 1) + " " + String(stepValues[stepIdx]) + "v ";
      
        if(newRow2 != lcdRow2 || newLcdRow1 != lcdRow1){      
          lcd.setCursor ( 0, 0 );            
          lcd.print(newLcdRow1); 
          lcd.setCursor ( 0, 1); 
          lcd.print(newRow2);
          lcd.setCursor ( stepIdx, 2);            
          lcdRow1 = newLcdRow1;      
          lcdRow2 = newRow2;
        }      
    }
    
    lcdUpdated = millis();
  }
}

String renderLcdSteps() {
  String steps = "";
  for (int i = 0; i < SEQ_LEN_MAX; i++) {    
    if(i == stepIdx && i == stepValueIdx) {
      steps += "$";    
    } else 
    if(i == stepIdx) {
      steps += "|";    
    } else 
    if(i == stepValueIdx) {
      steps += "S";    
    } else {
      steps += ".";    
    }    
  }
  return steps;
}
