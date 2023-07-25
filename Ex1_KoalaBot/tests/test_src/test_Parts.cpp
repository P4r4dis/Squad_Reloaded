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