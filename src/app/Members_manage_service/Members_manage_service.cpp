#include "Members_manage_service.h"

Members_manage_service::Members_manage_service()
{
    members_entity = new Members_entity();
    members_manager_state = CARD_READER;
}

Members_manage_service::~Members_manage_service()
{

}

void Members_manage_service::Updata_state_event(std::string dev_name)
{
    switch(members_manager_state)
    {
        case CARD_READER:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_REGISTER;
                printf("Changed to CARD_RESISTER State\n");
            }
            break;
        case CARD_REGISTER:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_READER;
                printf("Changed to CARD_READER State\n");
            }
            break;
    }
}

void Members_manage_service::Check_card_num(uint8_t* card_num)
{
   switch(members_manager_state)
    {
        case CARD_READER:
            if(members_entity->Find_member_info(card_num))
                {
                printf("Registered Member!\n");
                members_entity->Print_member_info(card_num);
            }
           else printf("Not Registered Member!\n");
            break;
        case CARD_REGISTER:
            Members_info temp_member;
            temp_member.id= 10001;
            strcpy(temp_member.name, "LeeSoonShin");
            strcpy(temp_member.address, "101Dong 123Ho");
            strcpy(temp_member.phone_number, "010-2229-1223");
            memcpy(temp_member.card_num, card_num, sizeof(temp_member.card_num));
            
            members_entity->Add_member_info(temp_member);

            printf("Member Resistered!\n");
            break;
    }
}