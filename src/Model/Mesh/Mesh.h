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

#include "../Decorator/Decorator.h"

class Mesh:public Decorator
{
    private:
        std::vector<Vertex>  _vertices;
        std::vector<Texture> _textures;
        std::vector<unsigned int> _indices;

    public:

        /**
         * @brief Construct a new Mesh object
         * 
         * @param mod 
         */
        Mesh(Model* mod);

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
