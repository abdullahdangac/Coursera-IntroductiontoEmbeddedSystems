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
 * @file stats.c 
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
 * @author Abdullah Dangac
 * @date 2023-4-30
 *
 */

#include <platform.h>
#include "stats.h"

void print_array(const unsigned char* arr, unsigned int size) {
  #ifdef VERBOSE
    int i;
    for (i = 0; i < size; ++i) {
      if (i % 8 == 0) {
        PRINTF("\n");
      }
      PRINTF("%3d  ", *(arr + i));
    }
    PRINTF("\n");
  #endif
}

void sort_array(unsigned char* arr, unsigned int size) {
  unsigned char insert;

  int i;	
  for (i = 0; i < size; ++i) {
    insert = arr[i];
    int moveItem = i;
	  
    while (moveItem > 0 && arr[moveItem - 1] < insert) {
      arr[moveItem] = arr[moveItem - 1];
      --moveItem;	
    }
    arr[moveItem] = insert;
  }
}

unsigned char find_mean(const unsigned char* arr, unsigned int size) {
  double sum = 0;

  int i;
  for (i = 0; i < size; ++i) {
    sum += *(arr + i);
  }

  return (unsigned char)(sum / size + .5);
}

unsigned char find_median(unsigned char* arr, unsigned int size) {
  sort_array(arr, size);

  if (size % 2 != 0) {
    return arr[size / 2];
  }
  else {
    return (unsigned char)((arr[size / 2 - 1] + arr[size / 2]) / 2. + .5);
  }
}

unsigned char find_maximum(unsigned char* arr, unsigned int size) {
  sort_array(arr, size);

  return arr[0];
}

unsigned char find_minimum(unsigned char* arr, unsigned int size) {
  sort_array(arr, size);

  return arr[size - 1];
}

void print_statistics(unsigned char* arr, unsigned int size) {
  PRINTF("Array\n--------------------------------------");
  print_array(arr, size);

  unsigned char mean = find_mean(arr, size);
  unsigned char median = find_median(arr, size);
  unsigned char max = find_maximum(arr, size);
  unsigned char min = find_minimum(arr, size);
  
  PRINTF("\nSorted Array\n--------------------------------------");
  print_array(arr, size);
  PRINTF("\nSTATISTICS\n--------------------------------------\n");
  PRINTF("Mean   : %d\nMedian : %d\nMaximum: %d\nMinimum: %d\n", mean, median, max, min);
}
