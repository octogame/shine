#include <shine/CEngine.hpp>
#include <glfw/glfw3.h>

#include <iostream>

int main() {

/*	glfwInit();

	GLFWwindow *win = glfwCreateWindow(100,100,"hello",NULL,NULL);

	glfwMakeContextCurrent(win);


	bool logl = loadOpenGL();
	if(!logl) {
		return -1;
	}
	while(!glfwWindowShouldClose(win)) {
		glClearColor(0.1,0.3,0.5,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		glfwSwapBuffers(win);
		glfwPollEvents();
	}*/

	CEngine engine;

	engine.init();
	engine.run();

	return 0;
}
