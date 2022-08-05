/**
 * @file Figure.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <SOIL/SOIL.h>
#include "../../Config/Config.h"
#include "Figure.h"
#include "../../Logs/Debug.h"
#include <cstring>



// static GLfloat vertices[] = {  /// треугольник
//     0.5f,  0.5f, 0.0f,  // Верхний правый угол
//     0.5f, -0.5f, 0.0f,  // Нижний правый угол
//     -0.5f,  0.5f, 0.0f,  // Верхний левый угол
  
// };  

static GLuint indices[] = {  // Note that we start from 0!
    0, 1, 3,  // First Triangle
    1, 2, 3   // Second Triangle
};




Figure::Figure(GLfloat vertices[], size_t N): _VAO(0), _VBO(0), _EBO(0), _vertices(vertices), N_vertex(N)
{
    
    print_debug("Start construct Figure\n");
    
}


bool Figure::init()
{
    
    print_debug("Class Figure - mothod init\n");

    glGenVertexArrays(1, &this->_VAO);
    glGenBuffers(1, &this->_VBO);  /// генерируем буфера
    glGenBuffers(1, &this->_EBO);
    
   

    glBindVertexArray(this->_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, this->_VBO); /// привязывем буфер к определенному типу
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->N_vertex, this->_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    // glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO

    return true;
}



void Figure::draw(){
    
    print_debug("Class Figure - mothod draw\n");
    glBindVertexArray(this->_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}



Figure::~Figure(){
    glDeleteVertexArrays(1, &this->_VAO);
    glDeleteBuffers(1, &this->_VBO);
    glDeleteBuffers(1, &this->_EBO);

}