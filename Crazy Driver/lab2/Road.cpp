#include "Container.h"
#include "Road.h"
#include "Framework\DrawingWindow.h"
#include "Framework\Transform3D.h"

using namespace std;

Road::Road(void)
:vertices()
,faces()
,contour()
,road()
,roadContourL()
,roadContourR()
,outL()
,outR()
,line1()
,line2()

{
	vertices.push_back(new Point3D(-4,-6,0));
	vertices.push_back(new Point3D(4,-6,0));
	vertices.push_back(new Point3D(0.7,7,0));
	vertices.push_back(new Point3D(-0.7,7,0));
	
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	road = new Object3D(vertices, faces, Color( 0, 0, 0.501961), false);
	
	//margine stanga
	roadContourL = new Polygon2D(Color( 0, 0, 0.501961), true);
	roadContourL->addPoint(Point2D(-4, -6));
	roadContourL->addPoint(Point2D(-0.7, 7));
	roadContourL->addPoint(Point2D(-0.75, 7));
	roadContourL->addPoint(Point2D(-4.05, -6));

	//margine dreapta
	roadContourR = new Polygon2D(Color( 0, 0, 0.501961), true);
	roadContourR->addPoint(Point2D(4, -6));
	roadContourR->addPoint(Point2D(4.05, -6));
	roadContourR->addPoint(Point2D(0.75, 7));
	roadContourR->addPoint(Point2D(0.7, 7));

	//liniile delimitatoare de benzi
	line1 = new Line2D(Point2D(-1.7,-6), Point2D(-0.2, 7), Color( 0, 0, 0.501961));
	line2 = new Line2D(Point2D(1.7,-6), Point2D(0.2, 7), Color( 0, 0, 0.501961));

	outL = new Polygon2D(Color(0,1,0), true);
	outL->addPoint(Point2D(-4.05, -6));
	outL->addPoint(Point2D(-0.75, 7));
	outL->addPoint(Point2D(-4, 7));

}

void Road::drawingElement(){
	DrawingWindow::addObject3D_to_Visual2D(road, Container::bottom);
	DrawingWindow::addObject2D_to_Visual2D(line1, Container::bottom);
	DrawingWindow::addObject2D_to_Visual2D(line2, Container::bottom);
	DrawingWindow::addObject2D_to_Visual2D(roadContourL, Container::bottom);
	DrawingWindow::addObject2D_to_Visual2D(roadContourR, Container::bottom);
}

void Road::removeElement(){}
Road::~Road(void)
{
}
