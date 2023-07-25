#include "../test_include/test_KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string &serial) : _serial(serial),
                                                _arms(nullptr),
                                                _legs(nullptr),
                                                _head(nullptr)

{}

KoalaBot::~KoalaBot(void)
{}

Arms          &KoalaBot::getArms(void) const
{
    return *_arms;
}

Legs          &KoalaBot::getLegs(void) const
{
    return *_legs;
}

Head          &KoalaBot::getHead(void) const
{
    return *_head;
}

std::string   KoalaBot::getSerial(void) const
{
    return _serial;
}

void                KoalaBot::setPart(const Arms &arms,
                                        const Legs &legs,
                                        const Head &head)
{
    _arms = std::make_unique<Arms>(arms);
    _legs = std::make_unique<Legs>(legs);
    _head = std::make_unique<Head>(head);
}

void                KoalaBot::swapParts(const Arms &arms)
{
    _arms = std::make_unique<Arms>(arms);
}

void                KoalaBot::swapParts(const Legs &legs)
{
    _legs = std::make_unique<Legs>(legs);
}

void                KoalaBot::swapParts(const Head &head)
{
    _head = std::make_unique<Head>(head);
}