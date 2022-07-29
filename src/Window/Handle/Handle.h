/**
 * @file Handle.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HANDLE_H
#define HANDLE_H

#include "../Window.h"

/**
 * @brief 
 * 
 */
class Handle_Button
{
    public:
    /**
     * @brief Construct a new Handle_Button object
     * 
     */
        Handle_Button(){}
    /**
     * @brief Destroy the Handle_Button object
     * 
     */
        virtual ~Handle_Button(){}

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
        virtual void  processing(Window* window_p) = 0;
};


/**
 * @brief 
 * 
 */
class CloseButton
{
    public:

    /**
     * @brief 
     * 
     * @param window_p 
     * @return true 
     * @return false 
     */
        static void processing(GLFWwindow* window) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
};




#endif