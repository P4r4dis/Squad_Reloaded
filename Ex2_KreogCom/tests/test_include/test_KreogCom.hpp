#ifndef                 __KREOGCOM_HPP__
    #define             __KREOGCOM_HPP__


#include <iostream>

class                   KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        void            addCom(int x, int y, int serial);
        void            removeCom(void);
        KreogCom        *getCom(void);
        void            ping(void);
        void            locateSquad(void);
    private:
        int             _x;
        int             _y;
        const int       m_serial;
};

#endif //              !__KREOGCOM_HPP__