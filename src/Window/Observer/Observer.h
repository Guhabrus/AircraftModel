/**
 * @file Observer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief 
 * 
 */

class Observer
{
    protected:

        
    public:
        Observer(/* args */);
        virtual ~Observer(){}

        virtual void update() =0;
};







#endif