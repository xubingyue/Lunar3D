#include "luatypes.h"

typedef struct l_Drawable {
	unsigned int index; //A single int pointing to a drawable stored in a C table
} l_Drawable;

static const struct luaL_Reg drawablelib_f[] = { //functions - ie. not object-oriented
		{"new", newdrawable},
		{NULL, NULL} //Null terminated table!?
};

static const struct luaL_Reg drawablelib_m[] = { //methods
		{"__tostring", drawabletostring},
		{"setID", setdrawableid},
		{"setData", setdrawable},
		{"getData", getdrawable},
		{NULL, NULL}
};

static l_Drawable *checkdrawable(lua_State *L){
	void *ud = luaL_checkudata(L, 1, "__drawablemetatable");
	luaL_argcheck(L, ud != NULL, 1, "'array' expected");
	return (l_Drawable *)ud;
}

//Create a new blank drawable userdata object
static int newdrawable(lua_State *L){
	size_t nbytes = sizeof(l_Drawable);                     //Obtain the size of the drawable
	l_Drawable *a = (l_Drawable *)lua_newuserdata(L, nbytes); //Create a userdata object
	luaL_getmetatable(L, "__drawablemetatable");          //Get the metatable that we created
	lua_setmetatable(L, -2);                              //Set as the metatable of the userdata
	return 1;
}

static int setdrawableid(lua_State *L){
	l_Drawable *a = checkdrawable(L);
	int index = lua_tonumber(L, -1);

	luaL_argcheck(L, a != NULL, 1, "'array' expected");
	luaL_argcheck(L, 1 <= index && index <= UINT_MAX, 2, "index out of range");

	a->index = index;
	return 0;
}

static int setdrawable(lua_State *L){
	l_Drawable *a = checkdrawable(L);
	int index = lua_tonumber(L, -1);

	luaL_argcheck(L, a != NULL, 1, "'array' expected");
	luaL_argcheck(L, 1 <= index && index <= UINT_MAX, 2, "index out of range");

	a->index = index;
	return 0;
}

static int getdrawable(lua_State *L){
	l_Drawable *a = checkdrawable(L);

	luaL_argcheck(L, a != NULL, 1, "'array' expected");

	lua_pushnumber(L, a->index);
	return 1;
}

int drawabletostring(lua_State *L){
	l_Drawable *a = checkdrawable(L);
	lua_pushfstring(L, "drawable(%i)", a->index);
	return 1;
}

int l_opentypes(lua_State *L){
	luaL_newmetatable(L, "__drawablemetatable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, -2);
	lua_settable(L, -3);

	luaL_openlib(L, NULL, drawablelib_m, 0);

	luaL_openlib(L, "lunar.drawable", drawablelib_f, 0);
	return 1;
}
