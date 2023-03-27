#include "Trigger.hpp"
#include "Window.hpp"

Trigger::Trigger(Game* _game, commonInitData data, TriggerType _type)
    :IGameObject(_game){
    dims = data.dims; position = data.position;
    tType = _type; type = GameObjectType::trigger;
    shape = sf::RectangleShape({dims.x, dims.y});
}

void Trigger::draw(){
    if(!debugMode) return;
    shape.setPosition({position.x, position.y});
    window->draw(shape);
}
