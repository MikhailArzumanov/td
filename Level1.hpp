#ifndef LEVEL1_HPP_INCLUDED
#define LEVEL1_HPP_INCLUDED
#include "Level.hpp"

class Level1 : public Level{
public:
    Level1(Game* game);
    void init();
    void tick();
};


#endif // LEVEL1_HPP_INCLUDED
