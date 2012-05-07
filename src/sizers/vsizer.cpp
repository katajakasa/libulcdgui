#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/vsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/misc/guiobject.h"
#include "ulcdgui/components/component.h"

#include <iostream>

void VSizer::draw(Surface *s) {
    if(!this->refresh) return;
    this->refresh = false;

    int y = 0;
    for(Drawable *obj : this->objects) {
        if(obj->refresh) {
            Surface *sub = s->getSubSurface(0, y,
                                            obj->getW(),
                                            obj->getH());
            obj->draw(sub);
            delete sub;
        }
        obj->refresh = false;
        y += obj->getH();
    }
}

void VSizer::handle_event(GuiEvent *ev) {
    unsigned int y = 0;
    for(Drawable *obj : this->objects) {
        if(y <= ev->local_y && ev->local_y < y+obj->getH()) {
            ev->setParams(obj, 0, y);
            obj->handle_event(ev);
        }
        y += obj->getH();
    }
}

void VSizer::precalc_layout(int x, int y) {
    int med = h / this->objects.size();
    unsigned int req_pixels = 0;

    // Try to disable min or max from elements at the back of the list if necessary
    bool run = true;
    for(unsigned int t = this->objects.size(); t > 0 && run; t--) {
        // Try to make medium lower for elements that have no min or max
        for(unsigned int v = med; v > 0 && run; v--) {
            req_pixels = 0;
            // Try to calculate sizes for components
            for(unsigned int i = 0; i < this->objects.size() && run; i++) {
                Drawable *obj = this->objects.at(i);
                if(i > t) {
                    obj->setSize(w, v);
                    continue;
                }
                if(obj->getMinH() > v) {
                    obj->setSize(w, obj->getMinH());
                    std::cout << ":: " << obj->getH() << std::endl;
                }
                else if(obj->getMaxH() < v) {
                    obj->setSize(w, obj->getMaxH());
                }
                else {
                    obj->setSize(w, v);
                }
                req_pixels += obj->getH();

            }

            // Check if we could fit it all into the sizer
            if(req_pixels <= h) {
                run = false;
            }
        }
    }

    // Precalculate moar
    int dx = 0;
    for(Drawable *obj : this->objects) {
        obj->precalc_layout(dx, y);
        dx += obj->getW();
    }
}
