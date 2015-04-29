/*
 * luautils.h
 *
 *  Created on: 27/04/2015
 *      Author: Ryan
 */

#pragma once

#include "lua.h"
#include "lauxlib.h"
#include <string.h>

int l_string_split(lua_State *L);
int l_utils_print(lua_State *L);
