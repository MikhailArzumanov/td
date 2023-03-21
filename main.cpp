#include "Window.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include "Projectile.hpp"
#include <list>
#include "Circle.hpp"

int main(){
    window.initWindow("Example", 1200, 700);
    auto proj = Projectile({100, 100}, {0,0}, 1, 12);
    auto crcl = Circle({0,0});
    std::list<IGameObject*> objects;
    objects.push_back(&proj);
    objects.push_back(&crcl);
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                proj.kill();
                break;
            }
        }
        for(auto obj : objects)
            obj->tick();

        for(auto obj = objects.begin(); obj != objects.end();)
            if(!(*obj)->stillAlive()){
                auto tmp = obj;
                obj++;
                objects.erase(tmp);
            }
            else obj++;

        for(auto objL = objects.begin(); objL != objects.end(); objL++)
        for(auto objR = objL;            objR != objects.end(); objR++)
            if(objL != objR && (*objL)->doesCollidesWith(**objR)){
                (*objL)->collideWith(**objR);
                (*objR)->collideWith(**objL);
            }

        window->clear();
        for(auto obj : objects)
            obj->draw();
        window->display();
    }
    return 0;
}
