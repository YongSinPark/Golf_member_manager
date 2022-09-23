#ifndef MEMBERS_MANAGE_SERVICE_H
#define MEMBERS_MANAGE_SERVICE_H
#include <string>
#include <iostream>
#include <cstring>
#include "Members_entity.h"
#include "Members_info.h"
#include "Views.h"
#include "Com_dev.h"

enum {CARD_READER, CARD_REGISTER, CARD_DELETE, CARD_CHANGE};

class Members_manage_service
{    
private:
    Members_entity* members_entity;
    Views* views;
    Com_dev* com_dev;
    int members_manager_state;

public:
    Members_manage_service(Com_dev* com_dev);
    virtual ~Members_manage_service();
    void Updata_state_event(std::string dev_name);
    void Check_card_num(uint8_t* card_num);
    void Set_com_dev(Com_dev* com_dev);
    void Card_resister(uint8_t* card_num);
    void Card_change(uint8_t* card_num);
};

#endif