#ifndef OBJECT_H
#define OBJECT_H

enum ObjectType {
    OBJECT_COMPONENT,
    OBJECT_SIZER,
    OBJECT_FRAME,
};

class GuiObject {
public:
    GuiObject *parent;
    ObjectType type;

    GuiObject(ObjectType t);
    virtual ~GuiObject();

    virtual void setParent(GuiObject *parent);
    virtual void update();
};

#endif
