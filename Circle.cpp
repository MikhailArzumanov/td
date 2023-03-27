#include "Circle.hpp"
#include "Projectile.hpp"
#include "Window.hpp"
#include "Trigger.hpp"

Circle::Circle(Game* _game, commonInitData data, const visualData vData, float _hp, float _dmg):IGameObject(_game){
    position = data.position; dims = data.dims;
    hp = _hp; dmg = _dmg;
    shape = sf::CircleShape(dims.x/2.f, 12.f);
    shape.setFillColor(vData.fillClr);
    shape.setOutlineColor(vData.outlineClr);
    shape.setOutlineThickness(vData.outlineWdth);
    type = GameObjectType::circle;
}

void Circle::onTriggerred(TriggerType type){}

void Circle::collideWith(IGameObject& another){
    switch(another.getType()){
    case GameObjectType::circle:
    case GameObjectType::cprj:
    default:
        break;
    case GameObjectType::projectile:
        hp -= ((Projectile*)&another)->getDmg();
        break;
    case GameObjectType::edifice:
        hp = 0;
        break;
    case GameObjectType::trigger:
        onTriggerred(((Trigger*)&another)->getTriggerType());
        break;
    }
}

void Circle::tick(){
    IGameObject::tick();
    if(hp <= 0) isAlive = false;
}

void Circle::draw(){
    shape.setPosition({position.x, position.y});
    window->draw(shape);
}
