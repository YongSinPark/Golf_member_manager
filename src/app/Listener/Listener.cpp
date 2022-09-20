#include "Listener.h"
#include <string.h>

Listener::Listener()
: rfid(new Card_reader(new SPI(10, 3000000))), controller(new Controller())
//mfrc522* rfid = rfid;
{

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
}

bool Listener::Check_rfid()
{
    static unsigned int prev_check_time = 0;

    if(millis() - prev_check_time < 1000) return false;

    prev_check_time = millis();

    if(rfid->Is_card()) return true;
    return false;
}