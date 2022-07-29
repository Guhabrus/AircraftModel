/**
 * @file CallHandle.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CALLHANDLE_H
#define CALLHANDLE_H


#include "Handle.h"

class CallHandler
{
    public:
        static void key_callback(GLFWwindow* window , int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mode); //TODO убрать maybe_unused



};

#endif