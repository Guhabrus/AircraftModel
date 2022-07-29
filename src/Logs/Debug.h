/**
 * @file Debug.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DEBUG_H
#define DEBUG_H

#define PRINT_DEBUG

#ifdef PRINT_DEBUG
    #define print_debug(...) printf(__VA_ARGS__)
#else
    #define print_debug(...) while (false){}
#endif    


#define print_error(...) fprintf(stderr, __VA_ARGS__)

#endif