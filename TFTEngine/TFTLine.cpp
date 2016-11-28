#include "TFTLine.h"

TFTLine::TFTLine():TFTObject(){
    _color = 4;
    _cls = "";
}
String TFTLine::clear(){
    return _cls; 
}
String TFTLine::render(){
    String r = "PL(";
    r+=_start.x;
    r+=(",");
    r+=(_start.y);
    r+=(",");
    r+=(_end.x);
    r+=(",");
    r+=(_end.y);
    r+=(",");
    _cls = r;
    _cls+=0;
    _cls+=");";
    r+=_color;
    r+= ");";
    return r;
}
void TFTLine::start(float x,float y){
    _start.x = x;
    _start.y = y;
}
void TFTLine::end(float x,float y){
    _end.x = x;
    _end.y = y;
}
void TFTLine::setColor(int c){
    _color = c;            
}