#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/vsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/guiobject.h"
#include "ulcdgui/components/component.h"

void VSizer::draw(Surface *s) {
    int c = this->objects.size();
    int ppc = s->h / c;

    int y = 0;
    for(GuiObject *obj : this->objects) {
        Surface *sub = s->getSubSurface(0, y, s->w, ppc);
        y += ppc;

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

void VSizer::handle_event(GuiEvent *ev) {
    return;
}
