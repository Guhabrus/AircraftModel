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
#include "Observer/Observer.h"


/**
 * @brief 
 * 
 */
enum ERROR_WINDOW
{
    SUSSES,
    ERROR_INIT_WINDOW,
    ERROR_CREATE_WINDOW,
    ERROR_INIT_MODEL
};

/*!
  @brief Класс окна  //TODO написать описание
  
 */
class Window : public Observer
{
    private:
        GLuint _width, _height;
        GLFWwindow* _window_p;
        // Model* _model;
    public:
        /**
         * @brief Construct a new Window object
         * 
         * @param _width высота окна
         * @param _height ширина окна
         */
        Window();

        /**
         * @brief 
         * 
         * @param model 
         * @return ERROR_WINDOW 
         */
        ERROR_WINDOW run([[maybe_unused]] Model *mdl);

        GLFWwindow* getWindow(){
            return _window_p;
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool windowInit();


        void draw_triangle(const GLuint* ID_VAO, const GLuint* shaderProgram);

        /**
         * @brief 
         * 
         virtual */
        void update();
        
        virtual ~Window();
};


void test_func(GLuint* ID_VAO, GLuint* shaderProgram);

#endif