#ifndef MEMBERS_ENTITY_H
#define MEMBERS_ENTITY_H

#include<iostream>
#include <vector>
#include "Members_info.h"

class Members_entity
{
private:
    std::vector<Members_info> vecMembers_list;
    Members_info members_info;
    FILE* fpDB_data;

public:
    Members_entity();
    virtual ~Members_entity();
    void Load_members_info();
    //void Add_member_info(Members_info member);
    //void Delete_member_info(Members_info member);
    //void Make_DB_members_info();
    void Print_member_info();
};

#endif