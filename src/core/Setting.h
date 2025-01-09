
/**
 * @file Setting.h
 * @version 1.1
 * 
 * @copyright Copyright (c) 2024
 * @author Igor Co (or IgorIoT13)
 */
#ifndef SETTING_MV_H
#define SETTING_MV_H


// Check cpp or standart c
#ifdef __cplusplus
    #define CPP_CODE
#endif


/**
 * @brief Error list
 * 
 * @note Used to mark errors 
 */

typedef enum ERROR_STATUS{
    OK_STATUS,
    ERR_STATUS,
    ERR_NOT_FOUND_STATUS,
    ERR_NULL_PTR_STATUS,
    ERR_NULL_STATUS,
    ERR_UNCORECT_INPUT_STATUS,
    ERR_CPP_UNSUPORTED_STATUS
}ERROR_STATUS;


#endif