/* 
 * This is a advanced example for the "six-digit-seven-segment" Library
 * for more information see https://6-digit-7-segment-arduino.readthedocs.org
 * by SohnyBohny
*/

#include <SegmentDisplay.h>
int latchPin = 9; // Shiftregister
int clockPin = 10;
int dataPin = 8;

int digit1 = 6; // cathode of the digits
int digit2 = 1;
int digit3 = 2;
int digit4 = 3;
int digit5 = 4;
int digit6 = 5;
int punkt = 7; // anode of the DP

SegmentDisplay segmentDisplay(latchPin, // tell the library the pins -> pinMode will be called
                              clockPin,
                              dataPin,
                              digit1,
                              digit2,
                              digit3,
                              digit4,
                              digit5,
                              digit6,
                              punkt);
                              
  String input = "5tArt";

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome - please tell me what I should say");
  Serial.println("Legal charakters are:");
  Serial.println("0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t0");
  Serial.println("o(°)\tC\tF\tA\tb\tC\td\tE\tF\tG\tH");
  Serial.println("I\tJ\tL\tU\tc\th\tn\tO(o)\t0(O)\tr\tt");
  Serial.println("u\tp\ty\t\tX(for SPACE)");
  
  Serial.flush();
}

void loop() {
  bool corectChars = true;
  if(Serial.available()>0){
    corectChars = true;
    char inChar = '';
    while(Serial.available()>0){
      inChar = serial.read();
      if(!segmentDisplay.isLegal(inChar)){
        Serial.println("ERROR ------ " + String(inChar) + "is not legal");
        corectChars = false;
      }
      input += inChar;
    }
    if(!segmentDisplay.isLegal(inChar)){
        Serial.println("ERROR ------ " + String(inChar) + "is not legal");
        corectChars = false;
      }
    input += inChar;
    
    if(!corectChars){
      input = "tryXAGAIn";
    }
  }

  while(Serial.available()==0){
    segmentDisplay.showString(input);  
  }

}
