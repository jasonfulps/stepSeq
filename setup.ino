void setup() {

  // LCD
  lcd.blink();
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
  
  // Rotary Switch
  pinMode(RS1_CLK,INPUT);
  pinMode(RS1_DT,INPUT);
  pinMode(RS1_SW, INPUT_PULLUP);

  // Rotary Switch 2
  pinMode(RS2_CLK,INPUT);
  pinMode(RS2_DT,INPUT);
  pinMode(RS2_SW, INPUT_PULLUP);

  // Button 1
  pinMode(BTN1, INPUT_PULLUP);

  // Clock
  pinMode(CLOCK, INPUT);
  pinMode(RESET, INPUT);
  
 
  // Rotary Switches initial CLK state
  rs1_ClkLastState = digitalRead(RS1_CLK);
  rs2_ClkLastState = digitalRead(RS2_CLK);

  // Clock
  clock_LastTrigger = analogRead(CLOCK);
  reset_LastTrigger = analogRead(RESET);
 
  // Setup Serial Monitor
  Serial.begin(9600);

}
