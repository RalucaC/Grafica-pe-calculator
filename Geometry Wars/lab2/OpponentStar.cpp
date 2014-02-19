#include "OpponentStar.h"
#include "Opponent.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Visual2D.h"

OpponentStar::OpponentStar(Point2D centerCoord)
:moveVal()
,centralCircle()
,poly1()
,poly2()
,poly3()
,poly4()
{
	center = new Point2D(centerCoord);
	moveVal = new Point2D(0, 0);
	centralCircle = new Circle2D(*center,3, Color(1, 0.388235, 0.278431), 0);
	poly1 = new Polygon2D(Color(1, 0.388235, 0.278431), 1);
	poly2 = new Polygon2D(Color(1, 0.388235, 0.278431), 1);
	poly3 = new Polygon2D(Color(1, 0.388235, 0.278431), 1);
	poly4 = new Polygon2D(Color(1, 0.388235, 0.278431), 1);

	poly1->addPoint(Point2D(center->x + 4, center->y));
	poly1->addPoint(Point2D(center->x + 20, center->y));
	poly1->addPoint(Point2D(center->x + 20, center->y - 10));

	poly2->addPoint(Point2D(center->x, center->y - 4));
	poly2->addPoint(Point2D(center->x, center->y - 20));
	poly2->addPoint(Point2D(center->x - 10, center->y - 20));

	poly3->addPoint(Point2D(center->x - 4, center->y));
	poly3->addPoint(Point2D(center->x - 20, center->y));
	poly3->addPoint(Point2D(center->x - 20, center->y + 10));

	poly4->addPoint(Point2D(center->x, center->y + 4));
	poly4->addPoint(Point2D(center->x, center->y + 20));
	poly4->addPoint(Point2D(center->x + 10, center->y + 20));
}

//desenare adversar
void OpponentStar::drawingPlayer(){
	DrawingWindow::addObject2D_to_Visual2D(centralCircle, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(poly1, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(poly2, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(poly3, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(poly4, Opponent::bottom);
}

//stergere adversar
void OpponentStar::removeOpponent(){
	DrawingWindow::removeObject2D_from_Visual2D(centralCircle, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(poly1, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(poly2, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(poly3, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(poly4, Opponent::bottom);
}

//miscare adversar
void OpponentStar::move(){
	float angle = rand() % 6;
	float tx = 8 * cos(angle);
	float ty = 8 * sin(angle);
	float matrix [3][3];

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrix[i][j] = Transform2D::TransformMatrix[i][j] ;
		}
	}
	
	while(center->x + tx > DrawingWindow::width - 30 || center->x + tx < 30 
		|| center-> y + ty > DrawingWindow::height - 50 || center->y + ty < 30){		
			angle = rand() % 6;
			tx = 2 * cos(angle);
		    ty = 2 * sin(angle);
	}

	moveVal->x = moveVal->x + tx;
	moveVal->y = moveVal->y + ty;
	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(moveVal->x ,moveVal->y);
	Transform2D::applyTransform(centralCircle);
	Transform2D::applyTransform(poly1);
	Transform2D::applyTransform(poly2);
	Transform2D::applyTransform(poly3);
	Transform2D::applyTransform(poly4);
	Transform2D::loadInitialMatrix(matrix);
	center->x += tx;
	center->y += ty;

}

OpponentStar::~OpponentStar(void)
{
}
