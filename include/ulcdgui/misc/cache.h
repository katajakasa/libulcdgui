#ifndef CACHE_H
#define CACHE_H

#include <map>
#include <string>

class Cache {
protected:
    static unsigned int id;
    static std::map<int,std::string> cachefiles;
    static unsigned int getId();
    static bool enabled;

public:
    static void init();
    static void clean();
    static unsigned int cachearea(int x, int y, int w, int h);
};

#endif // CACHE_H
