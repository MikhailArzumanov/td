#include "IGameObject.hpp"
#include "Trigger.hpp"

void IGameObject::onMouseLeft()    {}
void IGameObject::onMouseEntered() {}

void IGameObject::onMouseMove(sf::Event event) {
    point p = {event.mouseMove.x, event.mouseMove.y};
    if(contains(p) ^ mouseHovered){
        if(mouseHovered) onMouseLeft();
        else onMouseEntered();
        mouseHovered = !mouseHovered;
    }
}

void IGameObject::onMouseClick(sf::Event event){}
