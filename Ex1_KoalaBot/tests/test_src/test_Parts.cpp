#include "../test_include/test_Parts.hpp"
#include <iomanip>

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
    std::cout   << std::setw(18) << "[Parts] Arms " << _serial 
                << " status : "
                << (isFunctional() ? "OK" : "KO") << std::endl; 
}

Legs::Legs(std::string const &serial, bool functional) :    _serial(serial),
                                                            _functional(functional)
{}

Legs::~Legs(void)
{}

std::string &Legs::serial(void)
{
    return _serial;
}

bool        Legs::isFunctional(void)
{
    return _functional;
}

void        Legs::informations(void)
{
    std::cout   << std::setw(18) << "[Parts] Legs " << _serial 
                << " status : "
                << (isFunctional() ? "OK" : "KO") << std::endl; 
}

Head::Head(std::string const &serial, bool functional) :    _serial(serial),
                                                            _functional(functional)
{}

Head::~Head(void)
{}

std::string &Head::serial(void)
{
    return _serial;
}

bool        Head::isFunctional(void)
{
    return _functional;
}

void        Head::informations(void)
{
    std::cout   << std::setw(18) << "[Parts] Head " << _serial 
                << " status : "
                << (isFunctional() ? "OK" : "KO") << std::endl; 
}