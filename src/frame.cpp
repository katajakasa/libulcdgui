#include "ulcdgui/frame.h"

Frame::Frame(LCDDevice *dev) : GuiObject() {
    this->device = dev;
    this->base_sizer = 0;
    this->device->clearScreen();
}

Frame::~Frame() {
    if(this->base_sizer) {
        delete this->base_sizer;
    }
    this->device->clearScreen();
}

void Frame::run() {
    // Draw if necessary & possible
    if(this->base_sizer && this->base_sizer->refresh) {
        Surface *s = this->device->getSurface();
        this->base_sizer->draw(s);
        delete s;
    }

    // Check events
    GuiEvent ev;
    if(this->device->getEvent(&ev) && this->base_sizer) {
        this->base_sizer->handle_event(&ev);
    }
}

void Frame::setBaseSizer(Sizer *sizer) {
    this->base_sizer = sizer;
    this->base_sizer->setParent(this);
}

void Frame::update() {

}
