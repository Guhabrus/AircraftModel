/**
 * @file Mesh.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Mesh.h"
#include "../../Logs/Debug.h"


#include <fstream>
#include <string>
#include <sstream>

Mesh::Mesh(Model* mod):Decorator(mod)
{

}



bool Mesh::init()
{

    glGenVertexArrays(1, &this->_VAO);
    glGenBuffers(1, &this->_VBO);
    glGenBuffers(1, &this->_VAO);
    
    glBindVertexArray(this->_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->_VBO);

    glBufferData(GL_ARRAY_BUFFER, this->_vertices.size() * sizeof(Vertex), &this->_vertices.front(), GL_STATIC_DRAW);  

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->_indices.size() * sizeof(unsigned int), &this->_indices.front(), GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    glBindVertexArray(0);
    
    GLenum log = glGetError();
    if(log){
        print_error(" GLU ERROR - %d\n", log);
        return false;
    }


    return true;
}



void Mesh::draw(){

    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for(unsigned int i = 0; i < this->_textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // активируем текстурный блок, до привязки
        // получаем номер текстуры
        std::stringstream ss;
        std::string number;
        std::string name = this->_textures[i].type;

        if(name == "texture_diffuse")
            ss << diffuseNr++; // передаем unsigned int в stream
        else if(name == "texture_specular")
            ss << specularNr++; // передаем unsigned int в stream
        number = ss.str(); 

        glUniform1f(glGetUniformLocation(this->_shaderProgram, ("material." + name + number).c_str()), i); 
        glBindTexture(GL_TEXTURE_2D, this->_textures[i].id);     
    }
    glActiveTexture(GL_TEXTURE0);

    glActiveTexture(GL_TEXTURE0);

    // отрисовывем полигональную сетку
    glBindVertexArray(this->_VAO);
    glDrawElements(GL_TRIANGLES, this->_indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    GLenum log = glGetError();
    if(log){
        print_error(" GLU ERROR - %d\n", log);
    }



}