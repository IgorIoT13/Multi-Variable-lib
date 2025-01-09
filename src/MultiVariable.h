
/**
 * @file MultiVariable.h
 * @version 1.1
 * 
 * @copyright Copyright (c) 2025
 * @author Igor Co (or IgorIoT13)
 */
#ifndef MULTI_VARIABLE_H
#define MULTI_VARIABLE_H


#include "core/Setting.h"


#ifdef CPP_CODE
    #include <Arduino.h>
#else
    #include <stdio.h>
    #include <stdint.h>
#endif


/**
 * @brief Union for all variable (Large)
 * 
 * @note Save all enable data type and need to make more easy changing data type
 * 
 * @warning If use C bool and string is not available 
 * @warning Don't recommend use unions better use already exist tools
 * 
 * @warning Union use memory as much as his heaviest has element (8-byte or 64-bit)
 */
typedef union MV_UNION{
    char char_var;
    int int_var;
    float float_var;
    double double_var;

    char* char_ptr_var;
    int* int_ptr_var;
    float* float_ptr_var;
    double* double_ptr_var;

    int8_t int8t_var;
    int16_t int16t_var;
    int32_t int32t_var;
    int64_t int64t_var;

    uint8_t uint8t_var;
    uint16_t uint16t_var;
    uint32_t uint32t_var;
    uint64_t uint64t_var;





}MV_UNION;

#endif