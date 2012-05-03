#include "ulcdgui/guiobject.h"

GuiObject::GuiObject(ObjectType t) {
    this->type = t;
    this->refresh = true;
}

GuiObject::~GuiObject() {}

void GuiObject::setParent(GuiObject *parent) {
    this->parent = parent;
}

void GuiObject::update() {
    this->refresh = true;
    if(this->parent) {
        this->parent->update();
    }
}
