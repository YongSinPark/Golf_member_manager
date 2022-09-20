#ifndef LISTENER_H
#define LISTENER_H
#include "mfrc522_cmd.h"
#include "mfrc522_reg.h"
#include "mfrc522.h"
#include "Controller.h"

class Listener
{
private:
    mfrc522* rfid;
    uint8_t rfid_data[16];
    Controller* controller;

public:
    Listener(mfrc522* rfid);
    virtual ~Listener();
    void Check_event();
    bool Check_rfid();
};

#endif