#include "Controller.h"

Controller::Controller()
{
    monitor = new Monitor();
    members_manage_service = new Members_manage_service();
}

Controller::~Controller()
{

}

void Controller::Update_event(Device_data data)
{
    if(data.dev_name == "Card_reader")
    {
        uint8_t card_number[5];
        for(int i = 0; i < 5; i++)
        {
            card_number[i] = data.dev_data[i];
        }
        members_manage_service->Check_card_num(card_number);
    }

    if(data.dev_name == "Mode_button")
    {
        members_manage_service->Updata_state_event(data.dev_name);
    }
}