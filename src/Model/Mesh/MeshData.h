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

#define MAX_BONE_INFLUENCE 4

/**
 * @brief структура хранения вершин модели
 * 
 */
struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
	//bone indexes which will influence this vertex
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	//weights from each bone
	float m_Weights[MAX_BONE_INFLUENCE];
};
/**
 * @brief структура хранения текстур моделей
 * 
 */
struct Texture {
    unsigned int id;            ///< id текстуры 
    std::string type;           ///< тип текстуры 
    std::string path;
}; 


#pragma pack(pop)

#endif