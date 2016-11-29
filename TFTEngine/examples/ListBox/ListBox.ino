#include <SoftwareSerial.h>
#include "TFTEngine.h"

TFTEngine tft(A3,A2);
TFTText list[5];
String routes[5] = {"ChinaNet-4auG","Xiaomi-5374","Maker-Office","Maker-Guest","ChinaNet-5auG"};
void setup(){
  Serial.begin(115200);
  tft.begin(115200);
  delay(1000);
  tft.cls();
  tft.render();
  for(int i=0;i<5;i++){
    list[i].text(routes[i]);
    list[i].position(20,20+45*i);
  }
}
int t = 0;
void loop(){
  int i = 0;
  for(i=0;i<5;i++){
    list[i].setBackgroundMode(i==t?1:0);
    tft.draw(&list[i]);
  }
  tft.render();
  delay(1000);
  t++;
  t = t>4?0:t;
}
