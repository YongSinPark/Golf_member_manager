#include <iostream>
#include <thread>
#include <cstring>
#include <string>
#include <wiringPi.h>

#include "mfrc522.h"
#include "Listener.h"
#include "Controller.h"
#include "Members_manage_service.h"
#include "Com_dev.h"
#include "Tcp_server.h"
#include "Golf_membership_manager.h"
#include "Members_entity.h"

void Server_thread(Tcp_server *server)
{
    char recvBuff[BUFSIZ];
    int recvLen;

    while (server->waitAccept() > 0)
    {
        server->setClientState(true);
        while((recvLen = server->recvData(recvBuff, sizeof(recvBuff))) > 0)
        {
            recvBuff[recvLen] = '\0';
            server->sendData(recvBuff, recvLen);
            printf("received : %s\n", recvBuff);
        }
        server->closeSocket(server->getClientSocket());
        server->setClientState(false);
        printf("close client socket\n");
    }
}

int main()
{   
    Tcp_server* card_tcp_server = new Tcp_server(5100);
    Com_dev* com_dev = new Com_dev(card_tcp_server);
    Members_manage_service* members_manage_service = new Members_manage_service(com_dev);
    Controller* controller = new Controller(members_manage_service);
    Listener* listener = new Listener(controller);
    std::thread threadFunc(Server_thread, card_tcp_server);
    //Golf_membership_manager golf_membership_manager;

    //golf_membership_manager.Run();

    while(1)
    {
        listener->Check_event();
        delay(50);
    }
    return 0;
}