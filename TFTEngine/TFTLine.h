#ifndef TFTLine_H_
#define TFTLine_H_

#include "TFTObject.h"

class TFTLine : public TFTObject{
    public:
        TFTLine();
        void start(float x,float y);
        void end(float x,float y);
        void setColor(int c);
        String clear();
        String render();
    private:
        vector2d _start;
        vector2d _end;
        int _color;
        String _cls;
};

#endif
