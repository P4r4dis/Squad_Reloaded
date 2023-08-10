#include "../test_include/test_Phaser.hpp"

const int   Phaser::Empty = 0;
const std::string   Sounds::Regular = "Bang";
const std::string   Sounds::Plasma = "Fwooosh";
const std::string   Sounds::Rocket = "Boouuuuuum";



Phaser::Phaser(int maxAmmo, AmmoType type) :    _maxAmmo(maxAmmo),
                                                _currentAmmo(maxAmmo),
                                                _type(type)
{
    for (int i = 0; i < _maxAmmo; i++)
        _magazine.push_back(_type);
}

Phaser::~Phaser(void)
{}

int         Phaser::getCurrentAmmos(void) const
{
    return _currentAmmo;
}

void        Phaser::fire(void)
{
    if (_magazine.size() == Empty)
        std::cout << "Clip empty, please reload" << std::endl;
    else
    {
        _magazine.pop_back();
        _currentAmmo -= 1;
        switch (_type)
        {
            case 0:
                std::cout << Sounds::Regular << std::endl;
                break;
            case 1:
                std::cout << Sounds::Plasma << std::endl;
                break;
            case 2:
                std::cout << Sounds::Rocket << std::endl;
                break;
            default:
                break;
        }
    }
}

void        Phaser::ejectClip(void)
{
    _magazine.clear();
    _currentAmmo = Empty;
}