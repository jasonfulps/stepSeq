void stepSeqLcd(){

  if(millis() - lcdUpdated > DISPLAY_UPDATE_RATE) {

    String stepValueIdxDisplay = "STEP " + String(stepValueIdx + 1 ) + " ";
    String stepValueDisplay = String(stepValues[stepValueIdx]) + "v ";
    String newLcdRow1 = stepValueIdxDisplay + stepValueDisplay;    
    String newRow2 = "CLK  " + String(stepIdx + 1) + " " + String(stepValues[stepIdx]) + "v ";

//    lcd.clear();
//    lcd.setCursor ( 0, 0 );            // go to the top left corner
//    lcd.print("FOO ..."); // write this string on the top row
  

    if(newRow2 != lcdRow2 || newLcdRow1 != lcdRow1){      
      lcd.setCursor ( 0, 0 );            // go to the top left corner
      lcd.print(newLcdRow1); // write this string on the top row      
      lcd.setCursor ( 0, 1);            // go to the top left corner
      lcd.print(newRow2); // write this string on the top row      
      lcd.setCursor ( 0, 2);            // go to the top left corner
      lcd.print(renderLcdSteps());
      lcd.setCursor ( stepIdx, 2);            
      lcdRow1 = newLcdRow1;      
      lcdRow2 = newRow2;
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
