#include "Pyramid.h"
#include "Framework\DrawingWindow.h"
#include "Framework\Transform3D.h"

Pyramid::Pyramid(Point3D start, float xVal, float yVal, float zVal, Color color, bool fill)
:vertices()
,faces()
,contour()
,shape()
,moveVals()
,xLen()
,yLen()
,zLen()
,tx(0)
,ty(0)
,angle(0)

{
	startPoint = new Point3D(start);
	moveVals = new Point3D(0,0,0);
	xLen = xVal;
	yLen = yVal;
	zLen = zVal;

	//varfurile de jos
	vertices.push_back(startPoint);
	vertices.push_back(new Point3D(startPoint->x + xVal, startPoint->y, startPoint->z));
	vertices.push_back(new Point3D(startPoint->x + xVal, startPoint->y, startPoint->z + zVal));
	vertices.push_back(new Point3D(startPoint->x, startPoint->y, startPoint->z + zVal));

	//varful de sus
	vertices.push_back(new Point3D(startPoint->x + xLen/2, startPoint->y + yLen, startPoint->z + zVal/2));

	//fata de jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));

	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	faces.push_back(new Face(contour));

	shape = new Object3D(vertices, faces, color, fill);
}

void Pyramid::drawingElement(){
	DrawingWindow::addObject3D_to_Visual2D(shape, Container::bottom);
	Transform3D::loadIdentityProjectionMatrix();
	Transform3D::parallelProjectionMatrix(0.5,2,1.5);
	Transform3D::applyTransform(shape);
}
void Pyramid::removeElement(){
	DrawingWindow::removeObject3D_from_Visual2D(shape, Container::bottom);	
}

void Pyramid::move(float speed){
	tx = speed*cos(angle);
	ty = speed*sin(angle);
	float matrixSaved[4][4];
	
	for(unsigned int i = 0; i < 4; i++){
		for(unsigned int j = 0; j < 4; j++){
			matrixSaved[i][j] = Transform3D::ModelMatrix[i][j];
		}
	}
	moveVals->x += tx;
	moveVals->y += ty;

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix(moveVals->x, moveVals->y, moveVals->z);
	Transform3D::applyTransform(shape);
	Transform3D::setIdentityModelMatrix(matrixSaved);

	startPoint->x += tx; 
	startPoint->y += ty;

}
void Pyramid::setAngle(float val){
	angle = val;
}
Pyramid::~Pyramid(void)
{
}
