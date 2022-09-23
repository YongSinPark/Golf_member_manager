#include "Views.h"

Views::Views()
{
    lcd = new LCD(new I2C("/dev/i2c-1", 0x27));
    monitor = new Monitor();
    led_1 = new Led(25);
    led_2 = new Led(24);
    led_3 = new Led(23);
    led_4 = new Led(22);
    Monitor_view("READER_MODE");
    Lcd_view("READER_MODE");
    Led_view("READER_MODE");
}

Views::~Views()
{
    delete lcd;
    delete monitor;
    delete led_1;
    delete led_2;
    delete led_3;
    delete led_4;
}

void Views::Monitor_view(std::string str)
{
    if(str == "READER_MODE")
    {
        system("clear");
        printf("<READER_MODE>\n");
        printf("Detect Card!!\n\n");    
    }
    if(str == "RESISTER_MODE")
    {
        system("clear");
        printf("<RESISTER_MODE>\n");
        printf("Detect Card!!\n\n");  
    }
    if(str == "DELETE_MODE")
    {
        system("clear");
        printf("<DELETE_MODE>\n");
        printf("Detect Card!!\n\n");    
    }
    if(str == "CHANGE_MODE")
    {
        system("clear");
        printf("<CHANGE_MODE>\n");
        printf("Detect Card!!\n\n");    
    }
}

void Views::Lcd_view(std::string str)
{
    char buff[20];

    if(str == "READER_MODE")
    {
        sprintf(buff, "                ");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "                ");
        lcd->WriteStringXY(1, 0, buff);
        sprintf(buff, "<READER_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);
    }
    if(str == "RESISTER_MODE")
    {
        sprintf(buff, "                ");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "                ");
        lcd->WriteStringXY(1, 0, buff);
        sprintf(buff, "<RESISTER_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);       
    }
    if(str == "DELETE_MODE")
    {
        sprintf(buff, "                ");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "                ");
        lcd->WriteStringXY(1, 0, buff);
        sprintf(buff, "<DELETE_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);
    }
    if(str == "CHANGE_MODE")
    {
        sprintf(buff, "                ");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "                ");
        lcd->WriteStringXY(1, 0, buff);
        sprintf(buff, "<CHANGE_MODE>");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff, "Detect Card!!");
        lcd->WriteStringXY(1, 0, buff);    
    }
}

void Views::Led_view(std::string str)
{
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