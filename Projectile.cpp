#include "Projectile.hpp"
#include "Window.hpp"

const point     PROJ_DIMS          = {12.f, 12.f};

const sf::Color PROJECTILE_FILL_COLOR    = sf::Color::Black;
const sf::Color PROJECTILE_OUTLINE_COLOR = sf::Color::White;
const float     PROJECTILE_OUTLINE_WIDTH = 1.2f;

Projectile::Projectile(point _position, point target, float vModule, float _dmg){
    velocity = target-_position;
    float vm = velocity.getModule();
    velocity *= vModule/vm;
    position = _position;
    shape = sf::RectangleShape({PROJ_DIMS.x, PROJ_DIMS.y});
    shape.setFillColor(PROJECTILE_FILL_COLOR);
    shape.setOutlineColor(PROJECTILE_OUTLINE_COLOR);
    shape.setOutlineThickness(PROJECTILE_OUTLINE_WIDTH);
    type = GameObjectType::projectile;
    dmg = _dmg;
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
