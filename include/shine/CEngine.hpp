#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <shine/IEngine.h>

bool loadOpenGL();


class CEngine : public IEngine {
private:
	GLFWwindow *win = nullptr;
public:
	CEngine();
	~CEngine();
	bool init()    override;
	bool run()     override;
   	bool update()  override;
	bool destroy() override;	
};
