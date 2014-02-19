#include "Car.h"
#include "Framework\DrawingWindow.h"
#include "Framework\Transform3D.h"

Car::Car(Point3D start)
:angle(PI/2)
,position(1)
,xLen()
,yLen()
,zLen()
,tx(0)
,ty(0)
,scale(1)
,translationVal()
,center()
,pas(0)
,cube1()
,cube2()
,wheel10()
,wheel11()
,wheel20()
,wheel21()
,wheel30()
,wheel31()
,wheel40()
,wheel41()
{
	startPoint = new Point3D(start);
	int latura = 1;
	
	xLen = 0.5;
	yLen = 0.2;
	zLen = 0.7;
	cube1 = new Parallelepiped(start, xLen,yLen,zLen,Color(0,0,1), false);
	cube2 = new Parallelepiped(Point3D(start.x + 0.1, start.y + yLen, start.z + 0.2), xLen/2, yLen/2, zLen/2, Color(0,0,1), false);
	center = new Point3D(xLen/2, yLen/2, zLen/2);
	translationVal = new Point3D(0,0,0);
	wheel10 = new Parallelepiped(Point3D(start.x - 0.1, start.y - 0.1, start.z), 0.1, 0.1, 0.1, Color(0,0,1), false);
	wheel11 = new Parallelepiped(Point3D(start.x - 0.1, start.y - 0.1, start.z), 0.08, 0.08, 0.08, Color(0,0,1), false);

	wheel20 = new Parallelepiped(Point3D(start.x + xLen, start.y - 0.1, start.z), 0.1, 0.1, 0.1, Color(0,0,1), false);
	wheel21 = new Parallelepiped(Point3D(start.x + xLen, start.y - 0.1, start.z), 0.08, 0.08, 0.08, Color(0,0,1), false);

	wheel30 = new Parallelepiped(Point3D(start.x + xLen, start.y - 0.1, start.z + zLen - 0.1), 0.1, 0.1, 0.1, Color(0,0,1), false);
	wheel31 = new Parallelepiped(Point3D(start.x + xLen, start.y - 0.1, start.z + zLen - 0.1), 0.08, 0.08, 0.08, Color(0,0,1), false);

	wheel40 = new Parallelepiped(Point3D(start.x - 0.1, start.y - 0.1, start.z + zLen - 0.1), 0.1, 0.1, 0.1, Color(0,0,1), false);
	wheel41 = new Parallelepiped(Point3D(start.x - 0.1, start.y - 0.1, start.z + zLen - 0.1), 0.08, 0.08, 0.08, Color(0,0,1), false);

}

void Car::drawingElement(){
	cube1->drawingElement();
	cube2->drawingElement();
	wheel10->drawingElement();
	wheel11->drawingElement();
	wheel20->drawingElement();
	wheel21->drawingElement();
	wheel30->drawingElement();
	wheel31->drawingElement();
	wheel40->drawingElement();
	wheel41->drawingElement();
}

void Car::applyTransf(){
	Transform3D::applyTransform(cube1->shape);
	Transform3D::applyTransform(cube2->shape);
	Transform3D::applyTransform(wheel10->shape);
	Transform3D::applyTransform(wheel11->shape);
	Transform3D::applyTransform(wheel20->shape);
	Transform3D::applyTransform(wheel21->shape);
	Transform3D::applyTransform(wheel30->shape);
	Transform3D::applyTransform(wheel31->shape);
	Transform3D::applyTransform(wheel40->shape);
	Transform3D::applyTransform(wheel41->shape);
}

void Car::roateCar(int direction){
	
	if(direction == 1){
		//la stanga
		if(angle + 0.1 > 2*PI){
			angle = angle + 0.1 - 2*PI;
		}else{
			angle += 0.1;
		}
		pas -= 0.1;
	}else{
		//la dreapta
		if(angle - 0.1 < 0){
			angle = angle - 0.1 + 2*PI;
		}else{
			angle -= 0.1;
		}
		pas += 0.1;
	}

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix(-center->x,-center->y,-center->z);
	Transform3D::rotateMatrixOy(pas);
	Transform3D::translateMatrix(center->x,center->y,center->z);
	Transform3D::translateMatrix(translationVal->x, translationVal->y, translationVal->z);
	Transform3D::scaleMatrix(scale, scale, scale);
	applyTransf();
}

void Car::moveOZCar(bool dir){
	if(dir == true){
		Transform3D::translateMatrix(0,0,0.01);
	}	else{
		Transform3D::translateMatrix(0,0,-0.01);
	}
	applyTransf();
}

void Car::moveCar(){

	tx = 0.2*cos(angle);
	ty = 0.2*sin(angle);
		
	Transform3D::translateMatrix(tx,ty,0);

	applyTransf();
	drawingElement();

	translationVal->x += tx;
	translationVal->y += ty;
	startPoint->x = startPoint->x + tx;
	startPoint->y = startPoint->y + ty;
}

float Car::getAngle(){
	return angle;
}

void Car::removeElement(){}
Car::~Car(void)
{
}
