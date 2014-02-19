#include "OpponentDiamond.h"
#include "Opponent.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Visual2D.h"

OpponentDiamond::OpponentDiamond(Point2D centerCoord)
:moveVal()
,diamond()
,border()
{
	center = new Point2D(centerCoord);
	moveVal = new Point2D(0, 0);
	diamond= new Polygon2D(Color(0.854902, 0.647059, 0.12549), 1);
	border = new Polygon2D(Color(0.854902, 0.647059, 0.12549), 0);

	border->addPoint(Point2D(center->x + 10, center->y + 10));
	border->addPoint(Point2D(center->x + 10, center->y - 10));
	border->addPoint(Point2D(center->x - 10, center->y - 10));
	border->addPoint(Point2D(center->x - 10, center->y + 10));

	diamond->addPoint(Point2D(center->x, center->y + 10));
	diamond->addPoint(Point2D(center->x + 10, center->y));
	diamond->addPoint(Point2D(center->x, center->y - 10));
	diamond->addPoint(Point2D(center->x - 10, center->y));
}

//desenare adversar
void OpponentDiamond::drawingPlayer(){
	DrawingWindow::addObject2D_to_Visual2D(border, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(diamond, Opponent::bottom);
}
//stergere adversar
void OpponentDiamond::removeOpponent(){
	DrawingWindow::removeObject2D_from_Visual2D(border, Opponent::bottom);
	DrawingWindow::removeObject2D_from_Visual2D(diamond, Opponent::bottom);
}
//miscare aleatoare
void OpponentDiamond::move(){
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
	Transform2D::applyTransform(diamond);
	Transform2D::applyTransform(border);
	Transform2D::loadInitialMatrix(matrix);
	center->x += tx;
	center->y += ty;
}
OpponentDiamond::~OpponentDiamond(void)
{
}
