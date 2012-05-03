#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/hsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/guiobject.h"
#include "ulcdgui/components/component.h"

void HSizer::draw(Surface *s) {
    int c = this->objects.size();
    int ppc = s->w / c;

    int x = 0;
    for(GuiObject *obj : this->objects) {
        Surface *sub = s->getSubSurface(x, 0, ppc, s->h);
        x += ppc;

        if(obj->type == OBJECT_COMPONENT) {
            Component *com = (Component*)obj;
            com->draw(sub);
        } else {
            Sizer *sizer = (Sizer*)obj;
            sizer->draw(sub);
        }

        delete sub;
    }
}

void HSizer::handle_event(GuiEvent *ev) {
    return;
}
