#pragma once

#include <kivy/IRender.h>

class CRender : public IRender
{
public:
  CRender(IEngine *engine); // 
  ~CRender();
  
  void init() override;
  void run() override;

};