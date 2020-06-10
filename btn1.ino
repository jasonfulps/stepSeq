void btn1(){
    int btn1_State = digitalRead(BTN1);
//    Serial.println( String(btn1_State)); 
  if (btn1_State == HIGH) {
    if (millis() - btn1_LastPress > 50) {
      btn1_OnPress();
    }    
    btn1_LastPress = millis();
  }  
}

void btn1_OnPress(){
 Serial.println("Button 1 pressed!"); 
}
