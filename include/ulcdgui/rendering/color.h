#ifndef COLOR_H
#define COLOR_H

#include <cinttypes>

class Color {
    friend class Surface;

protected:
    float r,g,b;
    uint16_t getNativeColor();

public:
    Color();
    Color(int r, int g, int b);
    Color(double r, double g, double b);
    Color(uint16_t c);

    float getR() { return this->r; }
    float getG() { return this->g; }
    float getB() { return this->b; }
};

#endif
