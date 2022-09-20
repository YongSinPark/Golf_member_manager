#ifndef GOLF_MEMBERSHIP_MANAGER_H
#define GOLF_MEMBERSHIP_MANAGER_H

#include <iostream>
#include "Listener.h"
#include "mfrc522.h"
#include "Monitor.h"

class Golf_membership_manager
{
private:
    mfrc522* rfid;
    Listener* listener;

public:
    Golf_membership_manager();
    virtual ~Golf_membership_manager();
    void Run();
};

#endif