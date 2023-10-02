#include "../test_include/test_Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks,
            int serial, int x, int y, Phaser::AmmoType type) :  _name(name),
                                                                _stimPaks(stimPaks),
                                                                _serial(serial),
                                                                _x(x), _y(y), _type(type),
                                                                _phaser(new Phaser(_stimPaks, type)),
                                                                _kreogCom(new KreogCom(_x, _y, _serial))
{}

Skat::~Skat(void)
{
    if (_kreogCom != nullptr)
        delete _kreogCom;
    else if (_phaser != nullptr)
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
    return _kreogCom;
}

void                Skat::fire(void)
{
    _phaser->fire();
}

void                Skat::locate(void)
{
    _kreogCom->ping();
}

void                Skat::reload(void)
{
    _phaser->reload();
}