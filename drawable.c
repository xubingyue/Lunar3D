#include "drawable.h"

typedef struct Drawable {
	GLfloat *vertices;
	GLfloat *normals;
	int *indices;
} Drawable;

struct Drawable *newDrawable(GLfloat vertices[], GLfloat normals[], int indices[]){
	//Create Drawable
	//Whatever creates this is responsible for freeing it
	struct Drawable *returnval = malloc(sizeof(Drawable));
	returnval->vertices = malloc(NELEMS(vertices) * sizeof(GLfloat));
	returnval->normals = malloc(NELEMS(normals) * sizeof(GLfloat));
	returnval->indices = malloc(NELEMS(indices) * sizeof(int));

	//Set data values of Drawable
	returnval->vertices = vertices;
	returnval->normals = normals;
	returnval->indices = indices;

	return returnval; //I wonder what this does
}

void drawableSetVertices(struct Drawable *d, GLfloat vertices[]){
	free(d->vertices); //Free memory before allocating new memory for different vertices
	d->vertices = malloc(NELEMS(vertices) * sizeof(GLfloat)); //Allocate new memory
	d->vertices = vertices; //Set the Drawable's vertices to reflect the vertices that are given
}

void drawableSetNormals(struct Drawable *d, GLfloat normals[]){
	free(d->normals);
	d->normals = malloc(NELEMS(normals) * sizeof(GLfloat));
	d->normals = normals;
}

void drawableSetIndices(struct Drawable *d, int indices[]){
	free(d->indices);
	d->indices = malloc(NELEMS(indices) * sizeof(int));
	d->indices = indices;
}

void drawableFree(struct Drawable *d){
	free(d->vertices);
	free(d->normals);
	free(d->indices);
	free(d);
}
