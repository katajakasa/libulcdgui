#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/hsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/misc/guiobject.h"
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
    // Find the object the event belongs to
    int c = this->objects.size();
    int ppc = this->last_w / c;
    unsigned int pos = ev->local_x / ppc;
    if(pos == this->objects.size()) pos--;

    // Get object, change event a bit and handle it
    Drawable *obj = this->objects.at(pos);
    ev->setParams(obj, ppc*pos, 0);
    obj->handle_event(ev);
}
