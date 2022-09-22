#include "View.h"

View::View()
{
    lcd = new LCD();
    monitor = new Monitor();
    led_1 = new Led(25);
    led_2 = new Led(24);
    led_3 = new Led(23);
    led_4 = new Led(22);
}

View::~View()
{

}

void View::Monitor_view(std::string str)
{
char buff[20];

    if(str == "READER_MODE")
    {
        system("clear");
        prinitf("<READER_MODE>\n");
        printf("Detect Card!!\n");    
    }
    if(str == "RESISTER_MODE")
    {
        system("clear");
        prinitf("<RESISTER_MODE>\n");
        printf("Detect Card!!\n");  
    }
    if(str == "DELETE_MODE")
    {
        system("clear");
        prinitf("<DELETE_MODE>\n");
        printf("Detect Card!!\n");    
    }
    if(str == "CHANGE_MODE")
    {
        system("clear");
        prinitf("<CHANGE_MODE>\n");
        printf("Detect Card!!\n");    
    }
}

void View::Lcd_view(std::string str);
{
    char buff[20];

    if(str == "READER_MODE")
    {
        sprintf(buff, "<READER_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);
    }
    if(str == "RESISTER_MODE")
    {
        sprintf(buff, "<RESISTER_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);       
    }
    if(str == "DELETE_MODE")
    {
        sprintf(buff, "<DELETE_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);
    }
    if(str == "CHANGE_MODE")
    {
        sprintf(buff, "<CHANGE_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);    
    }
}

void View::Led_view(std::string str)
{
char buff[20];

    if(str == "READER_MODE")
    {
        led_1->On();    
        led_2->Off();
        led_3->Off();
        led_4->Off();
    }
    if(str == "RESISTER_MODE")
    {
        led_1->Off();    
        led_2->On();
        led_3->Off();
        led_4->Off();    
    }
    if(str == "DELETE_MODE")
    {
        led_1->Off();    
        led_2->Off();
        led_3->On();
        led_4->Off();
    }
    if(str == "CHANGE_MODE")
    {
        led_1->Off();    
        led_2->Off();
        led_3->Off();
        led_4->On();
    }
}