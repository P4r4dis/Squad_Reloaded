#ifndef                         __SKAT_HPP__
    #define                     __SKAT_HPP__

#include <iostream>
#include "test_Phaser.hpp"
#include "test_KreogCom.hpp"

class                           Skat
{
    public:
        Skat(const std::string &name, int stimPaks, int serial, 
                int x, int y, Phaser::AmmoType type);
        ~Skat(void);

        const std::string       getName(void);
        int                     getStimPaks(void);
        int                     getSerial(void);
        int                     getPosX(void);
        int                     getPosY(void);
        Phaser::AmmoType        getAmmoType(void);
        Phaser                  *getPhaser(void);
        KreogCom                *getKreogCom(void);

        void                    fire(void);
        void                    locate(void);
        void                    reload(void);
    private:
        const std::string       _name;
        int                     _stimPaks;
        int                     _serial;
        int                     _x;
        int                     _y;
        Phaser::AmmoType        _type;
        Phaser                  *_phaser;
        KreogCom                *_kreogCom;

};

#endif //           !__SKAT_HPP__