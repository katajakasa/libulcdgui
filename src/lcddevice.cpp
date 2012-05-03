#include "ulcdgui/lcddevice.h"

LCDDevice::LCDDevice(int port) {
    this->dev = ulcd_init(port);
    if(!this->dev) {
        throw GuiException(ulcd_get_error_str());
    }
}

LCDDevice::~LCDDevice() {
    ulcd_close(this->dev);
}

void LCDDevice::clearScreen() {
    ulcd_clear(this->dev);
}

Surface* LCDDevice::getSurface() {
    return new Surface(this->dev);
}
