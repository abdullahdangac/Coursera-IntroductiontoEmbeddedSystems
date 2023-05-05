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
 * @file stats.h 
 * @brief A simple C code that calculates some statistics of a data set.  
 *
 * A simple C-Programming example that analyze an array of unsigned char data 
 * items and report analytics on the maximum, minimum, mean, and median of the 
 * data set. This data sets from large to small while calculating statistics.
 * Prints that data to the screen in nicely formatted presentation.
 *
 *    Note: This program is not meant to be compiled nor efficient, but rather
 *          provide a handful of c-programming examples and coding guidelines.
 *
 * @author Abdullah Dangac (@abdullahdangac)
 * @date 2023-4-30
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints statistics (median, mean, maximum, minimum) of a data set
 *
 * This function takes as input a data set (array) address (pointer to array) and 
 * number of items in data set (length of array). This will print the statistics of 
 * data set (array) including minimum, maximum, mean, and median. Calls some other 
 * functions while finding the statistics.
 *
 *    Note: Data set array given argument is modified (sorted)
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Nothing
 */
void print_statistics(unsigned char* arr, unsigned int size); 

/**
 * @brief Prints an array
 *
 * This function takes as input a data set (array) address (pointer to array) and 
 * number of items in data set (length of array). This will print the data set (array)
 * to the screen with a maximum 8 data in a row.
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Nothing
 */
void print_array(const unsigned char* arr, unsigned int size); 

/**
 * @brief Sorts a data set (array) from largest to smallest
 *
 * This function takes as input a data set (array) address (pointer to array) and 
 * number of items in data set (length of array). This will sort the data set (array).
 * Sorts the dataset array by accessing its memory via the pointer, so nothing is 
 * returned. 
 *
 *    Note: Data set array given argument is modified (sorted)
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Nothing
 */
void sort_array(unsigned char* arr, unsigned int size); 

/**
 * @brief Finds median value of a data set (array) 
 *
 * This function takes as input a data set address (pointer to array) and number of 
 * items in data set (length of array). This will find the median value of the data 
 * set (array). It will rounded down to the nearest integer this median and returned 
 * value as unsigned char. 
 *
 *    Note: Data set array given argument is modified (sorted)
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Median value of the data set (array)
 */
unsigned char find_median(unsigned char* arr, unsigned int size); 

/**
 * @brief Finds average of a data set (array) 
 *
 * This function takes as input a data set address (pointer to array) and number of 
 * items in data set (length of array). This will find the average of the data set 
 * (array). It will rounded down to the nearest integer this average and returned as 
 * unsigned char.
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Mean of the data set (array)
 */
unsigned char find_mean(const unsigned char* arr, unsigned int size); 

/**
 * @brief Finds maximum value in a data set (array) 
 *
 * This function takes as input a data set address (pointer to array) and number of 
 * items in data set (length of array). This will find the maximum value of the data 
 * set (array). It will rounded down to the nearest integer this maximum value and 
 * returned as unsigned char.
 *
 *    Note: Data set array given argument is modified (sorted)
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Maximum value of the data set (array)
 */
unsigned char find_maximum(unsigned char* arr, unsigned int size); 

/**
 * @brief Finds minimum value in a data set (array) 
 *
 * This function takes as input a data set address (pointer to array) and number of 
 * items in data set (length of array). This will find the minimum value of the data 
 * set (array). It will rounded down to the nearest integer this minimum value and 
 * returned as unsigned char.
 *
 *    Note: Data set array given argument is modified (sorted)
 *
 * @param arr Pointer to a data set (array)
 * @param size Number of items in data set (length of array)
 *
 * @return Minimum value of the data set (array)
 */
unsigned char find_minimum(unsigned char* arr, unsigned int size); 

#endif /* __STATS_H__ */
