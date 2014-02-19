#pragma once
#include "Framework\Circle2D.h"
class Snow
{
public:
	Snow(float, float);
	void move();
	~Snow(void);
private:
	Circle2D *snowFlake;
	Point2D* center;
};

