#include "Framework\Point2D.h"
#include "Framework\Rectangle2d.h"
#include "Framework\Polygon2D.h"
#include "Framework\Circle2D.h"
#include "Opponent.h"
#pragma once
class OpponentDiamond : public Opponent
{

public:
	OpponentDiamond(Point2D);
	void drawingPlayer();
	void removeOpponent();
	void rotate(int);
	void move();
	~OpponentDiamond(void);
private:
	Point2D *moveVal;
	Polygon2D *diamond;
	Polygon2D *border;
};

