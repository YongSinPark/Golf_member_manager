#include "Members_entity.h"
#include <cstring>  //string.h

using namespace std;

Members_entity::Members_entity()
{
    Load_members_info();
}

Members_entity::~Members_entity()
{

}

void Members_entity::Load_members_info()
{
    fpDB_data = fopen("memberLists.bin", "r");
    if(fpDB_data == NULL)
    {
        fprintf(stderr, "file open error!\n");
        return;
    }
    while(fread(&members_info, sizeof(members_info), 1, fpDB_data))
    {
        vecMembers_list.push_back(members_info);
    }
    fclose(fpDB_data);
}

void Members_entity::Add_member_info(Members_info member)
{
    vecMembers_list.push_back(member);
}

void Members_entity::Print_member_info(int index)
{
    if((char)index > vecMembers_list.size()) 
    {
        fprintf(stderr, "out of range member count!\n");
        return;
    }
    printf("%05d %s %s %s %0x-%0x-%0x-%0x-%0x \n", 
    vecMembers_list[index].id,
    vecMembers_list[index].name,
    vecMembers_list[index].address,
    vecMembers_list[index].phone_number,
    vecMembers_list[index].card_num[0],
    vecMembers_list[index].card_num[1],
    vecMembers_list[index].card_num[2],
    vecMembers_list[index].card_num[3],
    vecMembers_list[index].card_num[4]
    );
}

void Members_entity::Print_member_info(std::string name)
{
    for (const auto &member : vecMembers_list)
    {
        if (strcmp(member.name, name.c_str()) == 0) 
        {
            Print_member_info(member.id);
            return;
        }
    }
}

void Members_entity::Print_member_info(uint8_t* card_num)
{
    for (const auto &member : vecMembers_list)
        {
            if (memcmp(member.card_num, card_num, sizeof(member.card_num)) == 0) 
            {
                Print_member_info(member.id);
                return;
            }
        }
}

bool Members_entity::Find_member_info(std::string name)
{
    for (const auto &member : vecMembers_list)
    {
        if (strcmp(member.name, name.c_str()) == 0) 
        {
            Print_member_info(member.id);
            return true;
        }
    }
    return false;
}

bool Members_entity::Find_member_info(uint8_t* card_num)
{
    for (const auto &member : vecMembers_list)
        {
            if (memcmp(member.card_num, card_num, sizeof(member.card_num)) == 0) return true;
        }
        return false;    
}

bool Members_entity::Del_member_info(uint8_t* card_num)
{
    std::vector<Members_info>::iterator itr_member;

    for(itr_member = vecMembers_list.begin(); itr_member != vecMembers_list.end(); itr_member++)
    {
        if(memcmp(itr_member->card_num, card_num, sizeof(itr_member->card_num)) == 0)
        {
            vecMembers_list.erase(itr_member);
            return true;
        }   
    }
    return false;
}

bool Change_member_info(uint8_t* card_num, Members_info member)
{
    std::vector<Members_info>::iterator itr_member;

    for(itr_member = vecMembers_list.begin(); itr_member != vecMembers_list.end(); itr_member++)
    {
        if(memcmp(itr_member->card_num, card_num, sizeof(itr_member->card_num)) == 0)
        {
            vecMembers_list.push(member);
            return true;
        }   
    }
    return false;
}

void Members_entity::Memory_to_DB()
{
    fpDB_data = fopen("memberLists.bin", "w");
    FILE* fpDB_data2 = fopen("memberLists.txt", "w");

    if(fpDB_data == NULL)
    {
        fprintf(stderr, "file open error!\n");
        return;
    }

    for(const auto &member : vecMembers_list)
    {
        fwrite(&member, sizeof(member), 1, fpDB_data);
        fprintf(fpDB_data2, "%05d %s\n", member.id, member.name);
    }
    fclose(fpDB_data);
    fclose(fpDB_data2);
}