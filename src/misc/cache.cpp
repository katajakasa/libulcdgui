#include "ulcdgui/misc/cache.h"
#include <ulcd_driver.h>
#include <sstream>

void Cache::init(LCDDevice *dev) {
    if(!Cache::enabled) {
        Cache::id = 0;
        Cache::enabled = true;
    }
}

void Cache::clean() {

}

unsigned int Cache::getId() {
    return Cache::id++;
}

unsigned int cachearea(int x, int y, int w, int h) {
    std::ostringstream o;
    o << Cache::getId() << ".gcf";
}
