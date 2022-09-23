#include "Listener.h"
#include <string.h>

Listener::Listener(Controller* controller)
//mfrc522* rfid = rfid;
{
    rfid = new Card_reader(new SPI(10,3000000));
    this->controller = controller;
    manage_button = new Manage_button(27, "Mode_button");
    update_button = new Manage_button(28, "Update_button");
}

Listener::~Listener()
{

}

void Listener::Check_event()
{
    if(Check_rfid())
    {
       controller->Update_event(rfid->Get_card_number());
    }
    if(manage_button->Check_button()) 
    {
        controller->Update_event(manage_button->Get_button_data());
    }
    if(update_button->Check_button())
    {
        controller->Update_event(update_button->Get_button_data());
    }
}

bool Listener::Check_rfid()
{
    static unsigned int prev_check_time = 0;

    if(millis() - prev_check_time < 1000) return false;

    prev_check_time = millis();

    if(rfid->Is_card()) return true;
    return false;
}