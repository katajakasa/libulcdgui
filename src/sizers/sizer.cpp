#include "ulcdgui/sizers/sizer.h"

Sizer::Sizer() : Drawable() {}

Sizer::~Sizer() {
    for(Drawable *obj : this->objects) {
        delete obj;
    }
}

void Sizer::add(Drawable *obj) {
    obj->setParent(this);
    this->objects.push_back(obj);
}

void Sizer::remove(unsigned int i) {
    if(i < this->objects.size()) {
        delete this->objects.at(i);
        this->objects.erase(this->objects.begin() + i);
    }
}

int Sizer::count() {
    return this->objects.size();
}
