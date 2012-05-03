#ifndef FRAME_H
#define FRAME_H

#include "lcddevice.h"
#include "sizers/sizer.h"
#include "components/component.h"
#include "events/event.h"
#include "guiobject.h"

class Frame : public GuiObject {
protected:
    LCDDevice *device;
    Sizer *base_sizer;

public:
    Frame(LCDDevice *dev);
    virtual ~Frame();

    void run();
    void setBaseSizer(Sizer *sizer);
    void update();
};

#endif
