#include "Circle.hpp"
#include "Projectile.hpp"
#include "Window.hpp"



Circle::Circle(Game* _game, commonInitData data, visualData vData, float _hp):IGameObject(_game){
    position = data.position; dims = data.dims; hp = _hp;
    shape = sf::CircleShape(dims.x/2.f, 12.f);
    shape.setFillColor(vData.fillClr);
    shape.setOutlineColor(vData.outlineClr);
    shape.setOutlineThickness(vData.outlineWdth);
    type = GameObjectType::circle;
}
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
    }
}

void Circle::tick(){
    if(hp <= 0) isAlive = false;
}

void Circle::draw(){
    shape.setPosition({position.x, position.y});
    window->draw(shape);
}
