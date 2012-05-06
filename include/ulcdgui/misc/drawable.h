#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "ulcdgui/misc/guiobject.h"

class Surface;
class GuiEvent;

enum Alignment {
    ALIGN_VERTICAL = 0,
    ALIGN_HORIZONTAL,
    ALIGN_AUTO
};

enum Expansiveness {
    EXPAND_NONE = 0x00,
    EXPAND_HORIZONTAL,
    EXPAND_VERTICAL,
    EXPAND_ALL,
};

class Drawable : public GuiObject {
    friend class Component;
    friend class Sizer;

protected:
    int min_w, min_h;
    int max_w, max_h;
    int w, h;
    Alignment align;
    Expansiveness exp;
    unsigned int margin;

public:
    Drawable() : GuiObject() {
        w = h = -1;
        min_w = max_w = -1;
        min_h = max_h = -1;
        align = ALIGN_AUTO;
        exp = EXPAND_ALL;
        margin = 2;
    }

    virtual void draw(Surface *s) = 0;
    virtual void handle_event(GuiEvent *ev) = 0;

    // TODO: IMPLEMENT THESE IN COMPONENTS/SIZERS!
    void setMargin(unsigned int margin) { this->margin = margin; }
    void setAlignment(Alignment align) { this->align = align; }
    void setExpansiveness(Expansiveness exp) { this->exp = exp; }
    void setMinimumSize(int w, int h) { this->min_w = w; this->min_h = w; }
    void setMaximumSize(int w, int h) { this->max_w = w; this->max_h = h; }
    unsigned int getMargin() { return this->margin; }
    Alignment getAlignment() { return this->align; }
    Expansiveness getExpansiveness() { return this->exp; }
    int getMinW() { return this->min_w; }
    int getMinH() { return this->min_h; }
    int getMaxW() { return this->max_w; }
    int getMaxH() { return this->max_h; }
    int getW() { return this->w; }
    int getH() { return this->h; }
};

#endif
