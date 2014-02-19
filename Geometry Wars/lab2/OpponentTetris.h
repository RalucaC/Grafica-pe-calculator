#include "Framework\Point2D.h"
#include "Framework\Rectangle2d.h"
#include "Opponent.h"
#pragma once
class OpponentTetris : public Opponent
{
public:
	OpponentTetris(Point2D);
	void drawingPlayer();
	void removeOpponent();
	void rotate(int);
	void move();
	~OpponentTetris(void);
private:
	Point2D *moveVal;
	float angle;
	Rectangle2D *sq1;
	Rectangle2D *sq2;
	Rectangle2D *sq3;
	Rectangle2D *sq4;
	Rectangle2D *sq1fill;
	Rectangle2D *sq2fill;
	Rectangle2D *sq3fill;
	Rectangle2D *sq4fill;
};

