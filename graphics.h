//protect against multiple includes
//linker being annoying, have to set variables in c file
#pragma once

//Lua Libraries
#include "lua.h"
#include "lauxlib.h"

//GLFW Libraries
#include <GLFW/glfw3.h>

const GLfloat cubevertices[72], cubenormals[72], cubecolors[72];
const GLubyte cubeindices[36];

//Draw Functions
int l_graphics_drawquad();
int l_graphics_drawcube();

//Graphics State Functions
int l_graphics_setcolor();
int l_graphics_getcolor();
int l_graphics_setbackgroundcolor();
int l_graphics_getbackgroundcolor();

//Object Creation
int l_graphics_newmodel();
