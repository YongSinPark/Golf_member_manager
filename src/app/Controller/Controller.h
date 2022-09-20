#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include "Monitor.h"
#include "Device_data.h"

using namespace std;

class Controller
{    
private:
    Monitor* monitor;

public:
    Controller();
    virtual ~Controller();
    void Update_event(Device_data data);
};

#endif