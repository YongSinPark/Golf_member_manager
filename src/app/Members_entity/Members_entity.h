#ifndef MEMBERS_ENTITY_H
#define MEMBERS_ENTITY_H

#include<iostream>
#include <vector>
#include "Members_info.h"

class Members_entity
{
private:
    Members_info members_info;
    FILE* fpDB_data;

public:
    std::vector<Members_info> vecMembers_list;
    Members_entity();
    virtual ~Members_entity();
    void Load_members_info();
    void Add_member_info(Members_info member);
    bool Del_member_info(uint8_t* card_num);
    bool Change_member_info(uint8_t* card_num, Members_info member);
    void Print_member_info(int index);
    void Print_member_info(std::string name);
    void Print_member_info(uint8_t* card_num);
    bool Find_member_info(std::string name);
    bool Find_member_info(uint8_t* card_num);
    void Memory_to_DB();
};

#endif