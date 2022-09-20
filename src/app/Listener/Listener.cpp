#include "Listener.h"

Listener::Listener(mfrc522* rfid)
: rfid(rfid)  //mfrc522* rfid = rfid;
{

}

Listener::~Listener()
{

}

void Listener::Check_event()
{
    if(rfid->mfrc522_request(PICC_REQALL, rfid_data) == CARD_FOUND){
        rfid->mfrc522_get_card_serial(rfid_data);

        for(int i = 0; i < 5; i++)
        {
            printf("%02x", rfid_data[i]);
        }
    }

}