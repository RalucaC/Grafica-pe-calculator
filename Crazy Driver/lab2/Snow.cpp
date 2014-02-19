#include "Snow.h"
#include "Framework\DrawingWindow.h"
#include "Framework\Transform2D.h"
#include "Container.h"
Snow::Snow(float xCoodr, float yCoord)
:snowFlake()
,center()
{
	center = new Point2D(0, 0);
	snowFlake = new Circle2D(Point2D(xCoodr, yCoord), 0.05, Color(0,0,1), true);
	DrawingWindow::addObject2D_to_Visual2D(snowFlake, Container::bottom);
}

void Snow::move(){
	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(center->x ,center->y);
	Transform2D::applyTransform(snowFlake);

	center->y -= 0.1;
	center->x -= 0.01;
}

Snow::~Snow(void)
{
}
