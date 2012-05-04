#ifndef COMPONENT_H
#define COMPONENT_H

#include "ulcdgui/drawable.h"

class Component : public Drawable {
protected:
    void *user_data;

public:
    Component();

    void setUserData(void *data);
    void* getUserData();
};

#endif
