#include "../test_include/test_Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks,
            int serial, int x, int y, Phaser::AmmoType type) :  _name(name),
                                                                _stimPaks(stimPaks),
                                                                _serial(serial),
                                                                _x(x), _y(y), _type(type),
                                                                _phaser(new Phaser(20, Phaser::REGULAR)),
                                                                _Com(new KreogCom(_x, _y, _serial))//_Com(nullptr)//_kreogCom(new KreogCom(_x, _y, _serial))
{} 

Skat::~Skat(void)
{
    if (_Com)
        delete _Com;
    if (_phaser)
        delete _phaser;
}

const std::string   Skat::getName(void)
{
    return _name;
}

int                 Skat::getStimPaks(void)
{
    return _stimPaks;
}

int                 Skat::getSerial(void)
{
    return _serial;
}

int                 Skat::getPosX(void)
{
    return _x;
}

int                 Skat::getPosY(void)
{
    return _y;
}

Phaser::AmmoType    Skat::getAmmoType(void)
{
    return _type;
}

Phaser              *Skat::getPhaser(void)
{
    return _phaser;
}

KreogCom            *Skat::getKreogCom(void)
{
    return _Com;
}

void                Skat::fire(void)
{
    _phaser->fire();
}

void                Skat::locate(void)
{
    _Com->ping();
}

void                Skat::reload(void)
{
    _phaser->reload();
}

KreogCom            &Skat::com(void)
{
    return *_Com;
}

// void                Skat::addCom(KreogCom *com)
// {
//     // com->addCom(com->getX(), com->getY(), com->getSerial());
//     _Com->addCom(com);
// }