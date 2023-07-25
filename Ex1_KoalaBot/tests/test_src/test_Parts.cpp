#include "../test_include/test_Parts.hpp"

Arms::Arms(std::string const &serial, bool functional) :    _serial(serial),
                                                            _functional(functional)
{}

Arms::~Arms(void)
{}

std::string &Arms::serial(void)
{
    return _serial;
}

bool        Arms::isFunctional(void)
{
    return _functional;
}

void        Arms::informations(void)
{
    std::cout   << "[Parts] Arms " << _serial << " status : "
                << (isFunctional() ? "OK" : "KO") << std::endl; 
}