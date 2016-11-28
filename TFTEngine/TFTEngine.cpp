#include "TFTEngine.h"

TFTEngine::TFTEngine(void){

}
TFTEngine::TFTEngine(uint8_t txPin,uint8_t rxPin){
  _tft = new SoftwareSerial(txPin,rxPin);
}
void TFTEngine::begin(int baudrate){
  _tft->begin(baudrate);
}
void TFTEngine::setBaudrate(int rate){
    
}
void TFTEngine::cls(){
    _tft->print("CLS(0);DR0;");
}
void TFTEngine::draw(TFTObject obj){
    _cleanObject(obj);
    _tft->print(obj.render());
}
void TFTEngine::render(){
    _tft->println();
}
void TFTEngine::_cleanObject(TFTObject obj){
    _tft->print(obj.clear());
}
