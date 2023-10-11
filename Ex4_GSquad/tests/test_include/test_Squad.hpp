#ifndef                         __SQUAD_HPP__
    #define                     __SQUAD_HPP__

#include <iostream>
#include "test_Phaser.hpp"
#include "test_Skat.hpp"

class                           Squad
{
    public:
        Squad(int posXBegin = 0, int posYBegin = 0,
                Phaser::AmmoType ammoType = Phaser::REGULAR, int size = 5);
        ~Squad(void);

        void                    fire(void);
        void                    localisation(void);
        int                     size(void);
        Skat                    **skats(void);
        Skat                    *at(int idx);
        void                    foreach(int beginIdx, void (Skat::*actionPtr)());


        int                     getPosXBegin(void);
        int                     getPosYBegin(void);
        Phaser::AmmoType        getAmmoType(void);
        int                     getSize(void);
    private:
        int                     _posXBegin;
        int                     _posYBegin;
        Phaser::AmmoType        _ammoType;
        int                     _size;
        Skat                    **_skat;
};

#endif //           !__SQUAD_HPP__