#pragma once

//Lua Libraries
#include "lua.h"
#include "lauxlib.h"

#include <math.h>
#include <limits.h>

static int newdrawable();
static int setdrawable();
static int getdrawable();
int drawabletostring();
int l_opentypes();
