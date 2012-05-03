#ifndef EVENT_H
#define EVENT_H

enum EventType {
    EVENT_PRESS,
    EVENT_RELEASE,
    EVENT_MOVING
};

class GuiEvent {
public:
    EventType type;
    int x,y;
};

#endif
