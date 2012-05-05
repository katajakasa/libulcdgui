#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/hsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/guiobject.h"
#include "ulcdgui/components/component.h"

void HSizer::draw(Surface *s) {
    this->last_w = s->w;
    this->last_h = s->h;
    if(!this->refresh) return;
    this->refresh = false;

    int c = this->objects.size();
    int ppc = s->w / c;

    int x = 0;
    for(Drawable *obj : this->objects) {
        if(!obj->refresh) {
            x += ppc;
            continue;
        }

        Surface *sub = s->getSubSurface(x, 0, ppc, s->h);
        x += ppc;
        obj->draw(sub);
        obj->refresh = false;
        delete sub;
    }
}

void HSizer::handle_event(GuiEvent *ev) {
    int c = this->objects.size();
    int ppc = this->last_w / c;
    unsigned int pos = ev->x / ppc;
    if(pos == this->objects.size()) pos--;
    this->objects.at(pos)->handle_event(ev);
}
