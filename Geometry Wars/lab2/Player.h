#include "Framework\Object2D.h"
#include "Framework\Circle2D.h"
#include "Framework\Line2D.h"
#include "Framework\Point2D.h"
#include "Framework\Visual2D.h"
#include "Framework\Polygon2D.h"

#pragma once
#define PI 3.14159265358979323846

class Player : Object2D
{
public:
	Player(void);
	Player(Point2D, float);
	void drawingPlayer();
	void drawingSymbol(Point2D);
	void rotate(int);
	void move();
	Point2D getCenter();
	float getAngle();
	int getArmState();
	void activateArm();
	~Player(void);
private:
	float angle;
	float tx;
	float ty;
	int armState;
	Point2D *center;
	Circle2D *player;
	Polygon2D *playerSymbol;
	Polygon2D *playerArm;
};


