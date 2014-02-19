#include "Framework\Point2D.h"
#include "Framework\Rectangle2d.h"
#include "Framework\Polygon2D.h"
#include "Opponent.h"
#pragma once
class OpponentPlane : public Opponent
{
public:
	OpponentPlane(Point2D);
	void drawingPlayer();
	void removeOpponent();
	void rotate(int);
	void move();
	~OpponentPlane(void);
private:
	Point2D *moveVal;
	Polygon2D *left;
	Polygon2D *right;
};

