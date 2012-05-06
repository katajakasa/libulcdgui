#ifndef FRAME_H
#define FRAME_H

#include "ulcdgui/lcddevice.h"
#include "ulcdgui/sizers/sizer.h"
#include "ulcdgui/components/component.h"
#include "ulcdgui/events/event.h"
#include "ulcdgui/misc/guiobject.h"

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
