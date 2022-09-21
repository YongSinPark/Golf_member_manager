#include <iostream>
#include <cstring>
#include "mfrc522.h"
#include "Listener.h"
#include "Golf_membership_manager.h"
#include "Members_entity.h"


using namespace std;

int main()
{
    Golf_membership_manager golf_membership_manager;

    golf_membership_manager.Run();

    return 0;
}