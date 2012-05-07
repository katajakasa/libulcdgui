#ifndef EVENT_H
#define EVENT_H

#include "ulcdgui/misc/guiobject.h"

enum EventType {
    EVENT_PRESS,
    EVENT_RELEASE,
    EVENT_MOVING,
    EVENT_LEAVING,
};

class GuiEvent {
public:
    EventType type;
    unsigned int global_x, global_y;
    unsigned int local_x, local_y;
    GuiObject *emitter;

    void setParams(GuiObject *emitter, unsigned int offset_x, unsigned int offset_y) {
        this->local_x -= offset_x;
        this->local_y -= offset_y;
        this->emitter = emitter;
    }
};

#endif
