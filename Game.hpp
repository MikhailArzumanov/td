#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Circle.hpp"
#include "Projectile.hpp"
#include <list>
#include <SFML/System/Clock.hpp>

class Game{
private:
    std::list<IGameObject*> objects;
    sf::Clock theClock;

    void collide();
    void lifeCheck();
    void tick();
    void draw();

    void handleEvents();
    void processMbPressed(sf::Event event);
    void processMouseMoved(sf::Event event);
    void processKeyPressed(sf::Event event);

public:
    Game();

    std::list<IGameObject*>* getObjects(){return &objects;}

    void pushGameObject(IGameObject* obj){objects.push_back(obj);}

    void init();
    void encycle();
    void clear();
};

#endif // GAME_HPP_INCLUDED
