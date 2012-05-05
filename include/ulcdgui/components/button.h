#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "ulcdgui/components/component.h"
#include <sigc++/signal.h>

class Surface;
class GuiEvent;

enum {
    STATE_UP = 0,
    STATE_DOWN,
};

class Button : public Component {
protected:
    int state;
    std::string text;

public:
    sigc::signal<void, GuiEvent*, void*> clicked;

    Button(std::string text) : Component() {
        this->state = STATE_UP;
        this->text = text;
    }

    void draw(Surface *sf);
    void handle_event(GuiEvent *ev);
};

#endif
