#ifndef DEVICE_H
#define DEVICE_H

#include <ulcd_driver.h>
#include "ulcdgui/guiexception.h"
#include "ulcdgui/rendering/surface.h"

class GuiEvent;

class LCDDevice {
protected:
    ulcd_dev *dev;

public:
    LCDDevice(int port);
    ~LCDDevice();

    void clearScreen();
    bool getEvent(GuiEvent *ev);
    Surface* getSurface();

    void setVolume(int level);
    void mute();
    void unmute();
    void playAudio(std::string file);
    void stopAudio();
};

#endif
