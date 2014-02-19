#include "Opponent2Squares.h"
#include "Opponent.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Visual2D.h"

Opponent2Squares::Opponent2Squares(Point2D centerCoord)
:moveVal()
,rect1()
,rect2()
{
	center = new Point2D(centerCoord);
	moveVal = new Point2D(0, 0);
	rect1= new Rectangle2D(Point2D(center->x - 12, center->y + 12),15,15, Color(0.9,0.3,0), 1);
	rect2 = new Rectangle2D(Point2D(center->x - 3, center->y + 3),15,15, Color(0.9,0.3,0), 0);
}

//functie de desenare obiect
void Opponent2Squares::drawingPlayer(){
	DrawingWindow::addObject2D_to_Visual2D(rect1, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(rect2, Opponent::bottom);
}

// functie de stergete obiect
void Opponent2Squares::removeOpponent(){
	DrawingWindow::removeObject2D_from_Visual2D(rect1, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(rect2, Opponent::bottom);
}

//functie de miscare obiect
void Opponent2Squares::move(){
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
			tx = 2 * cos(angle);
		    ty = 2 * sin(angle);
	}

	moveVal->x = moveVal->x + tx;
	moveVal->y = moveVal->y + ty;
	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(moveVal->x ,moveVal->y);
	Transform2D::applyTransform(rect1);
	Transform2D::applyTransform(rect2);

	Transform2D::loadInitialMatrix(matrix);
	center->x += tx;
	center->y += ty;


}


Opponent2Squares::~Opponent2Squares(void)
{
}
