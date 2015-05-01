#include "dynarray.h"

typedef struct dynamic_array {
	unsigned count;
	unsigned size;
	void array[];
} Array;
