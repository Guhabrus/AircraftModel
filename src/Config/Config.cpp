/**
 * @file Config.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Config.h"


inline Config& Config::getInstance(){
    static Config instance;
    return instance;
}