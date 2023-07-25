#ifndef                             __KOALABOT_HPP__
    #define                         __KOALABOT_HPP__

#include <iostream>
#include <memory>
#include "test_Parts.hpp"

class                               KoalaBot
{
    public:
        KoalaBot(const std::string &serial = "Bob-01");
        ~KoalaBot(void);

        const Arms                  &getArms(void) const;
        const Legs                  &getLegs(void) const;
        const Head                  &getHead(void) const;
        const std::string           &getSerial(void) const;
    private:
        const std::string           _serial;
        const std::unique_ptr<Arms> _arms;
        const std::unique_ptr<Legs> _legs;
        const std::unique_ptr<Head> _head;
};
#endif //                       !__KOALABOT_HPP__