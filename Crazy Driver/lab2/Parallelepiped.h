#include "Container.h"
#include "Framework\Object3D.h"
#include "Framework\Object3D.h"

#pragma once
class Parallelepiped : public Container
{
public:
	Parallelepiped(Point3D, float, float, float, Color, bool);
	void drawingElement();
	void removeElement();
	void move(float);
	void rotate(float);
	void setAngle(float);
	Object3D *shape;
	~Parallelepiped(void);
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

