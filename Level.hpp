#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

class Game;

enum class LevelsEnum{
    First,
    count
};

class Level{
protected:
    Game* game;
    LevelsEnum level = LevelsEnum::count;
public:
    Level(Game* _game){game = _game;}
    virtual void init() = 0;
    virtual void tick() = 0;
    LevelsEnum getNum(){return level;}
};

#endif // LEVEL_HPP_INCLUDED
