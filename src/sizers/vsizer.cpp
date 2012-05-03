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
    for(GuiObject *obj : this->objects) {
        Surface *sub = s->getSubSurface(0, y, s->w, ppc);
        y += ppc;
        if(!obj->refresh) continue;

        if(obj->type == OBJECT_COMPONENT) {
            Component *com = (Component*)obj;
            com->draw(sub);
            com->refresh = false;
        } else {
            Sizer *sizer = (Sizer*)obj;
            sizer->draw(sub);
            sizer->refresh = false;
        }

        delete sub;
    }
}

void VSizer::handle_event(GuiEvent *ev) {
    int c = this->objects.size();
    int ppc = this->last_h / c;
    int pos = ev->y / ppc;

    GuiObject *obj = this->objects.at(pos);
    if(obj->type == OBJECT_COMPONENT) {
        Component *com = (Component*)obj;
        com->handle_event(ev);
    } else {
        Sizer *sizer = (Sizer*)obj;
        sizer->handle_event(ev);
    }
}
