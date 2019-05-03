#include <kivy/CEngine.hpp>

int main() {
	std::cout << "...";

	glfwInit();

	GLFWwindow *win = glfwCreateWindow(100,100,"hello",NULL,NULL);

	glfwMakeContextCurrent(win);

	CEngine engine;

	while(!glfwWindowShouldClose(win)) {
		glClearColor(0.1,0.3,0.5,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

}
