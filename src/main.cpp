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
#include "Model/Model.h"
#include "Model/Texture/Texture.h"
#include "Model/Shader/Shader.h"

#include <iostream>
#include <stdio.h>


int main()
{
    Config::getInstance().set_height(600);
    Config::getInstance().set_width(800);     //TODO убрать это сделать парсинг командной строки
    Config::getInstance().setPathShader((GLchar*)"/home/maksim/Myfolder/Scince/C++/AircraftModel/src/Model/Shader/Source/Shader.vs",(GLchar*)"/home/maksim/Myfolder/Scince/C++/AircraftModel/src/Model/Shader/Source/Shader.frag");
    Config::getInstance().setPathTexureImage((char*)"/home/maksim/Myfolder/Scince/C++/AircraftModel/model/Texture/container.jpg");

    

   GLfloat vertices[] = {
    // Позиции          // Цвета             // Текстурные координаты
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Верхний правый
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Нижний правый
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Нижний левый
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Верхний левый
    };
  
  

    

    

    Model* triangle = new Texture(
                            new Shader(
                                new Figure(vertices, 32)));

    Window win;
    
    return win.run(triangle);
}
