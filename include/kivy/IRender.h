#pragma once

#define RENDER_API

struct IEngine;

struct IRender {
  virtual void init() = 0;
  virtual void run() = 0;
};



extern "C"
{
  RENDER_API IRender* CreateIRender(IEngine *engine);
}