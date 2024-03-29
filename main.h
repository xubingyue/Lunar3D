#pragma once

//Lua Libraries
#include "lua.h"
#include "lauxlib.h"

//GL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glut.h>

//Misc
#include <math.h>

//C files
#include "luafunctions.h"

float ratio, currentFrame, deltaTime, lastFrame;
int width, height;
float dt;
const double pi = 3.1415926535897932384626433832795;

GLFWwindow* window;

void checkInputs();
void camera();
void glPerspective();

void deltatime();

void getWindow();
