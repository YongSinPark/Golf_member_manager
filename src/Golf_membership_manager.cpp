#include "Golf_membership_manager.h"

Golf_membership_manager::Golf_membership_manager()
: rfid(new mfrc522(new SPI(10, 3000000))), listener(new Listener(rfid))
//mfrc52* rfid = new mfrc522(new SPI(10, 3000000))
{

}
 
Golf_membership_manager::~Golf_membership_manager()
{
    
}

void Golf_membership_manager::Run()
{
    while(1)
    {
        listener->Check_event();
        delay(10);
    }
}