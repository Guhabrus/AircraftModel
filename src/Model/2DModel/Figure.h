/**
 * @file Figure.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FIGURE_H
#define FIGURE_H

#include "../Model.h"

#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

class Figure: public Model
{
    private:
        GLuint _VAO,_VBO, _EBO ,_shaderProgram;
        GLfloat* _vertices;
        size_t N_vertex;
        GLuint _texture;
        
    public:
        /**
         * @brief Construct a new Figure object
         * 
         */
        Figure(GLfloat vertices[], size_t N);
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
        bool model_init();


        /**
         * @brief Set the texture object
         * 
         */
        void gen_texture();
        ~Figure();
};


#endif