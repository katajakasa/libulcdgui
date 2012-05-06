#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class GuiException {
protected:
    std::string errortext;

public:
    GuiException(std::string text) { this->errortext = text; }
    std::string getText() { return this->errortext; }
};

#endif
