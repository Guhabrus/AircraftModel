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

#include "Config/Config.h"
#include "Model/Model.h"

#include "Model/Shader/Shader.h"
#include "Model/3DModel/3DModel.h"

#include <iostream>
#include <stdio.h>


int main()
{
    Config::getInstance().set_height(600);
    Config::getInstance().set_width(800);     //TODO убрать это сделать парсинг командной строки
    Config::getInstance().setPathShader((GLchar*)"/home/maksim/Myfolder/Scince/C++/AircraftModel/src/Model/Shader/Source/Shader.vs",(GLchar*)"/home/maksim/Myfolder/Scince/C++/AircraftModel/src/Model/Shader/Source/Shader.frag");
    Config::getInstance().setPathTexureImage((char*)"/home/maksim/Myfolder/Scince/C++/AircraftModel/model/Texture/container.jpg");

    


    

    

    Model* triangle =   new Shader(
                                new Model3D("/home/maksim/Myfolder/Scince/C++/AircraftModel/model/AirplaneA310/11803_Airplane_v1_l1.obj")  );
                                

    Window win;
    
    return win.run(triangle);
}
