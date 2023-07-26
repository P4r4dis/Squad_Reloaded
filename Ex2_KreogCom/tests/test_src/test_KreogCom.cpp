#include "../test_include/test_KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :  _x(x), _y(y), m_serial(serial)
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

