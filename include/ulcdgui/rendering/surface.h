#ifndef SURFACE_H
#define SURFACE_H

#include <list>
#include <string>
#include <ulcd_driver.h>
#include "ulcdgui/rendering/color.h"

enum PenType {
    PEN_SOLID = 0x00,
    PEN_WIREFRAME = 0x01,
};

class Surface {
protected:
    ulcd_dev *dev;
    Color c;
    int x,y;

public:
    int w,h;

    Surface(ulcd_dev *dev);
    Surface(ulcd_dev *dev, int x, int y, int w, int h);

    void pixel(int x, int y);
    void line(int x0, int y0, int x1, int y1);
    void rect(int x0, int y0, int x1, int y1);
    void circle(int x, int y, int radius);
    void blit(int x, int y, int w, int h, char *data);
    void text(std::string text, int x, int y, int font);
    void setPen(PenType p);
    void setColor(Color c);

    Surface* getSubSurface(int x, int y, int w, int h);
};

#endif