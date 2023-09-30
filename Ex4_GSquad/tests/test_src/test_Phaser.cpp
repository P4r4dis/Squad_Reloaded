#include "../test_include/test_Phaser.hpp"

const int   Phaser::Empty = 0;
const std::string   Sounds::Regular = "Bang";
const std::string   Sounds::Plasma = "Fwooosh";
const std::string   Sounds::Rocket = "Booooooom";



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

void        Phaser::changeType(AmmoType newType)
{
    _type = newType;
    switch (_type)
    {
        case 0:
            std::cout << "Switching ammo to type: regular" << std::endl;
            break;
        case 1:
            std::cout << "Switching ammo to type: plasma" << std::endl;
            break;
        case 2:
            std::cout << "Switching ammo to type: rocket" << std::endl;
            break;
        default:
            break;
    }
}

Phaser::AmmoType    Phaser::getAmmoType(void) const
{
    return _type;
}

void                Phaser::reload(void)
{
    ejectClip();
    _currentAmmo = _maxAmmo;
    for (int i = 0; i < _maxAmmo; i++)
        _magazine.push_back(_type);
    std::cout << "Reloading..." << std::endl; 
}

size_t              Phaser::getMagazine(void) const
{
    return _magazine.size();
}

void                Phaser::addAmmo(AmmoType type)
{
    if (_currentAmmo == _maxAmmo)
        std::cout << "Clip full" << std::endl;
    else
    {
        _magazine.push_back(type);
        _currentAmmo++;
    }
}