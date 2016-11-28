#ifndef TFTObject_H_
#define TFTObject_H_
#include <Arduino.h>

struct vector2d{
    float x;
    float y;
};
struct vector3d{
    float x;
    float y;
    float z;
};
class TFTObject{
    public:
        TFTObject();
        String clear();
        String render();

};

#endif
