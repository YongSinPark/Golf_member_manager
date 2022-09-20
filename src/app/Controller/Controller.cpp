#include "Controller.h"

Controller::Controller()
{
    monitor = new Monitor();
}

Controller::~Controller()
{

}

void Controller::Update_event(uint8_t* data)
{
     monitor->Print(data, 16);
}