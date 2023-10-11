#include "../test_include/test_Squad.hpp"

Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size)
    :   _posXBegin(posXBegin), _posYBegin(posYBegin), _ammoType(ammoType), 
        _size(size), _skat(new Skat *[_size])
{
    for (int i = 0; i < _size; ++i) {
        _skat[i] = new Skat(std::to_string(i), 20, i, _posXBegin + i * 10, _posYBegin + i * 15, _ammoType);
    }
}

Squad::~Squad(void)
{
    for (int i = 0; i < _size; i++)
    {
        delete _skat[i];
    }
}

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


void                Squad::foreach(int beginIdx, void (Skat::*actionPtr)())
{
    for(int i = beginIdx; i < _size; i++)
    {
        (*_skat[i].*actionPtr)();
    }
}


void                Squad::fire()
{
    foreach(0, &Skat::fire);
}

void                Squad::localisation(void)
{
    foreach(0, &Skat::locate);
}