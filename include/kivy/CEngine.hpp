#pragma once

#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <kivy/IEngine.h>
#include <kivy/IRender.h>
bool loadOpengl();


class CEngine : public IEngine 
{
private:
  IRender *m_Render;
public:
  CEngine();
  ~CEngine(); 
  void init() override;
  int run() override;
};