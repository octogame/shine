#pragma once

struct IEngine {
	virtual bool  init() 	= 0;
	virtual bool  run() 	= 0;
	virtual bool  update() 	= 0;
	virtual bool  destroy() = 0;
};
