#ifndef TFTEngine_H_
#define TFTEngine_H_
#include <SoftwareSerial.h>
#include "TFTLine.h"
#include "TFTText.h"
class TFTEngine:public SoftwareSerial
{
    public:
        TFTEngine(void);
        TFTEngine(uint8_t txPin,uint8_t rxPin);
        void setBaudrate(int rate);
        void cls();
        void draw(TFTObject *obj);
        void render();
    private:
        void _cleanObject(TFTObject *obj);
};
#endif
