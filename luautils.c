#include "luautils.h"

/*
 * luautils.c
 *
 *  Created on: 27/04/2015
 *      Author: Ryan
 */


// String library

// lunar.utils.stringSplit(string, split)
int l_string_split(lua_State *L) {
	char *str = lua_tostring(L, -2);
	char *split = lua_tostring(L, -1);

	lua_newtable(L);

	char *result;
	int count = 1;
	result = strtok(str, split);

	lua_pushstring(L, result);
	lua_rawseti(L, -2, count);
	count++;

	while (result != NULL) {
		result = strtok(NULL, split);

		lua_pushstring(L, result);
		lua_rawseti(L, -2, count);
		count++;
	}

	return 1;
}

// lunar.utils.print(str)
int l_utils_print(lua_State *L) {
	char *str = lua_tostring(L, -1);

	printf("%s", str);
	return 0;
}
