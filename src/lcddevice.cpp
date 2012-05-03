#include "ulcdgui/lcddevice.h"
#include "ulcdgui/events/event.h"

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

bool LCDDevice::getEvent(GuiEvent *ev) {
    ulcd_event uev;
    ulcd_get_event(this->dev, &uev);
    if(uev.type != ULCD_NO_ACTIVITY) {
        switch(uev.type) {
        case ULCD_TOUCH_PRESS:
            ev->type = EVENT_PRESS;
            break;
        case ULCD_TOUCH_RELEASE:
            ev->type = EVENT_RELEASE;
            break;
        case ULCD_TOUCH_MOVING:
            ev->type = EVENT_MOVING;
            break;
        }

        ev->x = uev.x;
        ev->y = uev.y;
        return true;
    }
    return false;
}
