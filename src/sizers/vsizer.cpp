#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/vsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/guiobject.h"
#include "ulcdgui/components/component.h"

void VSizer::draw(Surface *s) {
    this->last_w = s->w;
    this->last_h = s->h;
    if(!this->refresh) return;
    this->refresh = false;

    int c = this->objects.size();
    int ppc = s->h / c;

    int y = 0;
    for(Drawable *obj : this->objects) {
        if(!obj->refresh) {
            y += ppc;
            continue;
        }

        Surface *sub = s->getSubSurface(0, y, s->w, ppc);
        y += ppc;
        obj->draw(sub);
        obj->refresh = false;
        delete sub;
    }
}

void VSizer::handle_event(GuiEvent *ev) {
    // Find the object the event belongs to
    int c = this->objects.size();
    int ppc = this->last_h / c;
    unsigned int pos = ev->local_y / ppc;
    if(pos == this->objects.size()) pos--;

    // Get object, change event a bit and handle it
    Drawable *obj = this->objects.at(pos);
    ev->setParams(obj, ppc*pos, 0);
    obj->handle_event(ev);
}
