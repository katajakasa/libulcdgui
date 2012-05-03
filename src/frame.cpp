#include "ulcdgui/frame.h"

Frame::Frame(LCDDevice *dev) : GuiObject(OBJECT_FRAME) {
    this->device = dev;
    this->base_sizer = 0;
}

Frame::~Frame() {
    if(this->base_sizer) {
        delete this->base_sizer;
    }
}

void Frame::run() {
    this->device->clearScreen();
    if(this->base_sizer) {
        Surface *s = this->device->getSurface();
        this->base_sizer->draw(s);
        delete s;
    }
}

void Frame::setBaseSizer(Sizer *sizer) {
    this->base_sizer = sizer;
}

void Frame::update() {

}
