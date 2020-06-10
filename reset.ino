void resetLoop(){
    int resetState = analogRead(RESET);
  if (resetState > 1000 ) {
    if (millis() - reset_LastTrigger > 50) {
      reset_OnTrigger();
    }    
    reset_LastTrigger = millis();
  }   
}

void reset_OnTrigger(){
  stepIdx = 0;
  //Serial.println("RESET triggered!"); 
}
