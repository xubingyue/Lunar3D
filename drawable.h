#pragma once

#include <GLFW/glfw3.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

struct Drawable *newDrawable();

void drawableSetVertices();
void drawableSetNormals();
void drawableSetIndices();
