#ifndef LISTENER_H
#define LISTENER_H
#include "mfrc522_cmd.h"
#include "mfrc522_reg.h"
#include "mfrc522.h"

class Listener
{
private:
    mfrc522* rfid;
    uint8_t rfid_data[16];

public:
    Listener(mfrc522* rfid);
    ~Listener();
    void Check_event();
};

#endif