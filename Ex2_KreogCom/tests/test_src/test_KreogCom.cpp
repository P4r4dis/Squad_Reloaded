#include "../test_include/test_KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :  _x(x), _y(y), 
                                                m_serial(serial),
                                                _next(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom(void)
{}

void        KreogCom::ping(void)
{
    std::cout   << "KreogCom " << m_serial 
                << " currently at " << _x << " "
                << _y << std::endl;
}

KreogCom    *KreogCom::getCom(void)
{
    return _next;
}

void        KreogCom::addCom(int x, int y, int serial)
{
    // 1:   create a new KoreogCom
    KreogCom *newKreogCom = new KreogCom(x, y, serial);

    // 2:   Check if the current KreogCom is already linked to another KreogCom 
    //      (m_next is not nullptr).
    if (_next) //  If already linked, traverse the linked list to find the last KreogCom
    {
        //  3:  create a current pointer to assign to _next
        KreogCom *current = _next;
        while (current->_next != nullptr)
        {
            current = current->_next;
        }
        // 4:   assign the last to newKreogCom
        current->_next = newKreogCom;

    }
    else
    {
        //  If not linked, link to the newKreog;
        _next = newKreogCom;
    }
}