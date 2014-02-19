#include "Framework\Point2D.h"
#include "Framework\Circle2D.h"
#include "Framework\Object2D.h"
#pragma once
class Bullet : public Object2D
{
public:
	Bullet(Point2D, float);
	void move();
	void removeBullet();
	Point2D getCircleCenter();
	~Bullet(void);
private:
	Point2D *center;
	Point2D *moveVal;
	Circle2D *circle;
	float angle;
};

