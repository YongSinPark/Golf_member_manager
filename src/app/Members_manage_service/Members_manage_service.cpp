#include "Members_manage_service.h"
#include <iostream>

using namespace std;

Members_manage_service::Members_manage_service(Com_dev* com_dev)
{
    members_entity = new Members_entity();
    views = new Views();
    this->com_dev = com_dev;
    members_manager_state = CARD_READER;
}

Members_manage_service::~Members_manage_service()
{

}

void Members_manage_service::Updata_state_event(std::string dev_name)
{
    if(dev_name == "Update_button") members_entity->Memory_to_DB();
    
    switch(members_manager_state)
    {
        case CARD_READER:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_REGISTER;
                views->Monitor_view("RESISTER_MODE");
                views->Lcd_view("RESISTER_MODE");
                views->Led_view("RESISTER_MODE");
            }
            break;
        case CARD_REGISTER:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_DELETE;
                views->Monitor_view("DELETE_MODE");
                views->Lcd_view("DELETE_MODE");
                views->Led_view("DELETE_MODE");
            }
            break;
        case CARD_DELETE:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_CHANGE;
                views->Monitor_view("CHANGE_MODE");
                views->Lcd_view("CHANGE_MODE");
                views->Led_view("CHANGE_MODE");
            }
            break;
        case CARD_CHANGE:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_READER;
                views->Monitor_view("READER_MODE");
                views->Lcd_view("READER_MODE");
                views->Led_view("READER_MODE");
            }
            break;
    }
}

void Members_manage_service::Check_card_num(uint8_t* card_num)
{
   switch(members_manager_state)
    {
        char select;

        case CARD_READER:
            if(members_entity->Find_member_info(card_num))
            {
                members_entity->Print_member_info(card_num);
                printf("Registered Member!\n");
                com_dev->Send_data(card_num);
            }
            else printf("Not Registered Member!\n");
            break;

        case CARD_REGISTER:
            Members_info temp_member;

            if(members_entity->Find_member_info(card_num))
            {
                members_entity->Print_member_info(card_num);
                printf("Registered Member!\n");
                printf("Change the information?(y/n) : ");
                cin >> select;
                if(select == 'y')
                {
                    members_manager_state = CARD_CHANGE;
                    break;
                }
                if(select == 'n')
                {
                    card_num = NULL;
                    break;
                }
            }
            else
            {
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
            }
            break;

        case CARD_DELETE:
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
            else printf("Not Registered Member!\n Retry detect card.\n");
            break;

        case CARD_CHANGE:
            if(members_entity->Find_member_info(card_num))
            {
                members_entity->Print_member_info(card_num);
                printf("Change member information\n");
                printf("Really change the information?(y/n) : ");
                cin >> select;
                if(select == 'y')
                {
                    char tmp = temp_member.id;
                    
                    // members_entity->Del_member_info(card_num);
                    temp_member.id = tmp;
                
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
                    
                    members_entity->Change_member_info(card_num, temp_member);

                    printf("Member Resistered!\n");
                }
                else 
                {
                    card_num = NULL;
                    break;
                }
            }
            else printf("Not Registered Member!\n Retry detect card.\n");
            break;
    }
}

void Members_manage_service::Set_com_dev(Com_dev* com_dev)
{
    this->com_dev = com_dev;
}