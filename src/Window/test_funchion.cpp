#include "Window.h"

static GLfloat vertices[] = {  /// треугольник
    0.5f,  0.5f, 0.0f,  // Верхний правый угол
    0.5f, -0.5f, 0.0f,  // Нижний правый угол
    -0.5f,  0.5f, 0.0f,  // Верхний левый угол
  
};  

static GLuint indices[] = {  // Note that we start from 0!
    0, 1, 3,  // First Triangle
    1, 2, 3   // Second Triangle
};


// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


#include <iostream>
void test_func(GLuint* _ID_VAO, GLuint* _shaderProgram){
    printf("Test_Funuchion\n");
    

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);    // создаем вершинный шейдер
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // привязываем код шейдера к объекту
    glCompileShader(vertexShader);      // скомпилируем его

    GLint success;          //проверка на удачную сборку шейдера
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    GLuint fragmentShader= glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    GLuint shaderProgram = glCreateProgram();   // создаем программу для работы шейдеров
    glAttachShader(shaderProgram, vertexShader); // привязывем вершинный шейдер к программк 
    glAttachShader(shaderProgram, fragmentShader); // привязывем фрагентый шейдер к программк 
    glLinkProgram(shaderProgram);               // собираем программу

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

   


    GLuint VBO, VAO, EBO;                 ///< ID буффера под фигуру
    glGenBuffers(1, &VBO);  /// генерируем буфера
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO); /// привязывем буфер к определенному типу
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO

    (*_ID_VAO) = VAO;
    (*_shaderProgram) = shaderProgram;

}