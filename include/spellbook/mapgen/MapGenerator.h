#ifndef MapGenerator_h
#define MapGenerator_h

#include <spellbook/grid/Grid.h>

typedef au::Grid<2, char> Map;

class MapGenerator
{
public:

    virtual ~MapGenerator() { }

    virtual void generate(Map& map) = 0;

private:
};

#endif

