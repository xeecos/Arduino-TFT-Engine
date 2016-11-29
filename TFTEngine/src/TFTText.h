#ifndef TFTText_H_
#define TFTText_H_
#include "TFTObject.h"
class TFTText:public TFTObject{
  public:
    TFTText();
    void text(String msg);
    void position(int x,int y);
    void size(int size);
    void setColor(int c);
    void setBackgroundColor(int c);
    void setBackgroundMode(int mode);
    String render();
  private:
    void cls();
    pixel2d _position;
    String _cls;
    String _text;
    bool _changed;
    int _size;
    int _color;
    int _backgroundColor;
    int _backgroundMode;
};

#endif
