#include "Circle.hpp"
#include "Projectile.hpp"
#include "Window.hpp"


const point     CRCL_DIMS          = {34.f, 34.f};

const sf::Color CIRCLE_FILL_COLOR    = sf::Color::Black;
const sf::Color CIRCLE_OUTLINE_COLOR = sf::Color::White;
const float     CIRCLE_OUTLINE_WIDTH = 1.2f;

Circle::Circle(point _position){
    position = _position;
    velocity = {0,0};
    dims = CRCL_DIMS;
    hp = 12;
    shape = sf::CircleShape(CRCL_DIMS.x/2.f, 12);
    shape.setFillColor(CIRCLE_FILL_COLOR);
    shape.setOutlineColor(CIRCLE_OUTLINE_COLOR);
    shape.setOutlineThickness(CIRCLE_OUTLINE_WIDTH);
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
