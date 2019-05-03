#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

bool loadOpengl() {
 if (!gladLoadGL()) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    return false;
  }
  return true;
}

int main() {

	glfwInit();

	GLFWwindow *win = glfwCreateWindow(100,100,"hello",NULL,NULL);

	glfwMakeContextCurrent(win);


	bool logl = loadOpengl();
	if(!logl) {
		return -1;
	}

	while(!glfwWindowShouldClose(win)) {
		glClearColor(0.1,0.3,0.5,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

}
