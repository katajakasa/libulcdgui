#ifndef SIZER_H
#define SIZER_H

#include <list>
#include "ulcdgui/guiobject.h"

class Surface;
class GuiEvent;

class Sizer : public GuiObject {
protected:
    std::list<GuiObject*> objects;

public:
    Sizer();
    virtual ~Sizer();

    void addComponent(GuiObject *obj);

    virtual void draw(Surface *s) = 0;
    virtual void handle_event(GuiEvent *ev) = 0;
};

#endif
