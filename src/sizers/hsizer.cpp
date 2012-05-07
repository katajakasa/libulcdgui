#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/sizers/hsizer.h"
#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/misc/guiobject.h"
#include "ulcdgui/components/component.h"

void HSizer::draw(Surface *s) {
    if(!this->refresh) return;
    this->refresh = false;

    int x = 0;
    for(Drawable *obj : this->objects) {
        if(obj->refresh) {
            Surface *sub = s->getSubSurface(x, 0,
                                            obj->getW(),
                                            obj->getH());
            obj->draw(sub);
            delete sub;
        }
        obj->refresh = false;
        x += obj->getW();
    }
}

void HSizer::handle_event(GuiEvent *ev) {
    unsigned int x = 0;
    for(Drawable *obj : this->objects) {
        if(x <= ev->local_x && ev->local_x < x+obj->getW()) {
            ev->setParams(obj, x, 0);
            obj->handle_event(ev);
        }
        x += obj->getW();
    }
}

void HSizer::precalc_layout(int x, int y) {
    unsigned int med = w / this->objects.size();
    int tw = w;
    int tc = this->objects.size();
    for(Drawable *obj : this->objects) {
        if(obj->getMaxW() < med) {
            tw -= obj->getMaxW();
            tc--;
        }
    }
    if(tc > 0) {
        med = tw / tc;
    }

    // Try to disable min or max from elements at the back of the list if necessary
    bool run = true;
    unsigned int req_pixels = 0;
    unsigned int last_req = 0;
    for(unsigned int t = this->objects.size(); t > 0 && run; t--) {
        // Try to make medium lower for elements that have no min or max
        for(unsigned int v = med; v > 0 && run; v--) {
            req_pixels = 0;
            // Try to calculate sizes for components
            for(unsigned int i = 0; i < this->objects.size() && run; i++) {
                Drawable *obj = this->objects.at(i);
                if(i > t) {
                    obj->setSize(v, h);
                    continue;
                }
                if(obj->getMinW() > v) {
                    obj->setSize(obj->getMinW(), h);
                }
                else if(obj->getMaxW() < v) {
                    obj->setSize(obj->getMaxW(), h);
                }
                else {
                    obj->setSize(v, h);
                }
                req_pixels += obj->getW();
            }

            // If there was no change to the previous run, just break the pixel test loop
            // and try disabling min & max testing from more elements
            if(last_req == req_pixels) {
                break;
            }
            last_req = req_pixels;

            // Check if we could fit it all into the sizer
            if(req_pixels <= w) {
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
