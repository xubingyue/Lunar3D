#include "dynarray.h"

IntArray newIntArray(){
	IntArray *a = malloc(sizeof(IntArray));
	a->array = malloc(sizeof(int));
	a->count = 0;
	a->size = 1;

	return a;
}

void intArrayInsert(IntArray *a, int element){
	if(a->count == a->size) {
		a->size++;
		a->array = realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->count++] = element;
}

void intArrayFree(IntArray *a){
	free(a->array);
	a->array = NULL;
	a->count = a->size = 0;
	free(a);
}

unsigned int intArraySize(IntArray *a){
	return a->count - 1;
}
