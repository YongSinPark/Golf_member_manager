#include "Members_manage_service.h"
#include <iostream>

using namespace std;

Members_manage_service::Members_manage_service()
{
    members_entity = new Members_entity();
    view = new View();
    members_manager_state = CARD_READER;
}

Members_manage_service::~Members_manage_service()
{

}

void Members_manage_service::Updata_state_event(std::string dev_name)
{
    if(dev_name == "Update_button") Members_entity->Memory_to_DB();
    
    switch(members_manager_state)
    {
        case CARD_READER:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_REGISTER;
                view->Monitor_view("RESISTER_MODE");
                view->Lcd_view("RESISTER_MODE");
                view->Led_view("RESISTER_MODE");
            }
            break;
        case CARD_REGISTER:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_DELETE;
                view->Monitor_view("DELETE_MODE");
                view->Lcd_view("DELETE_MODE");
                view->Led_view("DELETE_MODE");
            }
            break;
        case CARD_DELETE:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_CHANGE;
                view->Monitor_view("CHANGE_MODE");
                view->Lcd_view("CHANGE_MODE");
                view->Led_view("CHANGE_MODE");
            }
            break;
        case CARD_CHANGE:
            if(dev_name == "Mode_button")
            {
                members_manager_state = CARD_READER;
                view->Monitor_view("READER_MODE");
                view->Lcd_view("READER_MODE");
                view->Led_view("READER_MODE");
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
                    
                    members_entity->Del_member_info(card_num);
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