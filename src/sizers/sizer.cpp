#include "ulcdgui/sizers/sizer.h"

Sizer::Sizer() : GuiObject(OBJECT_SIZER) {}

Sizer::~Sizer() {
    for(GuiObject *obj : this->objects) {
        delete obj;
    }
}

void Sizer::addComponent(GuiObject *obj) {
    obj->setParent(this);
    this->objects.push_back(obj);
}
