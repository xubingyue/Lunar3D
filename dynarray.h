#pragma once

#define NULL 0

typedef struct dynamic_int_array {
	unsigned int count; //Stores how many elements are in the array
	unsigned int size;  //Stores how many elements have been allocated in memory
	int *array; //The actual array
} IntArray;

IntArray newIntArray();
void intArrayInsert();
void intArrayFree();
unsigned int intArraySize();
