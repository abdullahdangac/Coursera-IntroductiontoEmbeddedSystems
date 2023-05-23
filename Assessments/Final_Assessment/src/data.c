/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Some very basic data manipulations.
 *
 * This implementation file provides an abstraction of basic data 
 * manipulations via function calls.
 *
 * @author Abdullah Dangac
 * @date May 23 2023
 *
 */
#include <stdint.h>
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/
int32_t pow_(uint8_t base, uint8_t exp) {
    int32_t result = 1;
    for (int i = 1; i <= exp; ++i) {
        result *= base;
    }
    return result;
}

void reverse_(uint8_t * ptr, uint8_t len) {
    uint8_t temp;
    for (int i = 0; i < len / 2; ++i) {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + len - i - 1);
        *(ptr + len - i - 1) = temp;
    }
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t negativeFlag = 0;
    uint8_t idx = 0;
    uint8_t len = 0;
    uint8_t val;

    if (data == 0) {
        *ptr = '0';
        len++;
        *(++ptr) = '\0';
        len++;
        
        return len;
    }

    if (data < 0 && base == 10) {
        negativeFlag = 1;
        data *= -1;
    }

    while (data != 0) {
        val = data % base;
        *(ptr + idx++) = (val > 9) ? (val - 10) + 'A' : val + '0';
        data = data / base;
        len++;    
    } 
          
    if (negativeFlag) {
        *(ptr + idx++) = '-';
        len++;
    }
    
    reverse_(ptr, len);
    *(ptr + idx) = '\0';
    len++;

    return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    uint8_t negativeFlag = 0;
    uint8_t idx = 0;
    int32_t ival = 0;
    uint8_t digit;

    if (*ptr == '-') {
        negativeFlag = 1;
        idx++;
    }

    while (idx < (digits + negativeFlag)) {
        digit = *(ptr + idx);
        if (digit >= 'A' && digit <= 'F')
            digit = (int)(*(ptr + idx) - '7');
        else if (digit >= '0' && digit <= '9')
            digit = (int)(*(ptr + idx) - '0');
        else
            digit = 0;
            //break;
        
        ival += digit * pow_(base, (digits - idx + negativeFlag - 1));
        idx++;
    }
    
    if (negativeFlag)
        ival *= -1;
        
    return ival;
}
