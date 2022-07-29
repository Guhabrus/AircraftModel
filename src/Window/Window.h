/**
 * @file Window.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include "../Model/Model.h"


enum ERROR_WINDOW
{
    SUSSES,
    ERROR_INIT,
    ERROR_CREATE_WINDOW
};

/*!
  @brief Класс окна  //TODO написать описание
  
 */
class Window
{
    private:
        GLuint _width, _height;
        GLFWwindow* _window_p;
    public:
        /**
         * @brief Construct a new Window object
         * 
         * @param _width высота окна
         * @param _height ширина окна
         */
        Window(GLuint _width, GLuint _height);

        /**
         * @brief 
         * 
         * @param model 
         * @return ERROR_WINDOW 
         */
        ERROR_WINDOW run();

        virtual ~Window();
};


#endif