#include "ulcdgui/components/button.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/rendering/color.h"

void Button::draw(Surface *sf) {
    sf->setPen(PEN_SOLID);

    if(this->state == STATE_UP) {
        sf->setColor(Color(0.9f, 0.9f, 0.9f));
        sf->rect(2, 2, sf->w-2, sf->h-2);
    } else {
        sf->setColor(Color(0.8f, 0.8f, 0.8f));
        sf->rect(2, 2, sf->w-2, sf->h-2);
    }

    sf->setColor(Color(0.1f, 0.1f, 0.1f));

    int tw = text.length() * 8;
    int th = 12;
    int txm = (sf->w - tw) / 2;
    int tym = (sf->h - th) / 2;
    sf->text(this->text, txm, tym, 2);
}

void Button::handle_event(GuiEvent *ev) {
    if(ev->type == EVENT_PRESS) {
        this->state = STATE_DOWN;
    } else if(ev->type == EVENT_RELEASE) {
        this->state = STATE_UP;
    }
}
