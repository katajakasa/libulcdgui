#include "ulcdgui/frame.h"

Frame::Frame(LCDDevice *dev) : GuiObject() {
    this->device = dev;
    this->base_sizer = 0;

    // Clear screen + set background color
    Surface *s = this->device->getSurface();
    s->setColor(Color(0.97, 0.97, 0.97));
    s->rect(0, 0, s->w, s->h);
    delete s;
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
