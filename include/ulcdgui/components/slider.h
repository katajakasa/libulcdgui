#ifndef SLIDER_H
#define SLIDER_H

#include "ulcdgui/components/component.h"
#include <sigc++/signal.h>

class Slider : public Component {
protected:
    double position;
    unsigned int min,max,range;
    Alignment align;
    int last_w, last_h;

public:
    sigc::signal<void, GuiEvent*, void*> changed;

    Slider(unsigned int min, unsigned int max, Alignment align = ALIGN_AUTO);

    void setValue(unsigned int value);
    unsigned int getValue();

    void draw(Surface *sf);
    void handle_event(GuiEvent *ev);
};

#endif // SLIDER_H
