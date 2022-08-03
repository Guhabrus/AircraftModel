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


Window::Window(Model* mdl):Observer(), _model(mdl)
{
    print_debug("Start constructor Window\n");

    // this->_model = new Model(*mdl);
    
    _height = Config::getInstance().get_height();
    _width = Config::getInstance().get_width();
}

void Window::draw_triangle(const GLuint* ID_VAO, const GLuint* shaderProgram){
  
  

    glUseProgram(*shaderProgram);
    glBindVertexArray(*ID_VAO);
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

ERROR_WINDOW Window::run()
{
    if(!windowInit()){
        return ERROR_INIT;
    }
    
    
    
    while(!glfwWindowShouldClose(_window_p))
    {
        glfwPollEvents();                       ///< проверяет двженяи с клавиатуры

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        this->_model->draw();    

        glfwSwapBuffers(_window_p);
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

    _window_p = glfwCreateWindow(_width, _height, "Airbus A310", nullptr, nullptr);

    if(!(bool)_window_p){
        print_error(" Error open window\n");
        return false;
    }

    glfwMakeContextCurrent(_window_p);

    //Инициализация GLEW
    glewExperimental = GL_TRUE;

    if(glewInit()){
        print_error("Error inicialization glew\n");
        return false;
    }

    glViewport(0,0,_width, _height);
    glfwSetKeyCallback(_window_p, CallHandler::key_callback);                //TODO убрать maybe_unused

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

