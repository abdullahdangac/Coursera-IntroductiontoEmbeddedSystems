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
 * @file memory.h
 * @brief Some very basic data manipulations.
 *
 * This header file provides an abstraction of basic data 
 * manipulations via function calls. 
 *
 * @author Abdullah Dangac
 * @date May 23 2023
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Exponentiation function
 *
 * Given a base and an exponent, this will take exponentiation.
 *
 * @param base Base for exponentiation
 * @param exp Exponent for exponentiation
 *
 * @return Result of exponentiation.
 */
int32_t pow_(uint8_t base, uint8_t exp);

/**
 * @brief Reverse the given character set 
 *
 * Given a pointer to a character set and length of this character
 * set. This will reverse the given chracter set.
 *
 * @param ptr Pointer to character set
 * @param len Length of the character set
 *
 * @return void.
 */
void reverse_(uint8_t * ptr, uint8_t len);

/**
 * @brief Converts data from a integer type into an ASCII string.
 *
 * The number will be convert is taken in as a signed 32-bit integer. 
 * This  coppy the converted character string to the uint8_t* pointer 
 * given in as a parameter (ptr). Places a null terminator at the end 
 * of the converted c-string. This function be able to support bases 
 * 2 to 16 and handle signed data. 
 *
 * @param data Number to convert
 * @param ptr Memory to copy the converted number
 * @param base Base of number to convert
 *
 * @return Length of the converted data (including negative sign and 
 * the null terminator).
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data from an ASCII represented string into an integer type. 
 *
 * The character string to convert is given in as a uint8_t * pointer 
 * (ptr). The number of digits in your character set is given in as a 
 * uint8_t integer (digits). This function be able to support bases 2 
 * to 16 and handle signed data. 
 *
 * @param ptr Memory to copy the converted number
 * @param digits The number of digits in your character set
 * @param base Base of number to convert
 *
 * @return The converted 32-bit signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
