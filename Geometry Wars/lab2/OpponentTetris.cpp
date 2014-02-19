#include "OpponentTetris.h"
#include "Opponent.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Visual2D.h"
#define PI 3.14159265358979323846

OpponentTetris::OpponentTetris(Point2D centerCoord)
:moveVal()
,angle(0)
,sq1()
,sq2()
,sq3()
,sq4()
,sq1fill()
,sq2fill()
,sq3fill()
,sq4fill()
{
	center = new Point2D(centerCoord);
	moveVal = new Point2D(0, 0);
	sq1fill = new Rectangle2D(Point2D(center->x + 10, center->y + 10), 10,10,Color(0,0,1), 1);
	sq2fill = new Rectangle2D(Point2D(center->x, center->y + 10), 10,10,Color(0,0,1), 1);
	sq3fill = new Rectangle2D(Point2D(center->x - 10, center->y + 10), 10,10,Color(0,0,1), 1);
	sq4fill = new Rectangle2D(Point2D(center->x - 10, center->y), 10,10,Color(0,0,1), 1);
	sq1 = new Rectangle2D(Point2D(center->x + 10, center->y + 10), 10,10,Color(0,1,1), 0);
	sq2 = new Rectangle2D(Point2D(center->x, center->y + 10), 10,10,Color(0,1,1), 0);
	sq3 = new Rectangle2D(Point2D(center->x - 10, center->y + 10), 10,10,Color(0,1,1), 0);
	sq4 = new Rectangle2D(Point2D(center->x - 10, center->y), 10,10,Color(0,1,1), 0);
}

//desenare adversar
void OpponentTetris::drawingPlayer(){
	DrawingWindow::addObject2D_to_Visual2D(sq1fill, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq2fill, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq3fill, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq4fill, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq1, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq2, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq3, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(sq4, Opponent::bottom);

	
}

//stergere adversar
void OpponentTetris::removeOpponent(){
	DrawingWindow::removeObject2D_from_Visual2D(sq1fill, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq2fill, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq3fill, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq4fill, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq1, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq2, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq3, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(sq4, Opponent::bottom);
}

//miscare aleatoare
void OpponentTetris::move(){
	angle = rand() % 6;
	float tx = 5 * cos(angle);
	float ty = 5 * sin(angle);
	float matrix [3][3];

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrix[i][j] = Transform2D::TransformMatrix[i][j] ;
		}
	}
	
	while(center->x + tx > DrawingWindow::width - 30 || center->x + tx < 30 
		|| center-> y + ty > DrawingWindow::height - 20 || center->y + ty < 30){		
			angle = rand() % 6;
			tx = 2 * cos(angle);
		    ty = 2 * sin(angle);
	}
	moveVal->x = moveVal->x + tx;
	moveVal->y = moveVal->y + ty;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(moveVal->x ,moveVal->y);
	Transform2D::applyTransform(sq1fill);
	Transform2D::applyTransform(sq2fill);
	Transform2D::applyTransform(sq3fill);
	Transform2D::applyTransform(sq4fill);
	Transform2D::applyTransform(sq1);
	Transform2D::applyTransform(sq2);
	Transform2D::applyTransform(sq3);
	Transform2D::applyTransform(sq4);

	Transform2D::loadInitialMatrix(matrix);
	center->x += tx;
	center->y += ty;
}

OpponentTetris::~OpponentTetris(void)
{
}
