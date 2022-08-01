/**
 * @file Config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONFIG_H
#define CONFIG_H

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
// #include <GLFW/glfw3.h>

#include "../Window/Observer/Observer.h"
#include <vector>

class Config
{
    private:
        
        std::vector<Observer*> _lst_obsvr;
        GLuint _width, _height;
        
    public:
        Config(){}
        
        

    /**
     * @brief Get the Instance object
     * 
     * @return Config& 
     */
    static Config& getInstance();

    /**
     * @brief 
     * 
     */
    void notify();

    /**
     * @brief 
     * 
     */
    void connect(Observer* obsrv);

    /**
     * @brief Get the size viewer object
     * 
     * @return size_t 
     */
    size_t get_size_viewer(void);

    /**
     * @brief Set the width object
     * 
     * @param width 
     * @return true 
     * @return false 
     */
    bool set_width(GLuint width);

    /**
     * @brief Set the height object
     * 
     * @param height 
     * @return true 
     * @return false 
     */
    bool set_height(GLuint height);

    /**
     * @brief Get the height object
     * 
     * @return GLuint 
     */
    GLuint get_height();

    /**
     * @brief Get the width object
     * 
     * @return GLuint 
     */
    GLuint get_width();

    Config& operator=(Config&);

    virtual ~Config(){}

};

#define MAX_HEIGHT_WINDOW 1000   ///< 
#define MAX_WIDTH_WINDOW  1000   ///< 
#define WIDTH_DEFAULT     600    ///<
#define HIGHT_DEFAULT     800    ///<

#endif