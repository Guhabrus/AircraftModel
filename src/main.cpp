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
#include "Model/2DModel/Figure.h"
#include "Config/Config.h"
#include <iostream>
#include <stdio.h>
int main()
{
    Config::getInstance().set_height(600);
    Config::getInstance().set_width(800);     //TODO убрать это сделать парсинг командной строки


    

    GLfloat vertices[] = {  /// треугольник
    0.5f,  0.5f, 0.0f,  // Верхний правый угол
    0.5f, -0.5f, 0.0f,  // Нижний правый угол
    -0.5f,  0.5f, 0.0f,  // Верхний левый угол
  
};  

    Figure triangle(vertices, 9);
    Window win;
    
    return win.run(&triangle);
}
