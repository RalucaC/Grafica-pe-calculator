#include "Container.h"
#include "Parallelepiped.h"

#pragma once
#define PI 3.14159265358979323846

class Car : public Container
{
public:
	Car(Point3D);
	void drawingElement();
	void removeElement();
	void moveCar();
	void moveOZCar(bool);
	void roateCar(int);
	float getAngle();
	~Car(void);
private:
	float angle;
	int position;
	float xLen;
	float yLen;
	float zLen;
	float tx;
	float ty;
	float pas;
	float scale;
	Point3D *translationVal;
	Point3D *center;
	Parallelepiped *cube1;
	Parallelepiped *cube2;
	Parallelepiped *wheel10;
	Parallelepiped *wheel11;
	Parallelepiped *wheel20;
	Parallelepiped *wheel21;
	Parallelepiped *wheel30;
	Parallelepiped *wheel31;
	Parallelepiped *wheel40;
	Parallelepiped *wheel41;
	void applyTransf();
};

