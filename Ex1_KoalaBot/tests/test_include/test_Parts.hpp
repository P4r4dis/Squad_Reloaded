#ifndef                     __PARTS_HPP__
    #define                 __PARTS_HPP__

#include <iostream>


class                       Arms
{
    public:
        Arms(std::string const &serial = "A-01", bool functional = true);
        ~Arms(void);

        std::string         &serial(void);
        bool                isFunctional(void);
        void                informations(void);
    private:
        std::string         _serial;
        bool                _functional;
};
class                       Legs
{
    public:
        Legs(std::string const &serial = "L-01", bool functional = true);
        ~Legs(void);

        std::string         &serial(void);
        bool                isFunctional(void);
        void                informations(void);
    private:
        std::string         _serial;
        bool                _functional;
};


#endif //                  !__PARTS_HPP__