#ifndef SIZER_H
#define SIZER_H

#include <vector>
#include "ulcdgui/misc/drawable.h"

class Sizer : public Drawable {
protected:
    std::vector<Drawable*> objects;

public:
    Sizer();
    virtual ~Sizer();

    void add(Drawable *obj);
    void remove(unsigned int i);
    int count();
};

#endif
