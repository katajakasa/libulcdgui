#ifndef VSIZER_H
#define VSIZER_H

#include "ulcdgui/sizers/sizer.h"

class Surface;
class GuiEvent;

class VSizer : public Sizer {
public:
    VSizer() : Sizer() {}

    void draw(Surface *s);
    void handle_event(GuiEvent *ev);
    void precalc_layout(int x, int y);
};

#endif
