#include "dynarray.h"

typedef struct dynamic_array {
	unsigned count;
	unsigned size;
	void array[];
} Array;

Array* newArray(unsigned size){
	Array* a = malloc(sizeof(Array) + size*sizeof())
}
