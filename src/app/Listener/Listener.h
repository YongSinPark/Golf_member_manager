#ifndef LISTENER_H
#define LISTENER_H
#include "mfrc522_cmd.h"
#include "mfrc522_reg.h"
#include "mfrc522.h"
#include "Controller.h"
#include "Card_reader.h"
#include "Manage_button.h"

class Listener
{
private:
    Card_reader* rfid;
    Controller* controller;
    Manage_button* manage_button;
    Update_button* update_button;
    uint8_t rfid_data[16];

public:
    Listener();
    virtual ~Listener();
    void Check_event();
    bool Check_rfid();
};

#endif