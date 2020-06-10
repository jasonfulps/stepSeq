void stepSeqConsole(){

  if(millis() - consoleUpdated > DISPLAY_UPDATE_RATE) {

    String stepValueIdxDisplay = "S " + String(stepValueIdx + 1 ) + " ";
    String stepValueDisplay = String(stepValues[stepValueIdx]) + "v ";
    String newconsoleRow1 = stepValueIdxDisplay + stepValueDisplay;
    
    String newConsoleRow2 = "| " + String(stepIdx + 1) + " " + String(stepValues[stepIdx]) + "v ";


    if(newConsoleRow2 != consoleRow2 || newconsoleRow1 != consoleRow1){      
      Serial.println("____________________");  
      Serial.println(renderSteps());
      consoleRow1 = newconsoleRow1;
      Serial.println(consoleRow1);  
      consoleRow2 = newConsoleRow2;
      Serial.println(consoleRow2);  
      Serial.println("____________________\n");  
    }      

    consoleUpdated = millis();
  }    
}

String renderSteps() {
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
