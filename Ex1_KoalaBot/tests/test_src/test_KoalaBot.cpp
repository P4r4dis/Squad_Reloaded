#include "../test_include/test_KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string &serial) : _serial(serial),
                                                _arms(nullptr),
                                                _legs(nullptr),
                                                _head(nullptr)

{}

KoalaBot::~KoalaBot(void)
{}

const Arms          &KoalaBot::getArms(void) const
{
    return *_arms;
}

const Legs          &KoalaBot::getLegs(void) const
{
    return *_legs;
}

const Head          &KoalaBot::getHead(void) const
{
    return *_head;
}

const std::string   &KoalaBot::getSerial(void) const
{
    return _serial;
}