/**
 * @file Mesh.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef MESH_H
#define MESH_H

#include <vector>

#include "MeshData.h"

#include "../Shader/Shader.h"

class Mesh
{
    private:
        std::vector<Vertex>  _vertices;
        std::vector<unsigned int> _indices;
        std::vector<Texture> _textures;
        
        unsigned int _VAO, _VBO, _EBO;
    public:

        /**
         * @brief Construct a new Mesh object
         * 
         * @param mod 
         */
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

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
        void draw(Shader shad);
        

};

#endif
