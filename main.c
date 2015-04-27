#include "main.h"

int l_test(lua_State *L){
	printf("C func called from lua");
	return 0;
}

int main(int argc, char *argv[]){
	//LUA STUFF
	//initalize the state
	lua_State *L = luaL_newstate();
	//load the libraries
	luaL_openlibs(L);

	//Load C functions
	addCLuaFunctions(L);

	//Reads in functions so that they can be executed in gameloop below
	luaL_dofile(L, "test.lua");

	//GLFW WINDOW STUFF
	if(!glfwInit())
		return -1;

	window = glfwCreateWindow(800, 600, "Lunar3D", NULL, NULL);

	if(!window){
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	lastFrame = glfwGetTime();

	while(!glfwWindowShouldClose(window)){
		//delta time
		deltatime();

		checkInputs();
		//camera(cx, cy, cz, crx, cry, crz);
		//camera(z, 0, 0, 0, 0, 0);

		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(0x0BA7); //GL_PROJECTION_MATRIX const, because C is a pain in the arse
		glLoadIdentity();
		gluPerspective(60, (double)width / (double)height, 0.1, 100);
		glRotated(crx, 1, 0, 0);
		glRotated(cry, 0, 1, 0);
		glRotated(crz, 0, 0, 1);
		glTranslatef(cx, cy, cz);


		glMatrixMode(GL_MODELVIEW_MATRIX);

		//call update function
		lua_getglobal(L, "lunar");
		lua_pushstring(L, "update");
		lua_gettable(L, -2);

		lua_pushnumber(L, dt);
		lua_pcall(L, 1, 0, 0);

		//call draw function
		lua_getglobal(L, "lunar");
		lua_pushstring(L, "draw");
		lua_gettable(L, -2);

		lua_pcall(L, 0, 0, 0);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void checkInputs(){
    if(glfwGetKey(window, GLFW_KEY_W)){
        cz += cos(cry / 180 * 3.14) * dt * 5;
        cx -= sin(cry / 180 * 3.14) * dt * 5;
    }
    if(glfwGetKey(window, GLFW_KEY_S)){
        cz -= cos(cry / 180 * 3.14) * dt * 5;
        cx += sin(cry / 180 * 3.14) * dt * 5;
    }
    if(glfwGetKey(window, GLFW_KEY_A)){
        cz -= -sin(cry / 180 * 3.14) * dt * 5;
        cx += cos(cry / 180 * 3.14) * dt * 5;
    }
    if(glfwGetKey(window, GLFW_KEY_D)){
        cz += -sin(cry / 180 * 3.14) * dt * 5;
        cx -= cos(cry / 180 * 3.14) * dt * 5;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)){
        cy -= dt * 5;
    }
    if(glfwGetKey(window,GLFW_KEY_LEFT_CONTROL)){
        cy += dt * 5;
    }

    if(glfwGetKey(window, GLFW_KEY_UP)){
        crx -= dt * 100;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN)){
        crx += dt * 100;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT)){
        cry -= dt * 100;
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT)){
        cry += dt * 100;
    }
}

void deltatime(){
	currentFrame = glfwGetTime();
	dt = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void glPerspective(double fovY, double aspect, double zNear, double zFar){
	double fW, fH;

    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;
    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

void getWindow(GLFWwindow* *win){
	*win = window;
}
