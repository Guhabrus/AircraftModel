/**
 * @file Texture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <SOIL/SOIL.h>
#include "Texture.h"
#include "../../Logs/Debug.h"
#include "../../Config/Config.h"

Texture::Texture(Model* mod):Decorator(mod){}

bool Texture::init()
{
    print_debug("Class Texture - method init\n");
    Decorator::init();

    glGenTextures(1, &this->_texture);                 // создание ID текстуры
    glBindTexture(GL_TEXTURE_2D, this->_texture);      // привязка текстуры к фигуре
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* image = SOIL_load_image(Config::getInstance().getPathTexureImage(),&width, &height,0, SOIL_LOAD_RGB);

    if(!image){
        print_error("Error load image\n");
        return false;
    }
        
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);

    return true;
}

void Texture::draw(){
    
    Decorator::draw();
    glBindTexture(GL_TEXTURE_2D, this->_texture);
}