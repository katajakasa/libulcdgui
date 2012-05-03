#ifndef DEVICE_H
#define DEVICE_H

#include <ulcd_driver.h>
#include "guiexception.h"
#include "rendering/surface.h"

class LCDDevice {
protected:
    ulcd_dev *dev;

public:
    LCDDevice(int port);
    ~LCDDevice();

    void clearScreen();

    Surface* getSurface();
};

#endif
