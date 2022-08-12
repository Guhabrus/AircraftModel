/**
 * @file Shader.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <fstream>
#include <sstream>
#include "Shader.h"
#include "../../Logs/Debug.h"
#include "../../Config/Config.h"

Shader::Shader(Model* mod):Decorator(mod){}


void Shader::draw(){
    
    Decorator::draw();
    glUseProgram(this->_shaderProgram);
}


bool Shader::init()
{
    print_debug("Class Shader - method init\n");
    if(!Decorator::init())
        return false;

    std::ifstream vShaderFile, fShaderFile;         ///< потоки считывания
    std::string vShaderCodeSourse, fShaderCodeSoursr;           ///< исходный код шейдеров

    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);

    try
    {
        vShaderFile.open(Config::getInstance().getVertexPath());
        fShaderFile.open(Config::getInstance().getFragmentPath());

        std::stringstream vShaderStream, fShaderStream;
        // Считываем данные в потоки
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();       
        // Закрываем файлы
        vShaderFile.close();
        fShaderFile.close();
        // Преобразовываем потоки в массив GLchar
        vShaderCodeSourse = vShaderStream.str();
        fShaderCodeSoursr = fShaderStream.str();   
    }
    catch(const std::exception& ex)
    {
       print_error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ - %s\n", ex.what());
    }
    
    const GLchar* vShaderCode = vShaderCodeSourse.c_str();
    const GLchar* fShaderCode = fShaderCodeSoursr.c_str();
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);    // создаем вершинный шейдер
    
    
    glShaderSource(vertexShader, 1, &vShaderCode, NULL); // привязываем код шейдера к объекту
    glCompileShader(vertexShader);      // скомпилируем его


    GLint success;          //проверка на удачную сборку шейдера
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        print_error("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s\n", infoLog);
        return false;
    }


    GLuint fragmentShader= glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);


    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);


    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        print_error("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
        return false;
    }


    this->_shaderProgram = glCreateProgram();   // создаем программу для работы шейдеров
    glAttachShader(this->_shaderProgram, vertexShader); // привязывем вершинный шейдер к программк 
    glAttachShader(this->_shaderProgram, fragmentShader); // привязывем фрагентый шейдер к программк 
    glLinkProgram(this->_shaderProgram);               // собираем программу


    glGetProgramiv(this->_shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->_shaderProgram, 512, NULL, infoLog);
        print_error("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n%s\n",infoLog);
        return false;
    }


    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}