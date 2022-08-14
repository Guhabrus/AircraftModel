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

#include "Handle/CallHandle.h"
#include "../Config/Config.h"
#include "../Model/Shader/Shader.h"



Window::Window():Observer()
{
    print_debug("Start constructor Window\n");

    // this->_model = new Model(*mdl);
    
    _height = Config::getInstance().get_height();
    _width = Config::getInstance().get_width();
}


ERROR_WINDOW Window::run([[maybe_unused]] Model *mdl)
{
    
    if(!windowInit()){
        return ERROR_INIT_WINDOW;
    }


    if(mdl){
        if(!mdl->init())
            return ERROR_INIT_MODEL;
    }

    
    while(!glfwWindowShouldClose(this->_window_p))
    {
        glfwPollEvents();                       ///< проверяет двженяи с клавиатуры

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if(mdl)
            mdl->draw();    

        glfwSwapBuffers(this->_window_p);
    }

    return SUSSES;
}

bool Window::windowInit(){

    if(!glfwInit()) {   
        print_error("Error inicialization glfw\n");
        return false;
    }
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  ///<Задается минимальная требуемая версия OpenGL. Мажоная
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  ///<Задается минимальная требуемая версия OpenGL. Минорная

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  ///<Установка профайла для которого создается контекст

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);                      ///< Выключение возможности изменения размера окна

    this->_window_p = glfwCreateWindow(_width, _height, "Airbus A310", nullptr, nullptr);

    if(!(bool)_window_p){
        print_error(" Error open window\n");
        return false;
    }

    glfwMakeContextCurrent(_window_p);

    //Инициализация GLEW
    // glewExperimental = GL_TRUE;

    if(glewInit()){
        print_error("Error inicialization glew\n");
        return false;
    }

    glViewport(0,0,_width, _height);
    
    glfwSetKeyCallback(_window_p, CallHandler::key_callback);                //TODO убрать maybe_unused
    glfwSetFramebufferSizeCallback(_window_p, CallHandler::framebuffer_size_callback);
    glfwSetCursorPosCallback(_window_p, CallHandler::mouse_callback);
    glfwSetScrollCallback(_window_p, CallHandler::scroll_callback);

    glfwSetInputMode(this->_window_p, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    GLenum log = glGetError();
    if(log){
        print_error(" GLU ERROR - %d\n", log);
        return false;
    }

    return true;
}

void Window::update(){
    //TODO дописать реализацию   
}


Window::~Window()
{
    print_debug("destructor of Window\n");
    glfwTerminate();
    // if(!this->_model)
    //     delete this->_model;
}

