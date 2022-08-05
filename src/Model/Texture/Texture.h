/**
 * @file Texture.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "../Model.h"
#include "../Decorator/Decorator.h"

/**
 * @brief 
 * 
 */
class Texture:public Decorator
{
    private:
        GLuint _texture;
    public:
        /**
         * @brief Construct a new Texture object
         * 
         */
        Texture(Model* mod);

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool init();

        /**
         * @brief 
         * 
         */
        void draw();
};

#endif