/**
 * @file Decorator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Decorator.h"

Decorator::Decorator(Model* mod):_model(mod){}

void Decorator::draw(){
    this->_model->draw();
}

bool Decorator::init(){
    return this->_model->init();
}


