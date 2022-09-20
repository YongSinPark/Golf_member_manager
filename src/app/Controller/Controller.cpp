#include "Controller.h"

Controller::Controller()
{
    monitor = new Monitor();
}

Controller::~Controller()
{

}

void Controller::Update_event(Device_data data)
{
    cout << data.dev_name << " : ";
    for(const auto data : data.dev_data)
    {
        cout << data << " ";
    }
    cout << endl;
}