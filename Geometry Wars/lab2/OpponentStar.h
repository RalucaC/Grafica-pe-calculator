#include "Framework\Point2D.h"
#include "Framework\Rectangle2d.h"
#include "Framework\Polygon2D.h"
#include "Framework\Circle2D.h"
#include "Opponent.h"
#pragma once
class OpponentStar : public Opponent
{
public:
	OpponentStar(Point2D);
	void drawingPlayer();
	void removeOpponent();
	void rotate(int);
	void move();
	~OpponentStar(void);
private:
	Point2D *moveVal;
	Circle2D *centralCircle;
	Polygon2D *poly1;
	Polygon2D *poly2;
	Polygon2D *poly3;
	Polygon2D *poly4;
};

