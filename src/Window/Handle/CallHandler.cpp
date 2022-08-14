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
        
        default:
    
            break;
        }
    }
}

void CallHandler::mouse_callback([[maybe_unused]] GLFWwindow* window, [[maybe_unused]] double xpoxInm, [[maybe_unused]] double yposIn)
{

}


void CallHandler::scroll_callback([[maybe_unused]] GLFWwindow* windowm,[[maybe_unused]] double xOffset,[[maybe_unused]] double yOffset)
{

}

void CallHandler::framebuffer_size_callback([[maybe_unused]] GLFWwindow* window,[[maybe_unused]] int width, [[maybe_unused]] int height)
{

}
