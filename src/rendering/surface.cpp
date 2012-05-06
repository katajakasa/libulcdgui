#include "ulcdgui/rendering/surface.h"
#include "ulcdgui/misc/guiexception.h"
#include <ulcd_driver.h>
#include <cstring>
#include <cstdio>

Surface::Surface(ulcd_dev *dev) {
    this->dev = dev;
    this->w = dev->w;
    this->h = dev->h;
    this->x = 0;
    this->y = 0;
}

Surface::Surface(ulcd_dev *dev, int x, int y, int w, int h) {
    this->dev = dev;
    x = (x > dev->w) ? dev->w : x;
    y = (y > dev->h) ? dev->h : y;
    this->w = (w+x > dev->w) ? dev->w - x : w;
    this->h = (h+y > dev->h) ? dev->h - y : h;
    this->x = x;
    this->y = y;
}

Surface* Surface::getSubSurface(int x, int y, int w, int h) {
    return new Surface(this->dev, this->x + x, this->y + y, w, h);
}

void Surface::pixel(int x, int y) {
    if(!ulcd_draw_pixel(this->dev, this->x+x, this->y+y, this->c.getNativeColor())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::ellipse(int x, int y, int xrad, int yrad) {
    if(!ulcd_draw_ellipse(this->dev, this->x+x, this->y+y, xrad, yrad, this->c.getNativeColor())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::line(int x0, int y0, int x1, int y1) {
    if(!ulcd_draw_line(this->dev, this->x+x0, this->y+y0, this->x+x1, this->y+y1, this->c.getNativeColor())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::rect(int x0, int y0, int x1, int y1) {
    if(!ulcd_draw_rect(this->dev, this->x+x0, this->y+y0, this->x+x1, this->y+y1, this->c.getNativeColor())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::circle(int x, int y, int radius) {
    if(!ulcd_draw_circle(this->dev, this->x+x, this->y+y, radius, this->c.getNativeColor())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::blit(int x, int y, int w, int h, const char *data) {
    if(!ulcd_blit(this->dev, this->x+x, this->y+y, w, h, data)) {
        throw GuiException(ulcd_get_error_str());
    }
}

Color Surface::getPixel(int x, int y) {
    return Color(ulcd_read_pixel(this->dev, x, y));
}

void Surface::text(std::string text, int x, int y, int font) {
    if(!ulcd_draw_text(this->dev, text.c_str(), this->x+x, this->y+y, font, this->c.getNativeColor())) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::setPen(PenType p) {
    if(!ulcd_pen_style(this->dev, p)) {
        throw GuiException(ulcd_get_error_str());
    }
}

void Surface::setColor(Color c) {
    this->c = c;
}
