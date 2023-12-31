#ifndef                     __SKAT_HPP__
    #define                 __SKAT_HPP__

#include <iostream>

class                       Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat(void);

        int                 stimPaks(void);
        const std::string   &name(void);

        void                shareStimPaks(int number, int stock);
        void                addStimPaks(unsigned int number);
        void                useStimPaks(void);
        void                status(void);
    private:
        const std::string   _name;
        int                 _stimPaks;
};
#endif //             ! __SKAT_HPP__