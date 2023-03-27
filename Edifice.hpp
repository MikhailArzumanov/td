#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "IGameObject.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

struct edificeInitData : public commonInitData{
    float atkSpeed, range, dmg, hp, prjSpeed;
    edificeInitData(point _position, point _dims, float _atkSpeed, float _range, float _dmg, float _hp, float _prjSpeed): commonInitData(_position, _dims){
        atkSpeed = _atkSpeed; range = _range; dmg = _dmg; hp = _hp; prjSpeed = _prjSpeed;
    }
};

enum class EdificeType {
    L1,
    count
};

class Edifice : public IGameObject{
protected:
    visualData vData;
    sf::RectangleShape shape;
    sf::RectangleShape crossV, crossH;

    void initCross();

    int gradeLevel = 0;
    int mxLevel    = 0;

    EdificeType eType = EdificeType::count;

    float atkSpeed = 1000.0f;
    float range    = 100.f;
    float dmg      = 0.1f;
    float hp       = 100.f;
    float prjSpeed = 1.0f;

    float reloadT  = 0.f;
public:
    Edifice(Game* _game, visualData _vData, edificeInitData data, int _mxLevel);
    virtual void collideWith(IGameObject& another);
    virtual void tick();
    virtual void draw();

    virtual void upgrade();
    virtual void hit(float dmg);
};


#endif // SQUARE_HPP_INCLUDED
