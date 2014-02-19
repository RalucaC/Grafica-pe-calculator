#include "Framework\Point2D.h"
#include "Framework\Rectangle2d.h"
#include "Framework\Object2D.h"
#include "Opponent.h"
#pragma once

class Opponent2Squares : public Opponent
{
public:
	Opponent2Squares(Point2D);
	void drawingPlayer();
	void removeOpponent();
	void rotate(int);
	void move();
	~Opponent2Squares(void);
private:
	Point2D *moveVal;
	Rectangle2D *rect1;
	Rectangle2D *rect2;
};

