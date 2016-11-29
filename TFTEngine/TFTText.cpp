#include "TFTText.h"

TFTText::TFTText():TFTObject(){
    _cls = "";
    _changed = false;
    _size = 12;
    _color = 4;
    _backgroundColor = 20;
    _backgroundMode = 1;
}

void TFTText::text(String msg){
  _text = msg;
  _changed = true;
}
void TFTText::position(int x,int y){
  _position.x = x;
  _position.y = y;
  _changed = true;
}
String TFTText::render(){
  if(!_changed){
    return "";
  }
  String r = "DS";
  r+=_size;
  r+="(";
  r+=_position.x;
  r+=_position.y;
  r+=",'";
  r+=_text;
  r+="',";
  r+=_color;
  r+=")";
  _cls = "BOXF(";
  _cls += _position.x;
  _cls += ",";
  _cls += _position.y;
  _cls += ",";
  _cls += _position.x+_text.length()*_size;
  _cls += ",";
  _cls += _position.y+_size;
  _cls += ",0);";
  _changed = false;
  return r;
}
void TFTText::setSize(int fontSize){
  _size = fontSize;
  _changed = true;
}
void TFTText::setColor(int c){
  
  _changed = true;
}
void TFTText::setBackgroundColor(int c){
  
  _changed = true;
}
void TFTText::setBackgroundMode(int mode){
  
  _changed = true;
}

