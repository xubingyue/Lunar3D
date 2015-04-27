//Lua Libraries
#include "lua.h"
#include "lauxlib.h"

//GLFW Libraries
#include <GLFW/glfw3.h>

extern const int LUNAR_KEYS[];
extern const char *LUNAR_SKEYS[];

#define NKEYS 119

GLFWwindow* windows;

//Functions
int l_keyboard_isdown();
int l_keyboard_getScancodeFromKey();
