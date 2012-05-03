#ifndef COMPONENT_H
#define COMPONENT_H

#include "ulcdgui/guiobject.h"

class GuiEvent;
class Surface;

class Component : public GuiObject {
protected:
    void *user_data;

public:
    Component();
    virtual ~Component();

    void setUserData(void *data);
    void* getUserData();

    virtual void draw(Surface *sf) = 0;
    virtual void handle_event(GuiEvent *ev) = 0;
};

#endif
