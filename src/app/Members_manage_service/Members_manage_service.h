#ifndef MEMBERS_MANAGE_SERVICE_H
#define MEMBERS_MANAGE_SERVICE_H
#include <string>
#include <iostream>
#include <cstring>
#include "Members_entity.h"
#include "Members_info.h"
#include "View.h"

enum {CARD_READER, CARD_REGISTER, CARD_DELETE, CARD_CHANGE};

class Members_manage_service
{    
private:
    Members_entity* members_entity;
    View* view;
    int members_manager_state;

public:
    Members_manage_service();
    virtual ~Members_manage_service();
    void Updata_state_event(std::string dev_name);
    void Check_card_num(uint8_t* card_num);
};

#endif