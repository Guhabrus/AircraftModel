/**
 * @file MeshData.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef MESHDATA_H
#define MESHDATA_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#pragma pack(push, 1)

/**
 * @brief структура хранения вершин модели
 * 
 */
struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

/**
 * @brief структура хранения текстур моделей
 * 
 */
struct Texture {
    unsigned int id;            ///< id текстуры 
    std::string type;           ///< тип текстуры 
}; 


#pragma pack(pop)

#endif