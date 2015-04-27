//lunar.graphics lua-C interface
#include "graphics.h"

//Cube data
const GLfloat cubevertices[] = {
	1, 1, 1,  -1, 1, 1,  -1,-1, 1,   1,-1, 1,   //front
	1, 1, 1,   1,-1, 1,   1,-1,-1,   1, 1,-1,   //right
	1, 1, 1,   1, 1,-1,  -1, 1,-1,  -1, 1, 1,   //top
    -1, 1, 1,  -1, 1,-1,  -1,-1,-1,  -1,-1, 1,  //left
	-1,-1,-1,   1,-1,-1,   1,-1, 1,  -1,-1, 1,  //bottom
	1,-1,-1,  -1,-1,-1,  -1, 1,-1,   1, 1,-1	//back
};

const GLfloat cubenormals[] = {
	0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,   //front
	1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,   //right
	0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,   //top
	-1, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,  //left
	0,-1, 0,   0,-1, 0,   0,-1, 0,   0,-1, 0,   //bottom
	0, 0,-1,   0, 0,-1,   0, 0,-1,   0, 0,-1    //back
};

//Default color gradient color for cubes
const GLfloat cubecolors[] = {
	1, 1, 1,   1, 1, 0,   1, 0, 0,   1, 0, 1,   //front
	1, 1, 1,   1, 0, 1,   0, 0, 1,   0, 1, 1,   //right
	1, 1, 1,   0, 1, 1,   0, 1, 0,   1, 1, 0,   //top
	1, 1, 0,   0, 1, 0,   0, 0, 0,   1, 0, 0,   //left
	0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,   //bottom
	0, 0, 1,   0, 0, 0,   0, 1, 0,   0, 1, 1    //back
};

const GLubyte cubeindices[] = {
	0, 1, 2,   2, 3, 0,      					//front
	4, 5, 6,   6, 7, 4,      					//right
	8, 9,10,  10,11, 8,      					//top
	12,13,14,  14,15,12,      					//left
	16,17,18,  18,19,16,      					//bottom
	20,21,22,  22,23,20  						//back
};

GLubyte r = 255;
GLubyte g = 255;
GLubyte b = 255;

GLubyte br = 0;
GLubyte bg = 0;
GLubyte bb = 0;

//lunar.graphics.drawQuad(x, y, z, width, height)
int l_graphics_drawquad(lua_State *L){
	float x = lua_tonumber(L, -5);
	float y = lua_tonumber(L, -4);
	float z = lua_tonumber(L, -3);
	float width = lua_tonumber(L, -2);
	float height = lua_tonumber(L, -1);

	//draw here
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(45, 1, 1, 0);
	glBegin(GL_QUADS);

	glVertex2f(-width / 2, height / 2);
	glVertex2f(width / 2, height / 2);
	glVertex2f(width / 2, -height / 2);
	glVertex2f(-width / 2, -height / 2);

	glEnd();
	glPopMatrix();

	return 0;
}

//lunar.graphics.drawCube(x, y, z, size)
int l_graphics_drawcube(lua_State *L){
	float x = lua_tonumber(L, -4);
	float y = lua_tonumber(L, -3);
	float z = lua_tonumber(L, -2);
	float size = lua_tonumber(L, -1);

	//Uses glDrawElements for efficient vertex array rendering
	//Uncomment GL_COLOR_ARRAY stuff for test gradient rendering
	glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_FLOAT, 0, cubenormals);
	//glColorPointer(3, GL_FLOAT, 0, cubecolors);
	glVertexPointer(3, GL_FLOAT, 0, cubevertices);

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(size / 2, size / 2, size / 2);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, cubeindices);

	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	//glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	return 0;
}

//lunar.graphics.setColor(r, g, b)
int l_graphics_setcolor(lua_State *L){
	r = lua_tonumber(L, -3);
	g = lua_tonumber(L, -2);
	b = lua_tonumber(L, -1);
	glColor3ub(r, g, b);
	return 0;
}

//lunar.graphics.getColor()
int l_graphics_getcolor(lua_State *L){
	lua_pushnumber(L, r);
	lua_pushnumber(L, g);
	lua_pushnumber(L, b);
	return 3;
}

//lunar.graphics.setBackgroundColor(r, g, b)
int l_graphics_setbackgroundcolor(lua_State *L){
	br = lua_tonumber(L, -3) / 255;
	bg = lua_tonumber(L, -2) / 255;
	bb = lua_tonumber(L, -1) / 255;
	glClearColor(br, bg, bb, 255);
	return 0;
}

//lunar.graphics.getBackgroundColor()
int l_graphics_getbackgroundcolor(lua_State *L){
	lua_pushnumber(L, br * 255);
	lua_pushnumber(L, bg * 255);
	lua_pushnumber(L, bb * 255);
	return 3;
}
