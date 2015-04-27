#include "luafunctions.h"

void addCLuaFunctions(lua_State *L){
	//lunar
	lua_newtable(L);

	//lunar functions
	lua_pushstring(L, "load");
	lua_pushcfunction(L, l_lunar_load);
	lua_settable(L, -3);

	lua_pushstring(L, "update");
	lua_pushcfunction(L, l_lunar_update);
	lua_settable(L, -3);

	lua_pushstring(L, "draw");
	lua_pushcfunction(L, l_lunar_update);
	lua_settable(L, -3);

	//lunar.graphics
	lua_pushstring(L, "graphics");
	lua_newtable(L);

	//lunar.graphics functions
	lua_pushstring(L, "drawQuad");
	lua_pushcfunction(L, l_graphics_drawquad);
	lua_settable(L, -3);

	lua_pushstring(L, "drawCube");
	lua_pushcfunction(L, l_graphics_drawcube);
	lua_settable(L, -3);

	lua_pushstring(L, "setCameraPosition");
	lua_pushcfunction(L, l_graphics_setcameraposition);
	lua_settable(L, -3);

	lua_pushstring(L, "getCameraPosition");
	lua_pushcfunction(L, l_graphics_getcameraposition);
	lua_settable(L, -3);

	lua_pushstring(L, "setCameraAngle");
	lua_pushcfunction(L, l_graphics_setcameraangle);
	lua_settable(L, -3);

	lua_pushstring(L, "getCameraAngle");
	lua_pushcfunction(L, l_graphics_getcameraangle);
	lua_settable(L, -3);

	lua_pushstring(L, "push");
	lua_pushcfunction(L, l_graphics_push);
	lua_settable(L, -3);

	lua_pushstring(L, "pop");
	lua_pushcfunction(L, l_graphics_pop);
	lua_settable(L, -3);

	lua_pushstring(L, "rotate");
	lua_pushcfunction(L, l_graphics_rotate);
	lua_settable(L, -3);

	lua_pushstring(L, "scale");
	lua_pushcfunction(L, l_graphics_scale);
	lua_settable(L, -3);

	lua_pushstring(L, "translate");
	lua_pushcfunction(L, l_graphics_translate);
	lua_settable(L, -3);

	lua_pushstring(L, "setColor");
	lua_pushcfunction(L, l_graphics_setcolor);
	lua_settable(L, -3);

	lua_pushstring(L, "getColor");
	lua_pushcfunction(L, l_graphics_getcolor);
	lua_settable(L, -3);

	lua_pushstring(L, "setBackgroundColor");
	lua_pushcfunction(L, l_graphics_setbackgroundcolor);
	lua_settable(L, -3);

	lua_pushstring(L, "getBackgroundColor");
	lua_pushcfunction(L, l_graphics_getbackgroundcolor);
	lua_settable(L, -3);

	lua_settable(L, -3); //push graphics library onto lunar stack

	//lunar.keyboard functions
	lua_pushstring(L, "keyboard");
	lua_newtable(L);

	lua_pushstring(L, "isDown");
	lua_pushcfunction(L, l_keyboard_isdown);
	lua_settable(L, -3);

	lua_settable(L, -3); //push keyboard library onto lunar stack

	lua_setglobal(L, "lunar");
}
