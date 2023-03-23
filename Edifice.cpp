#include "Edifice.hpp"
#include "Game.hpp"
#include "Window.hpp"
#include "Projectile.hpp"

const point     PROJ_DIMS          = {3.f, 3.f};

const sf::Color PROJECTILE_FILL_COLOR    = sf::Color::Black;
const sf::Color PROJECTILE_OUTLINE_COLOR = sf::Color::White;
const float     PROJECTILE_OUTLINE_WIDTH = 1.2f;

Edifice::Edifice(Game* _game, visualData vData, edificeInitData data) : IGameObject(_game){
    position = data.position; dims = data.dims;
    velocity = {0, 0}; atkSpeed = data.atkSpeed;
    dmg = data.dmg; hp = data.hp; range = data.range;
    prjSpeed = data.prjSpeed;
    type = GameObjectType::edifice;
    shape = sf::RectangleShape({dims.x,dims.y});
    shape.setFillColor(vData.fillClr);
    shape.setOutlineColor(vData.outlineClr);
    shape.setOutlineThickness(vData.outlineWdth);
}
void Edifice::collideWith(IGameObject& another){

}
void Edifice::tick(){
    IGameObject::tick();
    if(reloadT > 0){
        reloadT -= 1.f;
        return;
    }
    IGameObject* res = nullptr;
    float resDist = 1e9f;
    for(IGameObject* obj : *game->getObjects()){
        if(obj->getType() == GameObjectType::circle){
            point d = obj->getPosition()-position;
            float curDist = d.getSqrModule();
            if(curDist < resDist){
                resDist = curDist;
                res = obj;
            }
        }
    }
    if(res){
        auto prjVData = visualData(PROJECTILE_FILL_COLOR, PROJECTILE_OUTLINE_COLOR, PROJECTILE_OUTLINE_WIDTH);
        auto target = res->getPosition()+res->getDims()/2;
        auto prjIData = projectileInitData(position+dims/2, PROJ_DIMS, target, prjSpeed, dmg);
        auto proj = new Projectile(game, prjVData, prjIData);
        game->pushGameObject(proj);
        reloadT = atkSpeed;
    }
}
void Edifice::draw(){
    shape.setPosition(position.x, position.y);
    window->draw(shape);
}
void Edifice::hit(float dmg){

}
