//protect against multiple includes
//linker being annoying, have to set variables in c file
#pragma once

//Lua Libraries
#include "lua.h"
#include "lauxlib.h"

//GLFW Libraries
#include <GLFW/glfw3.h>

#include <math.h>

const GLfloat cubevertices[72], cubenormals[72], cubecolors[72];
const GLubyte cubeindices[36];

GLfloat cx, cy, cz, crx, cry, crz;

float trx, try, trz;

//Draw Functions
int l_graphics_drawquad();
int l_graphics_drawcube();

//Graphics State Functions
int l_graphics_setcolor();
int l_graphics_getcolor();
int l_graphics_setbackgroundcolor();
int l_graphics_getbackgroundcolor();

//Utility functions
int l_graphics_setcameraposition();
int l_graphics_getcameraposition();
int l_graphics_setcameraangle();
int l_graphics_getcameraangle();

//Coordinate System Manipulation - shameless plug
int l_graphics_push();
int l_graphics_pop();
int l_graphics_rotate();
int l_graphics_scale();
int l_graphics_translate();

//Object Creation
int l_graphics_newmodel();

//Memory deallocation and shutdown
void l_graphics_shutdown();
