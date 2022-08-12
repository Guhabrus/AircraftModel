/**
 * @file Decorator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef DECORATOR_H
#define DECORATOR_H
#include "../Model.h"

#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

class Decorator : public Model
{
    private:
        Model* _model;

    protected:
        GLuint _shaderProgram;
        unsigned int _VAO, _VBO, _EBO;

    public:
        Decorator(Model* mod);
        
        /**
         * @brief 
         * 
         */
        void draw();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool init();

};

#endif