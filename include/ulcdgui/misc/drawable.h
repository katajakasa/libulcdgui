#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "ulcdgui/misc/guiobject.h"
#include <climits>

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
    unsigned int w, h;
    Alignment align;
    Expansiveness exp;
    unsigned int margin;

public:
    Drawable() : GuiObject() {
        w = h = 0;
        min_w = min_h = 0;
        max_w = max_h = INT_MAX;
        align = ALIGN_AUTO;
        exp = EXPAND_ALL;
        margin = 2;
    }

    virtual void draw(Surface *s) = 0;
    virtual void handle_event(GuiEvent *ev) = 0;
    virtual void precalc_layout(int x, int y) = 0;

    // TODO: IMPLEMENT THESE IN COMPONENTS/SIZERS!
    void setMargin(unsigned int margin) { this->margin = margin; }
    void setAlignment(Alignment align) { this->align = align; }
    void setExpansiveness(Expansiveness exp) { this->exp = exp; }
    void setMinSize(unsigned int w, unsigned int h) { this->min_w = w; this->min_h = w; }
    void setMaxSize(unsigned int w, unsigned int h) { this->max_w = w; this->max_h = h; }
    void setSize(unsigned int w, unsigned int h) { this->w = w; this->h = h; }
    unsigned int getMargin() { return this->margin; }
    Alignment getAlignment() { return this->align; }
    Expansiveness getExpansiveness() { return this->exp; }
    unsigned int getMinW() { return this->min_w; }
    unsigned int getMinH() { return this->min_h; }
    unsigned int getMaxW() { return this->max_w; }
    unsigned int getMaxH() { return this->max_h; }
    unsigned int getW() { return this->w; }
    unsigned int getH() { return this->h; }
};

#endif
