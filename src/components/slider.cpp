#include "ulcdgui/components/slider.h"
#include "ulcdgui/misc/guiexception.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"

Slider::Slider(unsigned int min, unsigned int max, Alignment align) : Component() {
    if(min == max) {
        throw GuiException("Slider minimum value cannot be the same as maximum value.");
    }
    if(min > max) {
        throw GuiException("Slider min value has to be smaller than max value.");
    }
    this->min = min;
    this->max = max;
    this->range = max - min;
    this->align = align;
    this->last_w = 0;
    this->last_h = 0;
    this->position = 0;
}

void Slider::setValue(unsigned int value) {
    value = (value > this->max) ? this->max : value;
    value = (value < this->min) ? this->min : value;
    this->position = (value - this->min) / this->range;
}

unsigned int Slider::getValue() {
    return this->range * this->position + this->min;
}


void Slider::draw(Surface *sf) {
    // Clear background
    sf->setPen(PEN_SOLID);
    sf->setColor(Color::BACKGROUND);
    sf->rect(0, 0, sf->w, sf->h);

    // Save size
    last_w = sf->w;
    last_h = sf->h;

    // If necessary, decide which way we should draw the component
    Alignment an = this->align;
    if(an == ALIGN_AUTO) {
        if(sf->w >= sf->h) {
            an = ALIGN_HORIZONTAL;
        } else {
            an = ALIGN_VERTICAL;
        }
    }

    // Draw the slider
    int middle = 0;
    int slcenter = 0;
    int sbr = 8;
    int ticksep = 6;
    if(an == ALIGN_HORIZONTAL) {
        if(sf->h < 25) return;
        middle = sf->h / 2;
        slcenter = (sf->w - sbr*2) * this->position + sbr;

        // Middle line
        sf->setColor(Color(0.2,0.2,0.2));
        sf->line(sbr, middle+1, sf->w-sbr, middle+1);

        // Ticks
        sf->setColor(Color(0.3,0.3,0.3));
        sf->line(sbr, middle-5, sbr, middle+6);
        for(int i = sbr; i < sf->w-sbr; i=i+ticksep) {
            sf->line(i, middle-1, i, middle+3);
        }
        sf->line(sf->w-sbr, middle-5, sf->w-sbr, middle+6);

        // Draw slider rect
        sf->setColor(Color::FOREGROUND);
        sf->rect(slcenter-5, middle-9, slcenter+5, middle+10);
        sf->setPen(PEN_WIREFRAME);
        sf->setColor(Color::OUTERBORDER);
        sf->rect(slcenter-5, middle-9, slcenter+5, middle+10);
        sf->setColor(Color::INNERBORDER);
        sf->rect(slcenter-4, middle-8, slcenter+4, middle+9);
        sf->setPen(PEN_SOLID);
    } else {
        // TODO: Vertical sliders ...
    }
}

void Slider::handle_event(GuiEvent *ev) {
    // If necessary, decide which way we should draw the component
    Alignment an = this->align;
    if(an == ALIGN_AUTO) {
        if(last_w >= last_h) {
            an = ALIGN_HORIZONTAL;
        } else {
            an = ALIGN_VERTICAL;
        }
    }

    // Handle slider moving event
    int sbr = 8;
    if(ev->type == EVENT_MOVING || ev->type == EVENT_PRESS) {
        if(an == ALIGN_HORIZONTAL) {
            if(ev->local_x < sbr) {
                this->position = 0.0;
                return;
            }
            if(ev->local_x > last_w-sbr) {
                this->position = 1.0;
                return;
            }
            this->position = (double)(ev->local_x - sbr) / (double)(last_w - sbr*2);
        } else {
            // TODO: Vertical sliders ...
        }
        return;
    }

    // When released, tell listeners to do something.
    if(ev->type == EVENT_RELEASE) {
        this->update();
        this->changed.emit(ev, this->user_data);
    }
}
