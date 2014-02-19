#include "Bullet.h"
#include "Opponent.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"

Bullet::Bullet(Point2D centerCoord, float angleValue)
:center()
,moveVal()
,circle()
,angle()
{
	circle = new Circle2D(centerCoord, 4, Color(0.815686, 0.12549, 0.564706), 1);
	moveVal = new Point2D(0, 0);
	center = new Point2D(centerCoord);
	angle = angleValue;
	DrawingWindow::addObject2D_to_Visual2D(circle, Opponent::bottom);
}

//functie de miscare glont
void Bullet::move(){

	float tx = 10*cos(angle);
	float ty = 10*sin(angle);
	float matrix [3][3];

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrix[i][j] = Transform2D::TransformMatrix[i][j] ;
		}
	}
	moveVal->x = moveVal->x + tx;
	moveVal->y = moveVal->y + ty;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(moveVal->x ,moveVal->y);
	Transform2D::applyTransform(circle);

	Transform2D::loadInitialMatrix(matrix);
	center->x += tx;
	center->y += ty;
}

Point2D Bullet::getCircleCenter(){
	return *center;
}

//functi de stergere glont
void Bullet::removeBullet(){
	DrawingWindow::removeObject2D_from_Visual2D(circle, Opponent::bottom);
}

Bullet::~Bullet(void)
{
}
