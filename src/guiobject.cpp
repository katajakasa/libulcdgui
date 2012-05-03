#include "ulcdgui/guiobject.h"

GuiObject::GuiObject(ObjectType t) {
    this->type = t;
}

GuiObject::~GuiObject() {}

void GuiObject::setParent(GuiObject *parent) {
    this->parent = parent;
}

void GuiObject::update() {
    if(this->parent) {
        this->parent->update();
    }
}
