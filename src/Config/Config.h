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


class Config
{
    private:
        Config *conf;
        
    public:

    /**
     * @brief Get the Instance object
     * 
     * @return Config& 
     */
    static Config& getInstance();


};

#endif