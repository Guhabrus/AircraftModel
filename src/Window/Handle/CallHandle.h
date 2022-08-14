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


// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

class CallHandler
{
    public:
        static void key_callback(GLFWwindow* window , int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mode); //TODO убрать maybe_unused

        static void mouse_callback(GLFWwindow* window, double xpoxInm, double yposIn);

        static void scroll_callback(GLFWwindow* windowm, double xOffset, double yOffset);

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif