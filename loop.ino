void loop() {

  // TODO see if you can use resistors to seperate many rotary switches on the same digital input.

  // Rotary Switch
  rs1();

  // Rotary Switch 2
  rs2();

  // Button 1
//  btn1();

  // clock
  clockLoop();
  resetLoop();

  // Display
  stepSeqConsole();   
  stepSeqLcd();
}
