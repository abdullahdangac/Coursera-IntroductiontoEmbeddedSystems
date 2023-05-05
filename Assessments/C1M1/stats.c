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
 * @author Abdullah Dangac (@abdullahdangac)
 * @date 2023-4-30
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the data Set */
#define SIZE (40)

void main() {

  // test data set
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  print_statistics(test, SIZE);

}

void print_array(const unsigned char* arr, unsigned int size) {
  int i;
  for (i = 0; i < size; ++i) {
    if (i % 8 == 0) {
      printf("\n");
    }
    printf("%3d  ", *(arr + i));
  }
  printf("\n");
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
  printf("Array\n--------------------------------------");
  print_array(arr, size);

  unsigned char mean = find_mean(arr, size);
  unsigned char median = find_median(arr, size);
  unsigned char max = find_maximum(arr, size);
  unsigned char min = find_minimum(arr, size);
  
  printf("\nSorted Array\n--------------------------------------");
  print_array(arr, size);
  printf("\nSTATISTICS\n--------------------------------------\n");
  printf("Mean   : %d\nMedian : %d\nMaximum: %d\nMinimum: %d\n", mean, median, max, min);
}
