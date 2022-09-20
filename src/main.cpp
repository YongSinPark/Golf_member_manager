#include <iostream>
#include "mfrc522.h"
#include "Listener.h"

using namespace std;

int main()
{
    mfrc522 rfid(new SPI(10, 3000000));
    Listener* listener = new Listener(&rfid);

    while(1)
    {
        listener->Check_event();
        delay(1000);
        cout << "hihi" << endl;
    }
    return 0;
}