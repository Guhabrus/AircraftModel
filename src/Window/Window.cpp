/**
 * @file Window.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Window.h"

///< DEBUG
#include "../Logs/Debug.h"

class handle
{
    public:
    static void key_callback(GLFWwindow* window , int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mode) //TODO убрать maybe_unused
    {
        if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    	glfwSetWindowShouldClose(window, GL_TRUE);
    }
};



Window::Window(GLuint width, GLuint height): _width(width), _height(height)
{
    print_debug("Start constructor Wiindows\n");

    if(!glfwInit()) {   
        print_error("Error inicialization glfw\n");
        return;
    }
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  ///<Задается минимальная требуемая версия OpenGL. Мажоная
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  ///<Задается минимальная требуемая версия OpenGL. Минорная

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  ///<Установка профайла для которого создается контекст

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);                      ///< Выключение возможности изменения размера окна

    _window_p = glfwCreateWindow(_width, _height, "Airbus A310", nullptr, nullptr);
    if(!(bool)_window_p){
        print_error(" Error open window\n");
        return;
    }

    glfwMakeContextCurrent(_window_p);

    //Инициализация GLEW
    glewExperimental = GL_TRUE;

    if(glewInit()){
        print_error("Error inicialization glew\n");
        return;
    }

    glViewport(0,0,_width, _height);
    // glfwSetKeyCallback(_window_p, key_callback);                //TODO убрать maybe_unused
}


ERROR_WINDOW Window::run()
{

    while(!glfwWindowShouldClose(_window_p))
    {
        glfwPollEvents();                       ///< проверяет двженяи с клавиатуры

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(_window_p);
    }

    return SUSSES;
}




Window::~Window()
{
    print_debug("destructor of Window\n");
    glfwTerminate();
}

