#include "Listener.h"
#include <string.h>

Listener::Listener(mfrc522* rfid)
: rfid(rfid), controller(new Controller())
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
       controller->Update_event(rfid_data);
    }
}

bool Listener::Check_rfid()
{
    static unsigned int prev_check_time = 0;

    if(millis() - prev_check_time < 1000) return false;

    prev_check_time = millis();

    uint8_t byte;
     if((byte = rfid->mfrc522_request(PICC_REQALL, rfid_data)) == CARD_FOUND)
     {
        memset(rfid_data, 0, sizeof(rfid_data));
        rfid->mfrc522_get_card_serial(rfid_data);
        return true;
    }
    return false;
}