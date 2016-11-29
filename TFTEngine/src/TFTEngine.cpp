#include "TFTEngine.h"

TFTEngine::TFTEngine(void):SoftwareSerial(-1,-1){

}
TFTEngine::TFTEngine(uint8_t txPin,uint8_t rxPin): SoftwareSerial(txPin, rxPin){
    
}
void TFTEngine::setBaudrate(int rate){
    
}
void TFTEngine::cls(){
    TFTEngine::print("CLS(0);DR0;");
}
void TFTEngine::draw(TFTObject* obj){
    TFTEngine::print(obj->render());
}
void TFTEngine::render(){
    TFTEngine::println();
}
void TFTEngine::_cleanObject(TFTObject* obj){
    TFTEngine::print(obj->clear());
}
