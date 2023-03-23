#include "Projectile.hpp"
#include "Window.hpp"


Projectile::Projectile(Game* _game, visualData vData, projectileInitData data)
        :IGameObject(_game){
    position = data.position;
    velocity = data.target-position;
    float vm = velocity.getModule();
    velocity *= data.vModule/vm;
    dims = data.dims; dmg = data.dmg;
    shape = sf::RectangleShape({dims.x, dims.y});
    shape.setFillColor(vData.fillClr);
    shape.setOutlineColor(vData.outlineClr);
    shape.setOutlineThickness(vData.outlineWdth);
    type = GameObjectType::projectile;
}

void Projectile::draw(){
    shape.setPosition({position.x, position.y});
    window->draw(shape);
}

void Projectile::collideWith(IGameObject& another){
    switch(another.getType()){
    case GameObjectType::projectile:
    case GameObjectType::edifice:
    case GameObjectType::cprj:
    default:
        break;
    case GameObjectType::circle:
        isAlive = false;
        break;
    }
}

float Projectile::getDmg() const { return dmg; }
