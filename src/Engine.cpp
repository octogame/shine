#include "shine/Engine.hpp"


bool loadOpenGL() {
	if (!gladLoadGL()) {
//		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return false;
	}
	return true;
}


