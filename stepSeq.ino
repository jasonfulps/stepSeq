// LCD 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Rotary Encoder Constants
#define RS1_CLK 2
#define RS1_DT 3
#define RS1_SW 4

// Rotary Encoder 2 Constants
#define RS2_CLK 5
#define RS2_DT 6
#define RS2_SW 7

// Push button 1
#define BTN1 8

// Clock
#define CLOCK A0
#define RESET A1

// Step Constants
#define SEQ_LEN_MAX 64
#define STEP_VALUE_MAX 1
#define STEP_VALUE_INREMENT_MAX 2

// Display Constants
#define DISPLAY_UPDATE_RATE 1

// Console Display
int consoleUpdated = 0;
String consoleRow1 = "Row 1";
String consoleRow2 = "Row 2";

// LCD Display
int lcdMode = 0; // 0 steps, 1 step details
int lcdUpdated = 0;
String lcdRow1 = "Row 1";
String lcdRow2 = "Row 2";


// Rotary Switch 
int rs1_ClkState;
int rs1_ClkLastState;
String rs1_Direction ="";
unsigned long rs1_BtnLastPress = 0;
unsigned long rs1_LastChange = 0;

// Rotary Switch 2
int rs2_ClkState;
int rs2_ClkLastState;
String rs2_Direction ="";
unsigned long rs2_BtnLastPress = 0;
unsigned long rs2_LastChange = 0;

// Button 1
unsigned long btn1_LastPress = 0;

// Clock
unsigned long clock_LastTrigger = 0;
unsigned long reset_LastTrigger = 0;

// Step Index
int stepIdx = 0;
int stepDivision = 4;
int stepValueIdx = 0;
int stepDisplayBarSpacerChar = 1;

// Step Value Variables
int stepValueIncrementIdx = 0;
float stepValueIncrements[STEP_VALUE_INREMENT_MAX+1] = {.10, .05, .01};
float stepValues[SEQ_LEN_MAX] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// LCD Custom Chars
byte blank[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte frame[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
};

byte all[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

