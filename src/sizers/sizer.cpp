#include "ulcdgui/sizers/sizer.h"

Sizer::Sizer() : Drawable() {}

Sizer::~Sizer() {
    for(Drawable *obj : this->objects) {
        delete obj;
    }
}

void Sizer::addComponent(Drawable *obj) {
    obj->setParent(this);
    this->objects.push_back(obj);
}
