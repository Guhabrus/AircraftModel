/**
 * @file Config.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Config.h"


inline Config& Config::getInstance(){
    static Config instance;
    return instance;
}


void Config::connect(Observer* obsrv){
    getInstance()._lst_obsvr.push_back(obsrv);
}

void Config::notify(){
    for(std::vector<Observer*>::iterator it = getInstance()._lst_obsvr.begin(); it!= getInstance()._lst_obsvr.end(); ++it)
        (*it)->update();
}

size_t Config::get_size_viewer(){
    return getInstance()._lst_obsvr.size();
}

bool Config::set_height(GLuint height){
    if(height > 0 && height < MAX_HEIGHT_WINDOW){
        getInstance()._height = height;
        getInstance().notify();
        return true;
    }
    return false;
}


bool Config::set_width(GLuint width){
    if(width > 0 && width < MAX_WIDTH_WINDOW){
        getInstance()._width = width;
        getInstance().notify();
        return true;
    }
    return false;
}


GLuint Config::get_height(){
    return getInstance()._height;
}

GLuint Config::get_width(){
    return getInstance()._width;
}



void Config::setPathShader( GLchar* vertexPath,  GLchar* fragmentPath){
    this->getInstance()._vertexPath   = vertexPath;
    this->getInstance()._fragmentPath = fragmentPath;
}



GLchar* Config::getFragmentPath(){
    return this->getInstance()._fragmentPath;
}

GLchar* Config::getVertexPath(){
    return this->getInstance()._vertexPath;
}


void Config::setPathTexureImage(char* PathToImage){
    this->getInstance()._pathToTexureImage = PathToImage;
}


char* Config::getPathTexureImage(){
    return this->getInstance()._pathToTexureImage;
}