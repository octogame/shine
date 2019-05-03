#pragma once

struct IEngine {
  virtual void init() = 0;
  virtual int run() = 0;
};
