#include "ulcdgui/components/button.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/rendering/color.h"

void Button::draw(Surface *sf) {
    sf->setPen(PEN_SOLID);

    // Background
    if(this->state == STATE_UP) {
        sf->setColor(Color(0.9f, 0.9f, 0.9f));
        sf->rect(2, 2, sf->w-2, sf->h-2);
    } else {
        sf->setColor(Color(0.7f, 0.7f, 0.7f));
        sf->rect(2, 2, sf->w-2, sf->h-2);
    }

    // Borders
    sf->setPen(PEN_WIREFRAME);
    sf->setColor(Color(0.7f, 0.7f, 0.7f));
    sf->rect(2, 2, sf->w-2, sf->h-2);
    sf->setColor(Color(0.65f, 0.65f, 0.65f));
    sf->rect(3, 3, sf->w-3, sf->h-3);

    // Draw text
    sf->setColor(Color(0.1f, 0.1f, 0.1f));
    int tw = text.length() * 8;
    int th = 12;
    int txm = (sf->w - tw) / 2;
    int tym = (sf->h - th) / 2;
    sf->text(this->text, txm, tym, 2);
}

void Button::handle_event(GuiEvent *ev) {
    if(ev->type == EVENT_PRESS || ev->type == EVENT_MOVING) {
        if(this->state == STATE_UP) {
            this->update();
        }
        this->state = STATE_DOWN;
    } else if(ev->type == EVENT_RELEASE) {
        if(this->state == STATE_DOWN) {
            this->update();
        }
        this->state = STATE_UP;
    }
}
