#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "ulcdgui/guiobject.h"

class Surface;
class GuiEvent;

class Drawable : public GuiObject {
public:
    Drawable() : GuiObject() {}

    virtual void draw(Surface *s) = 0;
    virtual void handle_event(GuiEvent *ev) = 0;
};

#endif
