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

        Arms                  &getArms(void) const;
        Legs                  &getLegs(void) const;
        Head                  &getHead(void) const;
        std::string           getSerial(void) const;

        void                        setPart(const Arms &arms,
                                            const Legs &legs,
                                            const Head &head);
        void                        swapParts(const Arms &arms);
        void                        swapParts(const Legs &legs);
        void                        swapParts(const Head &head);
    private:
        std::string           _serial;
        std::unique_ptr<Arms> _arms;
        std::unique_ptr<Legs> _legs;
        std::unique_ptr<Head> _head;
};
#endif //                       !__KOALABOT_HPP__