/**
 Clock 
  - button for manual clock.
  - input jack for external clock  
**/


void clockLoop(){
    int clockState = analogRead(CLOCK);
  if (clockState > 1000) {    
    if (millis() - clock_LastTrigger > 100) {
      clock_OnTrigger();
    }    
    clock_LastTrigger = millis();
  }   
}

void clock_OnTrigger(){
  stepIdx = stepIdx == SEQ_LEN_MAX ? 0 : stepIdx + 1;
  // Serial.println("CLOCK triggered!"); 
}
