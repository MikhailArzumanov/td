#include "Edifice.hpp"
#include "Game.hpp"
#include "Window.hpp"
#include "Projectile.hpp"

const point     PROJ_DIMS          = {3.f, 3.f};

const sf::Color PROJECTILE_FILL_COLOR    = sf::Color::Black;
const sf::Color PROJECTILE_OUTLINE_COLOR = sf::Color::White;
const float     PROJECTILE_OUTLINE_WIDTH = 1.2f;

Edifice::Edifice(Game* _game, visualData _vData, edificeInitData data, int _mxLevel) : IGameObject(_game){
    position = data.position; dims = data.dims;
    velocity = {0, 0}; atkSpeed = data.atkSpeed;
    dmg = data.dmg; hp = data.hp; range = data.range;
    prjSpeed = data.prjSpeed; mxLevel = _mxLevel;
    type = GameObjectType::edifice; vData = _vData;
    shape = sf::RectangleShape({dims.x,dims.y});
    shape.setFillColor(vData.fillClr);
    shape.setOutlineColor(vData.outlineClr);
    shape.setOutlineThickness(vData.outlineWdth);
    initCross();
}

void Edifice::initCross(){
    float vCrossW = dims.x/7, vCrossH = dims.y - 2*vData.outlineWdth - 7,
        vCrossX = position.x+dims.x/2-vCrossW/2, vCrossY = position.y + vData.outlineWdth + 3.4;
    float hCrossH = dims.y/7, hCrossW = dims.x - 2*vData.outlineWdth - 7,
        hCrossY = position.y+dims.y/2-hCrossH/2, hCrossX = position.x + vData.outlineWdth + 3.4;

    crossH = sf::RectangleShape({hCrossW, hCrossH});
    crossH.setPosition(hCrossX, hCrossY);
    crossV = sf::RectangleShape({vCrossW, vCrossH});
    crossV.setPosition(vCrossX, vCrossY);
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
    float resSqrDist = 1e9f;
    for(IGameObject* obj : *game->getObjects()){
        if(obj->getType() == GameObjectType::circle){
            point d = obj->getPosition()-position;
            float curSqrDist = d.getSqrModule();
            if(curSqrDist < resSqrDist){
                resSqrDist = curSqrDist;
                res = obj;
            }
        }
    }
    float sqrRange = range*range;
    if(res){
        if(resSqrDist > sqrRange){
            return;
        }
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
    window->draw(crossH);
    window->draw(crossV);
}
void Edifice::hit(float dmg){

}

void Edifice::upgrade(){
    //...
}
