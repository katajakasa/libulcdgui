#ifndef COMPONENT_H
#define COMPONENT_H

#include "ulcdgui/misc/drawable.h"

class Component : public Drawable {
protected:
    void *user_data;

public:
    Component();

    // Components don't need this ...
    void precalc_layout(int x, int y) {}

    void setUserData(void *data);
    void* getUserData();
};

#endif
