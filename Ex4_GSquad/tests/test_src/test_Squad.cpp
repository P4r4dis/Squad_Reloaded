#include "../test_include/test_Squad.hpp"

Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size)
    :   _posXBegin(posXBegin), _posYBegin(posYBegin), _ammoType(ammoType), 
        _size(size)
{}

Squad::~Squad(void)
{}

int                 Squad::getPosXBegin(void)
{
    return _posXBegin;
}

int                 Squad::getPosYBegin(void)
{
    return _posYBegin;
}

Phaser::AmmoType    Squad::getAmmoType(void)
{
    return _ammoType;
}

int                 Squad::getSize(void)
{
    return _size;
}

