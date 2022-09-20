#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Monitor.h"

class Controller
{    
private:
    Monitor* monitor;

public:
    Controller();
    virtual ~Controller();
    void Update_event(uint8_t* data);
};

#endif