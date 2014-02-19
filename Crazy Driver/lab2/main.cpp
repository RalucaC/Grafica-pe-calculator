#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Transform3D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Container.h"
#include "Pyramid.h"
#include "Snow.h"
#include "Road.h"
#include "Car.h"
#include <iostream>
#include <time.h>
#include <windows.h>


#define PI 3.14159265358979323846
#define inf 1000000
#define ANGLE_LEFT 4.47079
#define ANGLE_CENTER 4.6876
#define ANGLE_RIGHT 4.87079 

using namespace std;

vector<Parallelepiped> obstacles;
vector<Pyramid> pyramids;
vector<Snow> snow;

int sleeptime = 0;
int score = 0;
int lives = 3;
int timeS = 0;
float dist = 100;
int stopOnIdel = 1;
bool carState = true;
clock_t start, t_elapsed;

Text *scoreBar;
Text *scoreValue;
Text *livesBar;
Text *livesValue;
Text *distanceBar;
Text *distanceValue;
Text *timeBar;
Text *timeValue;
Text *gameover;
Road *road;
Car *car;


//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{
	start = clock();
	DrawingWindow::addVisual2D(Container::bottom);

	Container::bottom->tipTran(true);
	Container::bottom->cadruPoarta(Color(0,0,0));

	 road = new Road();
	car = new Car(Point3D(0,-3,0));
	
	//score, distance, time and lives

	scoreBar = new Text("Score", Point2D(-3, 5.5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);
	scoreValue = new Text(to_string(score), Point2D(-2.3, 5.5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);

	livesBar = new Text("Lives", Point2D(-3, 5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);
	livesValue = new Text(to_string(lives), Point2D(-2.3, 5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);

	distanceBar = new Text("km", Point2D(2.5, 5.5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);
	distanceValue = new Text(to_string(dist), Point2D(1.9, 5.5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);

	timeBar = new Text("s", Point2D(2.5, 5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);
	timeValue = new Text(to_string(timeS), Point2D(2, 5), Color(1,0,0), BITMAP_TIMES_ROMAN_24);

	gameover = new Text("Game over!", Point2D(0,0), Color(1,0,0), BITMAP_TIMES_ROMAN_24);

	DrawingWindow::addText_to_Visual2D(scoreBar, Container::bottom);
	DrawingWindow::addText_to_Visual2D(scoreValue, Container::bottom);
	DrawingWindow::addText_to_Visual2D(livesBar, Container::bottom);
	DrawingWindow::addText_to_Visual2D(livesValue, Container::bottom);
	DrawingWindow::addText_to_Visual2D(distanceBar, Container::bottom);
	DrawingWindow::addText_to_Visual2D(distanceValue, Container::bottom);

	DrawingWindow::addText_to_Visual2D(timeBar, Container::bottom);
	DrawingWindow::addText_to_Visual2D(timeValue, Container::bottom);

	

	

	car->drawingElement();
	road->drawingElement();
}


void moveObstacles(float speed){

	if(speed == 0.5){
		dist -= 0.1;
		score += 5;
	}else{
		dist -= 0.02;
		score += 1;
	}
	string s = to_string(dist);
	s.resize(5);
	distanceValue->text = s;
	scoreValue->text = to_string(score);
	for(unsigned int i = 0; i < obstacles.size(); i++){
		obstacles[i].move(speed);
	}
	for(unsigned int i = 0; i < pyramids.size(); i++){
		pyramids[i].move(speed);
	}

}

void addRandomObstacle(){
	int randomPos, type;


	srand (time(NULL));
	randomPos = rand() % 3;
	type = rand() % 2;
	if(randomPos == 0){
		//adauga obstacol la stanga
		if(type == 0 && obstacles.size() > 0 && obstacles[obstacles.size() - 1].getStartPoint().y < 5.5){
			obstacles.push_back(Parallelepiped(Point3D(-0.5, 7, 0), 0.5,0.5,0.5, Color(0,0,1), false));
			obstacles[obstacles.size() - 1].drawingElement();
			obstacles[obstacles.size() - 1].setAngle(ANGLE_LEFT);
		}else if(type == 1 && pyramids.size() > 0 && pyramids[pyramids.size() - 1].getStartPoint().y < 5.5){
			pyramids.push_back(Pyramid(Point3D(-0.5, 7, 0), 0.3,0.5,0.3, Color(1, 0.647059, 0), false));
			pyramids[pyramids.size() - 1].drawingElement();
			pyramids[pyramids.size() - 1].setAngle(ANGLE_LEFT);
		}
	}
	if(randomPos == 1){
		//adauga obstacol in centru
		if(type == 0 && obstacles.size() > 0 && obstacles[obstacles.size() - 1].getStartPoint().y < 5.5){
			obstacles.push_back(Parallelepiped(Point3D(0, 7, 0),  0.5,0.5,0.5, Color(1,0,0), false));
			obstacles[obstacles.size() - 1].drawingElement();
			obstacles[obstacles.size() - 1].setAngle(ANGLE_CENTER);
		}else  if(type == 1 && pyramids.size() > 0 && pyramids[pyramids.size() - 1].getStartPoint().y < 5.5){
			pyramids.push_back(Pyramid(Point3D(0, 7, 0), 0.5,0.7,0.5, Color( 0.780392, 0.0823529, 0.521569), false));
			pyramids[pyramids.size() - 1].drawingElement();
			pyramids[pyramids.size() - 1].setAngle(ANGLE_CENTER);
		}
	}
	if(randomPos == 2){
		//adauga obstacol la dreapta
		if(type == 0 && obstacles.size() > 0 && obstacles[obstacles.size() - 1].getStartPoint().y < 5.5){
			obstacles.push_back(Parallelepiped(Point3D(0.5, 7, 0),  0.5,0.5,0.5, Color(1,0,0), false));
			obstacles[obstacles.size() - 1].drawingElement();
			obstacles[obstacles.size() - 1].setAngle(ANGLE_RIGHT);
		}else if(type == 1 && pyramids.size() > 0 && pyramids[pyramids.size() - 1].getStartPoint().y < 5.5){
			pyramids.push_back(Pyramid(Point3D(0.5, 7, 0), 0.3,0.5,0.3, Color(1,0,0), false));
			pyramids[pyramids.size() - 1].drawingElement();
			pyramids[pyramids.size() - 1].setAngle(ANGLE_RIGHT);
		}
	}

}

float distance2(Point3D p1, Point3D p2){
	float op1, op2, op3;
	op1 = (p1.x - p2.x)*(p1.x - p2.x);
	op2 = (p1.y - p2.y)*(p1.y - p2.y);
	op3 = (p1.z - p2.z)*(p1.z - p2.z);
	return sqrt(op1 + op2 + op3);
}

int contact(){

	vector<int> toRemoveObs;
	vector<int> toRemovePy;
	float d;
	 
	for(unsigned int i = 0; i < obstacles.size(); i++){
		Point3D p = obstacles[i].getStartPoint();
		d = distance2(p, car->getStartPoint());
		if(d < 0.8){
			lives--;
			livesValue->text = to_string(lives);
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Container::bottom);
				return 0;
			}
			toRemoveObs.push_back(i);
		}
		if(p.y < -7){
			toRemoveObs.push_back(i);
		}
	}
	for(unsigned int i = 0; i < toRemoveObs.size(); i++){
		obstacles[toRemoveObs[i]].removeElement();
		if(toRemoveObs[i] < obstacles.size()){
			obstacles.erase(obstacles.begin() + toRemoveObs[i]);
		}
	}
	for(unsigned int i = 0; i < toRemoveObs.size(); i++){
		addRandomObstacle();
	}

	for(unsigned int i = 0; i < pyramids.size(); i++){
		Point3D p = pyramids[i].getStartPoint();
		d = distance2(p, car->getStartPoint());
		if(d < 0.7){
			lives--;
			livesValue->text = to_string(lives);
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Container::bottom);
				return 0;
			}
			toRemovePy.push_back(i);
		}
		if(p.y < -7){
			toRemovePy.push_back(i);
		}
	}

	for(unsigned int i = 0; i < toRemovePy.size(); i++){
		pyramids[toRemovePy[i]].removeElement();
		if(toRemovePy[i] < pyramids.size()){
			pyramids.erase(pyramids.begin() + toRemovePy[i]);
		}
	}
	for(unsigned int i = 0; i < toRemovePy.size(); i++){
		addRandomObstacle();
	}
	return 1;
}

void moveSnow(){
	for(unsigned int i = 0 ; i < snow.size(); i++){
		snow[i].move();
	}
}
//functia care permite animatia
void DrawingWindow::onIdle()
{
	cout<<obstacles.size()<<" "<<pyramids.size()<<endl ;

	if(obstacles.size() == 0){
		obstacles.push_back(Parallelepiped(Point3D(-0.5, 7, 0), 0.5,0.5,0.5, Color( 0.133333, 0.545098, 0.133333), false));
		obstacles[obstacles.size() - 1].drawingElement();
		obstacles[obstacles.size() - 1].setAngle(ANGLE_LEFT);
	}
	if(pyramids.size() == 0){
		pyramids.push_back(Pyramid(Point3D(0, 7, 0), 0.5,0.7,0.5, Color(0.294118, 0, 0.509804), false));
		pyramids[pyramids.size() - 1].drawingElement();
		pyramids[pyramids.size() - 1].setAngle(ANGLE_CENTER);
	}
	if(stopOnIdel == 1){
		t_elapsed = clock();

		float difference= (((float)t_elapsed)-((float)start));
		int seconds = difference/1000;
		int minutes = seconds / 60;
		seconds = fmod(seconds, 60);
		string min = to_string(minutes);
		string sec = to_string(seconds);
		sec.resize(2);
		string time_el = min + ":";
		time_el = time_el + sec;

		timeValue->text = time_el;
		
		
		if(sleeptime > 100){
			int randPos = rand() % 7 + (-3);
			snow.push_back(Snow(randPos,7));
		}
		
		if(sleeptime%10 == 0){
			moveObstacles(0.3);
			moveSnow();
			stopOnIdel = contact();
		}

		if(sleeptime > 100){
			addRandomObstacle();
			sleeptime = 0;
		}
		sleeptime++;

	}
}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{
}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	switch(key)
	{
		case 27 : exit(0);
		case 'd':{
			car->roateCar(1);
			break;
				 }
		case 'f':{
			car->roateCar(0);
			break;
				 }	
		case 'e':{
			if(car->getAngle()< 2.5 && car->getAngle() > 1){
				moveObstacles(0.5);
				car->moveOZCar(carState);
				cout<<carState;
				if(carState == true){
					carState = false;
				}else{
					carState = true;
				}
			}else{
				car->moveCar();
			}
			break;
				 }
		case 'g' :{
			moveObstacles(0.1);	  
				  }
	}
}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{
}


int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 610, 700, 200, 10, "Crazy Driver");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	
	return 0;

}