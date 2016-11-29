#ifndef TFTObject_H_
#define TFTObject_H_
#include <Arduino.h>

struct vector2d{
    float x;
    float y;
};
struct pixel2d{
    int x;
    int y;
};
struct vector3d{
    float x;
    float y;
    float z;
};
class TFTObject{
    public:
        TFTObject();
        virtual String clear() { return ""; };
        virtual String render() { return ""; };

};

#endif
