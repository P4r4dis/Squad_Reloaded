#ifndef                         __PHASER_HPP__
    #define                     __PHASER_HPP__

#include "Sounds.hpp"
#include <iostream>
#include <vector>
class                           Phaser
{
    public:
        enum                    AmmoType
        {
            REGULAR = 0,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser(void);

        void                    fire(void);
        void                    ejectClip(void);
        void                    changeType(AmmoType newType);
        void                    reload(void);
        void                    addAmmo(AmmoType type);

        int                     getCurrentAmmos(void) const;
        AmmoType                getAmmoType(void) const;
        size_t                  getMagazine(void) const;

    private:
        static const int        Empty; // 0
        int                     _maxAmmo; // maxammo
        int                     _currentAmmo;
        AmmoType                _type;
        std::vector<AmmoType>   _magazine;


};

#endif  //                      !__PHASER_HPP__