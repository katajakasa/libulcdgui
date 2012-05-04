#ifndef SIZER_H
#define SIZER_H

#include <vector>
#include "ulcdgui/drawable.h"

class Sizer : public Drawable {
protected:
    std::vector<Drawable*> objects;
    int last_w, last_h;

public:
    Sizer();
    virtual ~Sizer();

    void addComponent(Drawable *obj);
};

#endif
