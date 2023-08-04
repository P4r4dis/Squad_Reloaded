#include "../include/KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :  _x(x), _y(y),
                                                m_serial(serial),
                                                _next(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom(void)
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}


void        KreogCom::addCom(int x, int y, int serial)
{
    // Create a new KreogCom with the given x, y, and serial values
    KreogCom    *newKreogCom = new KreogCom(x, y, serial);
    _list.push_back(newKreogCom);

    // Get the current next KreogCom
    KreogCom    *oldKreogCom = getCom();

    // If there is already a next KreogCom
    if (oldKreogCom != nullptr) {
        // Link the new KreogCom to the old one
        newKreogCom->_next = oldKreogCom;
    }
    // Link the new KreogCom to the current one
    _next = newKreogCom;
}

// void        KreogCom::addComSmartPtr(int x, int y, int serial)
// {
//     // Create a new KreogCom with the given x, y, and serial values
//     std::unique_ptr<KreogCom> newKreogCom = std::make_unique<KreogCom>(x, y, serial);

//     // Get the current next KreogCom
//     std::unique_ptr<KreogCom> oldKreogCom = std::move(m_next);

//     // Link the new KreogCom to the current one
//     m_next = std::move(newKreogCom);
// }

KreogCom    *KreogCom::getCom(void)
{
    return _next;
}

// std::unique_ptr<KreogCom>   KreogCom::getUniquePtrCom(void)
// {
//     return std::move(m_next);
// }

void        KreogCom::removeCom() 
{
    if (!_list.empty())
    {
        delete _list.back();
        _list.pop_back();
    }
    // if (_next != nullptr) {
    //     // Create a pointer to the next KreogCom in the list
    //     KreogCom* temp = _next;
    //     // Update the current KreogCom's next pointer to the next next KreogCom
    //     _next = _next->_next;
    //     // Set the next pointer of the deleted object to nullptr to avoid any dangling pointers
    //     temp->_next = nullptr;
    //     // Delete the next KreogCom
    //     delete temp;
    // }
}

void        KreogCom::ping(void)
{
    std::cout   << "KreogCom " << m_serial << " currently at "
                << _x << " " << _y << std::endl;
}

void        KreogCom::locateSquad(void)
{
    KreogCom    *current = _next;
    
    // Print information about all linked KreogCom
    while (current != nullptr) {
        current->ping();
        if(current->_next)
            current = current->_next;
        else
            current = nullptr;
    }
    // Print information about the current KreogCom
        this->ping();

}