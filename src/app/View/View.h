#ifndef __VIEW_H__
#define __VIEW_H__

#include <iostream>
#include <string>
#include "LCD.h"
#include "Monitor.h"
#include "Led.h"

class View
{
private:
    LCD* lcd;
    Led* led;
    Monitor* monitor;

public:
    View();
    virtual View();
    void Monitor_view(std::string str);
    void Lcd_view(std::string str);
    void Led_view(std::string str);
}

#endif  /*__VIEW_H__*/