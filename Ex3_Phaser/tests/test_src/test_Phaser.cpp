#include "../test_include/test_Phaser.hpp"

const int   Phaser::Empty = 0;
const std::string   Sounds::Regular = "Bang";
const std::string   Sounds::Plasma = "Fwooosh";
const std::string   Sounds::Rocket = "Boouuuuuum";



Phaser::Phaser(int maxAmmo, AmmoType type) :    _maxAmmo(maxAmmo),
                                                _currentAmmo(maxAmmo),
                                                _type(type)
{}

Phaser::~Phaser(void)
{}

int         Phaser::getCurrentAmmos(void) const
{
    return _currentAmmo;
}