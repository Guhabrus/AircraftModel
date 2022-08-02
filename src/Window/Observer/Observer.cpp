/**
 * @file Observer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Observer.h"

#include "../../Config/Config.h"

Observer::Observer(){
    Config::getInstance().connect(this);
}