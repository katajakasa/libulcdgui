#ifndef HSIZER_H
#define HSIZER_H

#include "ulcdgui/sizers/sizer.h"

class Surface;
class GuiEvent;

class HSizer : public Sizer {
public:
    HSizer() : Sizer() {}

    void draw(Surface *s);
    void handle_event(GuiEvent *ev);
};

#endif
