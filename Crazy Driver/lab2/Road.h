#include "Framework\Polygon2D.h"
#include "Framework\Object3D.h"
#include "Framework\Line2D.h"
#include "Container.h"
#pragma once
using namespace std;

class Road : public Container
{
public:
	Road(void);
	void drawingElement();
	void removeElement();
	~Road(void);
private:
	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;
	Object3D *road;
	Polygon2D *roadContourL;
	Polygon2D *roadContourR;
	Polygon2D *outL;
	Polygon2D *outR;
	Line2D *line1;
	Line2D *line2;
};

