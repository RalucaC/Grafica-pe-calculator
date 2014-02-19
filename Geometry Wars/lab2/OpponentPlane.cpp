#include "OpponentPlane.h"
#include "Opponent.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Visual2D.h"

OpponentPlane::OpponentPlane(Point2D centerCoord)
:moveVal()
,left()
,right()
{
	center = new Point2D(centerCoord);
	moveVal = new Point2D(0, 0);

	left = new Polygon2D(Color(0.219608, 0.556863, 0.556863), 1);
	right = new Polygon2D(Color(0.219608, 0.556863, 0.556863), 1);

	left->addPoint(Point2D(center->x, center->y + 3));
	left->addPoint(Point2D(center->x + 30, center->y));
	left->addPoint(Point2D(center->x - 5, center->y + 15));
	right->addPoint(Point2D(center->x, center->y - 3));
	right->addPoint(Point2D(center->x + 30, center->y));
	right->addPoint(Point2D(center->x - 5, center->y - 15));
}
//desenare adversar
void OpponentPlane:: drawingPlayer(){
	DrawingWindow::addObject2D_to_Visual2D(left, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(right, Opponent::bottom);
}
//stergere adversar
void OpponentPlane::removeOpponent(){
	DrawingWindow::removeObject2D_from_Visual2D(left, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(right, Opponent::bottom);
}
//functie pentru miscare aleatoare
void OpponentPlane::move(){
	float angle = rand() % 6;
	float tx = 4 * cos(angle);
	float ty = 4 * sin(angle);
	float matrix [3][3];

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrix[i][j] = Transform2D::TransformMatrix[i][j] ;
		}
	}
	
	while(center->x + tx > DrawingWindow::width - 30 || center->x + tx < 30 
		|| center-> y + ty > DrawingWindow::height - 50 || center->y + ty < 30){		
			angle = rand() % 6;
			tx = 4 * cos(angle);
		    ty = 4 * sin(angle);
	}

	moveVal->x = moveVal->x + tx;
	moveVal->y = moveVal->y + ty;
	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(moveVal->x ,moveVal->y);
	Transform2D::applyTransform(left);
	Transform2D::applyTransform(right);
	Transform2D::loadInitialMatrix(matrix);
	center->x += tx;
	center->y += ty;

}

OpponentPlane::~OpponentPlane(void)
{
}
