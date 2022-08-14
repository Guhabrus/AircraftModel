/**
 * @file 3DModel.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef MODEL3D_H
#define MODEL3D_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <vector>

#include "../Model.h"
#include "../Mesh/Mesh.h"
#include "../Mesh/MeshData.h"
#include "../Mesh/Mesh.h"

class Model3D:public Model
{
    private:
        std::string _pathModel;
        std::string _directory; ///< ???????
        std::vector<Texture> textures_loaded;
        std::vector<Mesh> _meshes;


        /**
         * @brief 
         * 
         * @param node 
         * @param scene 
         */
        void processNode(aiNode *node, const aiScene *scene);

        /**
         * @brief 
         * 
         * @param mesh 
         * @param scene 
         */
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);


        /**
         * @brief 
         * 
         * @param mat 
         * @param type 
         * @param typeName 
         * @return vector<Texture> 
         */
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);

        /**
         * @brief 
         * 
         * @param path 
         * @param directory 
         * @param gamma 
         * @return unsigned int 
         */
        unsigned int TextureFromFile(const char *path, const std::string &directory);


    public:

    Model3D(std::string path);

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


