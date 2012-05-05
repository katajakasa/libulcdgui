#ifndef OBJECT_H
#define OBJECT_H

#include <sigc++/trackable.h>

enum Alignment {
    ALIGN_VERTICAL = 0,
    ALIGN_HORIZONTAL,
    ALIGN_AUTO
};

class GuiObject  : public sigc::trackable {
public:
    bool refresh;
    GuiObject *parent;

    GuiObject();
    virtual ~GuiObject();

    virtual void setParent(GuiObject *parent);
    virtual void update();
};

#endif
