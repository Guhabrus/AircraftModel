/**
 * @file Shader.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include <string>

#include "../Decorator/Decorator.h"
#include "../Model.h"

/**
 * @brief 
 * 
 */
class Shader : public Decorator
{
 
        
    public:
        /**
         * @brief Construct a new Shader object
         * 
         * @param vertexPath 
         * @param fragmentPath 
         */
        Shader(Model* mod);

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


        /**
         * @brief 
         * 
         * @param shaider 
         * @param type 
         * @return true 
         * @return false 
         */
        bool check_shader_errors(GLuint shaider, std::string type);

        GLuint getShaderProgram(){
            return this->_shaderProgram;
        }

};


#endif