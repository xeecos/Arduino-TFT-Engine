#include "TFTText.h"

TFTText::TFTText():TFTObject(){
    _cls = "";
    _changed = false;
    _size = 16;
    _color = 4;
    _backgroundColor = 11;
    _backgroundMode = 0;
}

void TFTText::text(String msg){
  _text = msg;
  _changed = true;
}
void TFTText::position(int x,int y){
  if(_position.x != x || _position.y != y){
    _position.x = x;
    _position.y = y;
    _changed = true;
  }
}
String TFTText::render(){
  if(!_changed||_position.y>240){
    return "";
  }
  String r =  _cls;
  if(_backgroundMode==3){
    r += "PL(";
    r += _position.x-6;
    r += ",";
    r += _position.y+_size+4;
    r += ",";
    r += _position.x+_text.length()*_size/2+4;
    r += ",";
    r += _position.y+_size+4;
    r += ",";
    r += _backgroundColor;
    r += ");";
  }else if(_backgroundMode>0){
    r += _backgroundMode==1?"BOX(":"BOXF(";
    r += _position.x-10;
    r += ",";
    r += _position.y-10;
    r += ",";
    r += _position.x+_text.length()*_size/2+8;
    r += ",";
    r += _position.y+_size+8;
    r += ",";
    r += _backgroundColor;
    r += ");";
  }
  r += "DS";
  r +=_size;
  r +="(";
  r +=_position.x;
  r += ",";
  r +=_position.y;
  r +=",'";
  r +=_text;
  r +="',";
  r +=_color;
  r +=");";
  _cls = "BOXF(";
  _cls += _position.x-10;
  _cls += ",";
  _cls += _position.y-10;
  _cls += ",";
  _cls += _position.x+_text.length()*_size/2+8;
  _cls += ",";
  _cls += _position.y+_size+8;
  _cls += ",0);";
  _changed = false;
  return r;
}
void TFTText::size(int fontSize){
  if(_size != fontSize){
    _size = fontSize;
    _changed = true;
  }
}
void TFTText::setColor(int c){
  if(_color != c){
    _color = c;
    _changed = true;
  }
}
void TFTText::setBackgroundColor(int c){
  if(_backgroundColor != c){
    _backgroundColor = c;
    _changed = true;
  }
}
void TFTText::setBackgroundMode(int mode){
  if(_backgroundMode!=mode){
    _backgroundMode = mode;
    _changed = true;
  }
}
void TFTText::cls(){
  
}

