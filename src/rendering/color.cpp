#include "ulcdgui/rendering/color.h"
#include <ulcd_driver.h>

Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Color::Color(int r, int g, int b) {
    this->r = (r <= 0) ? 0.0 : (255/r);
    this->g = (g <= 0) ? 0.0 : (255/g);
    this->b = (b <= 0) ? 0.0 : (255/b);
}

Color::Color(float r, float g, float b) {
    this->r = (r > 1.0) ? 1.0 : r;
    this->g = (g > 1.0) ? 1.0 : g;
    this->b = (b > 1.0) ? 1.0 : b;
}

uint16_t Color::getNativeColor() {
    return alloc_color(this->r, this->g, this->b);
}
