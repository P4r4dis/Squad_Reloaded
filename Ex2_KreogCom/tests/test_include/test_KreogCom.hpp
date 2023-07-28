#ifndef                 __KREOGCOM_HPP__
    #define             __KREOGCOM_HPP__


#include <iostream>
#include <list>
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
        KreogCom        *_next;

};

#endif //              !__KREOGCOM_HPP__