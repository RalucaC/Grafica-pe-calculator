#include "Container.h"
#include "Framework\Object3D.h"
#include "Framework\Object3D.h"
#pragma once
class Pyramid :public Container
{
public:
	Pyramid(Point3D, float, float, float, Color, bool);
	void drawingElement();
	void removeElement();
	void move(float);
	void setAngle(float);
	Object3D *shape;
	~Pyramid(void);
private:
	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;
	Point3D *moveVals;
	float xLen;
	float yLen;
	float zLen;
	float tx;
	float ty;
	float angle;
};

