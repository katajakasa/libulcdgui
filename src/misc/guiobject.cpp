#include "ulcdgui/misc/guiobject.h"

GuiObject::GuiObject() {
    this->refresh = true;
    this->parent = 0;
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
