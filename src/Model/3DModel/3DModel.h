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

#include "../Model.h"

class Model3D:public Model
{
    public:

    /**
     * @brief 
     * 
     */
    void draw()=0;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool init() = 0;

};



#endif


