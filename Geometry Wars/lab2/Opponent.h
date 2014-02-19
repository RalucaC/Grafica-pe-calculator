#include "Framework\Point2D.h"
#include "Framework\Visual2D.h"
#pragma once
class Opponent
{
public:
	Opponent(void);
	virtual void removeOpponent() = 0;
	virtual void drawingPlayer() = 0;
	Point2D getCenter();
	static Visual2D *top;
	static Visual2D *bottom;
	virtual ~Opponent(void);
protected:
	Point2D *center; 
	
};

