#include "Framework\Visual2D.h"
#pragma once
class Container
{
public:
	Container(void);
	static Visual2D *bottom;
	virtual void drawingElement() = 0;
	virtual void removeElement() = 0;
	Point3D getStartPoint();
	~Container(void);
protected:
	Point3D *startPoint;
};

