#include "Container.h"
#include "Framework\DrawingWindow.h"

Visual2D * Container::bottom = new Visual2D(-3,-6,3,6,0,0,DrawingWindow::width,DrawingWindow::height);

Container::Container(void)
	:startPoint()
{
}

Point3D Container::getStartPoint(){
	return *startPoint;
}

Container::~Container(void)
{
}
