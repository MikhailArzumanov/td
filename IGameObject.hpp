#ifndef IGAMEOBJECT_HPP_INCLUDED
#define IGAMEOBJECT_HPP_INCLUDED
#include "IDrawable.hpp"
#include "RectShape.hpp"
#include "SFML/Window/Event.hpp"
#include <SFML/Graphics/Color.hpp>

enum class TriggerType;

class Game;

struct commonInitData{
    point position;
    point dims;
    commonInitData(point _position, point _dims){
        position = _position; dims = _dims;
    }
};

struct visualData{
    sf::Color fillClr;
    sf::Color outlineClr;
    float     outlineWdth;
    visualData(){}
    visualData(sf::Color _fillClr, sf::Color _outlineClr, float _outlineWdth){
        fillClr = _fillClr; outlineClr = _outlineClr; outlineWdth = _outlineWdth;
    }
};

enum GameObjectType{
    edifice,
    projectile,
    circle,
    cprj,
    trigger,
    count
};

class IGameObject : public IDrawable, public RectShape{
protected:
    Game* game;
    point          velocity = {0,0};
    bool           isAlive  = true;
    bool       mouseHovered = false;
    GameObjectType type     = count;

    virtual void onMouseLeft();
    virtual void onMouseEntered();
public:
    IGameObject(Game* _game){game = _game;}

    void kill();
    bool doesCollidesWith(IGameObject& another) const;
    virtual void collideWith(IGameObject& another) = 0;
    virtual void tick();

    virtual void onMouseMove(sf::Event event);
    virtual void onMouseClick(sf::Event event);


    point          getPosition() const;
    point          getVelocity() const;
    point          getDims()     const;
    bool           stillAlive()  const;
    GameObjectType getType()     const;
};

#endif // IGAMEOBJECT_HPP_INCLUDED
