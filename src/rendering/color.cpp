#include "ulcdgui/rendering/color.h"
#include <ulcd_driver.h>

Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Color::Color(int r, int g, int b) {
    r = (r < 0) ? 0 : r;
    g = (g < 0) ? 0 : g;
    b = (b < 0) ? 0 : b;
    this->r = (r <= 0) ? 0.0 : (255/r);
    this->g = (g <= 0) ? 0.0 : (255/g);
    this->b = (b <= 0) ? 0.0 : (255/b);
}

Color::Color(double r, double g, double b) {
    r = (r < 0.0) ? 0.0 : r;
    g = (g < 0.0) ? 0.0 : g;
    b = (b < 0.0) ? 0.0 : b;
    this->r = (r > 1.0) ? 1.0 : r;
    this->g = (g > 1.0) ? 1.0 : g;
    this->b = (b > 1.0) ? 1.0 : b;
}

Color::Color(uint16_t c) {
    int _r = c >> 11;
    int _g = (c >> 5) & 0x3F;
    int _b = c & 0x1F;
    this->r = (_r > 0) ? 31/r : 0;
    this->g = (_g > 0) ? 63/g : 0;
    this->b = (_b > 0) ? 31/b : 0;
}

uint16_t Color::getNativeColor() {
    return alloc_color(this->r, this->g, this->b);
}
