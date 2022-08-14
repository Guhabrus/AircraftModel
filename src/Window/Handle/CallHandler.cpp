/**
 * @file CallHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "CallHandle.h"
#include "../../Config/Config.h"

void CallHandler::key_callback(GLFWwindow* window , int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mode)
{
    if(action == GLFW_PRESS)
    {
        switch (key)
        {
            case GLFW_KEY_ESCAPE:
                // CloseButton::processing(window);
                glfwSetWindowShouldClose(window, GL_TRUE);
            break;
            
            case GLFW_KEY_N:        //TODO убрать иммитацию API
                Config::getInstance().set_height(400);
            break;

            default:
        
                break;
        }
    }
}



