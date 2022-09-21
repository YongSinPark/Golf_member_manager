#include "Members_entity.h"

using namespace std;

Members_entity::Members_entity()
{
    fpDB_data = fopen("memberLists.bin", "r+");
    Load_members_info();
    Print_member_info();
}

Members_entity::~Members_entity()
{

}

void Members_entity::Load_members_info()
{
    while(fread(&members_info, sizeof(members_info), 1, fpDB_data))
    {
        vecMembers_list.push_back(members_info);
    }
}
void Members_entity::Print_member_info()
{
    printf("%04d %s %s %s %02d %02d %02d %02d %02d \n", 
    vecMembers_list[1000].id,
    vecMembers_list[1000].name,
    vecMembers_list[1000].address,
    vecMembers_list[1000].phoneNumber,
    vecMembers_list[1000].cardNum[0],
    vecMembers_list[1000].cardNum[1],
    vecMembers_list[1000].cardNum[2],
    vecMembers_list[1000].cardNum[3],
    vecMembers_list[1000].cardNum[4]
    );
}