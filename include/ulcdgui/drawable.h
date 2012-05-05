#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "ulcdgui/guiobject.h"

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
    unsigned int min_w, min_h;
    unsigned int max_w, max_h;
    Alignment align;
    Expansiveness exp;
    unsigned int margin;

public:
    Drawable() : GuiObject() {
        min_w = max_w = 0;
        min_h = max_h = 0;
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
    void setMinimumSize(unsigned int w, unsigned int h) { this->min_w = w; this->min_h = w; }
    void setMaximumSize(unsigned int w, unsigned int h) { this->max_w = w; this->max_h = h; }
    unsigned int getMargin() { return this->margin; }
    Alignment getAlignment() { return this->align; }
    Expansiveness getExpansiveness() { return this->exp; }
    unsigned int getMinW() { return this->min_w; }
    unsigned int getMinH() { return this->min_h; }
    unsigned int getMaxW() { return this->max_w; }
    unsigned int getMaxH() { return this->max_h; }
};

#endif
