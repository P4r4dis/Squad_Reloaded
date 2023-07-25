#include "../test_include/test_Parts.hpp"

Arms::Arms(std::string const &serial, bool functional) :    _serial(serial),
                                                            _functional(functional)
{}

Arms::~Arms(void)
{}

bool        Arms::getFunctional(void)
{
    return _functional;
}

std::string &Arms::serial(void)
{
    return _serial;
}