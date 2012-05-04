#include "ulcdgui/components/component.h"

Component::Component() : Drawable() {}

void Component::setUserData(void *data) {
    this->user_data = data;
}

void* Component::getUserData() {
    return this->user_data;
}
