#include "ulcdgui/lcddevice.h"
#include "ulcdgui/events/event.h"

LCDDevice::LCDDevice(std::string device) {
    this->dev = ulcd_init(device.c_str());
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

        ev->global_x = uev.x;
        ev->local_x = uev.x;
        ev->global_y = uev.y;
        ev->local_y = uev.y;
        ev->emitter = 0;
        return true;
    }
    return false;
}

void LCDDevice::setVolume(int level) {
    if(level < ULCD_VOLUME_MIN) level = ULCD_VOLUME_MIN;
    if(level > ULCD_VOLUME_MAX) level = ULCD_VOLUME_MAX;
    if(!ulcd_set_volume(this->dev, level)) {
        throw GuiException(ulcd_get_error_str());
    }
}

void LCDDevice::mute() {
    if(!ulcd_set_volume(this->dev, ULCD_VOLUME_MUTE)) {
        throw GuiException(ulcd_get_error_str());
    }
}

void LCDDevice::unmute() {
    if(!ulcd_set_volume(this->dev, ULCD_VOLUME_UNMUTE)) {
        throw GuiException(ulcd_get_error_str());
    }
}

void LCDDevice::playAudio(std::string file) {
    if(!ulcd_audio_play(this->dev, file.c_str())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void LCDDevice::stopAudio() {
    if(!ulcd_audio_stop(this->dev)) {
        throw GuiException(ulcd_get_error_str());
    }
}
