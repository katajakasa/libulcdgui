#ifndef SIZER_H
#define SIZER_H

#include <vector>
#include "ulcdgui/guiobject.h"

class Surface;
class GuiEvent;

class Sizer : public GuiObject {
protected:
    std::vector<GuiObject*> objects;
    int last_w, last_h;

public:
    Sizer();
    virtual ~Sizer();

    void addComponent(GuiObject *obj);

    virtual void draw(Surface *s) = 0;
    virtual void handle_event(GuiEvent *ev) = 0;
};

#endif
