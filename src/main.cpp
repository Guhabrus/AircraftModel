/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Window/Window.h"
#include "Model/Model.h"
#include "Config/Config.h"
#include <iostream>
#include <stdio.h>
int main()
{
    Config::getInstance().set_height(600);
    Config::getInstance().set_width(800);     //TODO убрать это сделать парсинг командной строки


    Model *model = new Model;
    Window win(model);
    
    
    return win.run();
}
