#include <SoftwareSerial.h>
#include "TFTEngine.h"
TFTEngine tft(A3,A2);
void setup(){
  tft.begin(115200);
  delay(1000);
  tft.cls();
  tft.render();
}
void loop(){
    
}
