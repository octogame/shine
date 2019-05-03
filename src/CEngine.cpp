#include "kivy/CEngine.hpp"
#include "kivy/IRender.h"

bool loadOpengl() {
 if (!gladLoadGL()) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    return false;
  }
  return true;
}

CEngine::CEngine() : m_Render(CreateIRender(this)) {
  if(!glfwInit())
    exit(EXIT_FAILURE);
  bool load_opengl = loadOpengl();
  if(load_opengl)
    std::cout << ":)";
  else {
    std::cout << ":(";
    exit(EXIT_FAILURE);
  }



}

CEngine::~CEngine() {
  glfwTerminate();
}

void CEngine::init() {

}

int CEngine::run() {
  return 0;
}