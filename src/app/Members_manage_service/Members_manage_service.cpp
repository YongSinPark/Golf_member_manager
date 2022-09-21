#include "Members_manage_service.h"
#include <iostream>

using namespace std;

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
                members_manager_state = CARD_DELETE;
                printf("Changed to CARD_DELETE State\n");
            }
            break;
        case CARD_DELETE:
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
            //vector <Members_info> vec_temp_member;
            temp_member.id = members_entity->vecMembers_list.size();
            
            char name[20], address[40], phone_number[15];
            cout << "name : ";
            cin >> name;

            cout << "address : ";
            cin >> address;

            cout << "phone_number : ";
            cin >> phone_number;
            //cin >> name >> address >> phone_number;

            strcpy(temp_member.name, name);
            strcpy(temp_member.address, address);
            strcpy(temp_member.phone_number, phone_number);
            memcpy(temp_member.card_num, card_num, sizeof(temp_member.card_num));
            
            members_entity->Add_member_info(temp_member);

            printf("Member Resistered!\n");
            break;

        case CARD_DELETE:
            char select;
            if(members_entity->Find_member_info(card_num))
            {
                members_entity->Print_member_info(card_num);
                printf("\n Really Delete?(Y/N) : ");
                cin >> select;
                if(select == 'y')
                {
                    members_entity->Del_member_info(card_num);
                    printf("Delete Complete!!");
                }
                if(select == 'n')
                {
                    printf("Cancle Delete! goto mode : CARD_READER\n");
                    members_manager_state = CARD_READER;
                }
            }
            else printf("Not Registered Member!\n");
            break;
    }
}