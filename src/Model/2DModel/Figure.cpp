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



// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "layout (location = 1) in vec3 color;\n"
    "layout (location = 2) in vec2 texCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
        "gl_Position = vec4(position, 1.0f);\n"
        "ourColor = color;\n"
        "TexCoord = texCoord;\n"
    "}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"in vec3 ourColor;\n"
"in vec2 TexCoord;\n"
"out vec4 color;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"    color = texture(ourTexture, TexCoord);\n"
"}\n\0";



Figure::Figure(GLfloat vertices[], size_t N): _VAO(0), _VBO(0), _EBO(0), _shaderProgram(0), _vertices(vertices), N_vertex(N)
{
    
    print_debug("Start construct Figure\n");
    
}


bool Figure::model_init()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);    // создаем вершинный шейдер
    
    
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // привязываем код шейдера к объекту
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
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
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

    
    glGenVertexArrays(1, &this->_VAO);
    glGenBuffers(1, &this->_VBO);  /// генерируем буфера
    glGenBuffers(1, &this->_EBO);
    
     GLfloat vertices[] = {
    // Позиции          // Цвета             // Текстурные координаты
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Верхний правый
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Нижний правый
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Нижний левый
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Верхний левый
    };
  

    glBindVertexArray(this->_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, this->_VBO); /// привязывем буфер к определенному типу
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

    this->gen_texture();

    return true;

    
}


void Figure::gen_texture()
{
    glGenTextures(1, &this->_texture);                 // создание ID текстуры
    glBindTexture(GL_TEXTURE_2D, this->_texture);      // привязка текстуры к фигуре
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* fon = SOIL_load_image("../../../model/Texture/container.jpg",&width, &height,0, SOIL_LOAD_RGB);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, fon);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(fon);
    glBindTexture(GL_TEXTURE_2D, 0);

    


}

void Figure::draw(){
    glBindTexture(GL_TEXTURE_2D, this->_texture);
    glUseProgram(this->_shaderProgram);
    glBindVertexArray(this->_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}



Figure::~Figure(){
    glDeleteVertexArrays(1, &this->_VAO);
    glDeleteBuffers(1, &this->_VBO);
    glDeleteBuffers(1, &this->_EBO);

}